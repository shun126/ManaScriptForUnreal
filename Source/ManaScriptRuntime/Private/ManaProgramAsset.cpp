/**
 * @author		Shun Moriya
 * @copyright	2026- Shun Moriya
 * All Rights Reserved.
 */

#include "ManaProgramAsset.h"
#include "ManaScriptRuntime.h"
#include "Mana/runner/ProgramImage.h"
#include "Mana/runner/common/FileFormat.h"
#include "Containers/StringConv.h"
#include "Misc/SecureHash.h"

#include <string_view>

bool UManaProgramAsset::IsCompiled() const
{
	FString Error;
	return ValidateCompiledBinary(Error);
}

void UManaProgramAsset::GetExpectedBytecodeVersion(uint8& OutMajorVersion, uint8& OutMinorVersion)
{
	OutMajorVersion = mana::MajorVersion;
	OutMinorVersion = mana::MinorVersion;
}

bool UManaProgramAsset::IsBytecodeVersionCurrent() const
{
	uint8 ExpectedMajor = 0;
	uint8 ExpectedMinor = 0;
	GetExpectedBytecodeVersion(ExpectedMajor, ExpectedMinor);
	return BytecodeMajorVersion == ExpectedMajor && BytecodeMinorVersion == ExpectedMinor;
}

void UManaProgramAsset::PostLoad()
{
	Super::PostLoad();

	// バイトコードを持っていないアセットは、まだ何も壊れていない
	if (CompiledBinary.Num() == 0)
	{
		return;
	}

	if (IsBytecodeVersionCurrent())
	{
		return;
	}

	uint8 ExpectedMajor = 0;
	uint8 ExpectedMinor = 0;
	GetExpectedBytecodeVersion(ExpectedMajor, ExpectedMinor);

#if WITH_EDITOR
	// エディタでは原文から作り直せる。Mana を直した直後はここを通ります
	UE_LOG(LogManaScriptRuntime, Warning,
		TEXT("Mana bytecode version mismatch on %s: asset is %d.%d, runtime expects %d.%d. Recompiling from source."),
		*GetName(), BytecodeMajorVersion, BytecodeMinorVersion, ExpectedMajor, ExpectedMinor);

	if (OnRecompileRequest().IsBound())
	{
		OnRecompileRequest().Execute(*this);
	}

	if (!IsBytecodeVersionCurrent())
	{
		UE_LOG(LogManaScriptRuntime, Error,
			TEXT("Mana bytecode for %s could not be rebuilt. The compiled binary has been discarded."),
			*GetName());
		ResetCompiledBinary();
	}
#else
	// クック済みでは作り直せない。黙って動かすと仮想マシンが例外を投げるので、
	// ここで捨てて理由を明示する
	UE_LOG(LogManaScriptRuntime, Error,
		TEXT("Mana bytecode version mismatch on %s: asset is %d.%d, runtime expects %d.%d. ")
		TEXT("The asset must be recooked with a matching Mana revision."),
		*GetName(), BytecodeMajorVersion, BytecodeMinorVersion, ExpectedMajor, ExpectedMinor);
	ResetCompiledBinary();
#endif
}

bool UManaProgramAsset::TryGetCompiledBinary(TConstArrayView<uint8>& OutBinary, FString& OutError) const
{
	if (!ValidateCompiledBinary(OutError))
	{
		OutBinary = TConstArrayView<uint8>();
		return false;
	}

	OutBinary = TConstArrayView<uint8>(CompiledBinary);
	return true;
}

void UManaProgramAsset::UpdateCompiledBinary(const TArray<uint8>& InBinary)
{
	CompiledBinary = InBinary;
	CompiledBinarySize = CompiledBinary.Num();
	BuildBinaryHash(CompiledBinary, CompiledBinaryHash);
#if WITH_EDITOR
	ProgramImageCache.Reset();
	OnCompiledBinaryUpdated().Broadcast(this);
#endif
}

void UManaProgramAsset::ResetCompiledBinary()
{
	CompiledBinary.Reset();
	CompiledBinarySize = 0;
	CompiledBinaryHash.Reset();
#if WITH_EDITOR
	ProgramImageCache.Reset();
	OnCompiledBinaryUpdated().Broadcast(this);
#endif
}

#if WITH_EDITOR
UManaProgramAsset::FOnCompiledBinaryUpdated& UManaProgramAsset::OnCompiledBinaryUpdated()
{
	static FOnCompiledBinaryUpdated Delegate;
	return Delegate;
}

UManaProgramAsset::FOnRecompileRequest& UManaProgramAsset::OnRecompileRequest()
{
	static FOnRecompileRequest Delegate;
	return Delegate;
}
#endif

#if WITH_EDITOR

bool UManaProgramAsset::GetActorNames(TArray<FString>& OutActorNames, FString& OutError) const
{
	OutActorNames.Reset();
	if (!EnsureProgramImageLoaded(OutError))
	{
		return false;
	}

	const std::vector<std::string_view> ActorNames = ProgramImageCache->GetActorNames();
	OutActorNames.Reserve(static_cast<int32>(ActorNames.size()));
	for (const std::string_view Name : ActorNames)
	{
		const FUTF8ToTCHAR Converter(Name.data(), static_cast<int32>(Name.size()));
		OutActorNames.Emplace(Converter.Length(), Converter.Get());
	}

	OutError = TEXT("");
	return true;
}

bool UManaProgramAsset::HasActor(const FString& ActorFullName, FString& OutError) const
{
	if (!EnsureProgramImageLoaded(OutError))
	{
		return false;
	}

	const FTCHARToUTF8 ActorNameUtf8(*ActorFullName);
	const std::string_view ActorName(ActorNameUtf8.Get(), static_cast<size_t>(ActorNameUtf8.Length()));
	OutError = TEXT("");
	return ProgramImageCache->HasActor(ActorName);
}

bool UManaProgramAsset::GetActorActionNames(const FString& ActorFullName, TArray<FString>& OutActionNames, FString& OutError) const
{
	OutActionNames.Reset();
	if (!EnsureProgramImageLoaded(OutError))
	{
		return false;
	}

	const FTCHARToUTF8 ActorNameUtf8(*ActorFullName);
	const std::string_view ActorName(ActorNameUtf8.Get(), static_cast<size_t>(ActorNameUtf8.Length()));
	const std::vector<std::string_view> ActionNames = ProgramImageCache->GetActorActionNames(ActorName);
	OutActionNames.Reserve(static_cast<int32>(ActionNames.size()));
	for (const std::string_view Name : ActionNames)
	{
		const FUTF8ToTCHAR Converter(Name.data(), static_cast<int32>(Name.size()));
		OutActionNames.Emplace(Converter.Length(), Converter.Get());
	}

	OutError = TEXT("");
	return true;
}

bool UManaProgramAsset::HasActorAction(const FString& ActorFullName, const FString& ActionName, FString& OutError) const
{
	if (!EnsureProgramImageLoaded(OutError))
	{
		return false;
	}

	const FTCHARToUTF8 ActorNameUtf8(*ActorFullName);
	const FTCHARToUTF8 ActionNameUtf8(*ActionName);
	const std::string_view ActorNameView(ActorNameUtf8.Get(), static_cast<size_t>(ActorNameUtf8.Length()));
	const std::string_view ActionNameView(ActionNameUtf8.Get(), static_cast<size_t>(ActionNameUtf8.Length()));
	OutError = TEXT("");
	return ProgramImageCache->HasActorAction(ActorNameView, ActionNameView);
}

#endif

void UManaProgramAsset::BuildBinaryHash(const TArray<uint8>& InBinary, TArray<uint8>& OutHash)
{
	OutHash.Reset();
	if (InBinary.Num() == 0)
	{
		return;
	}

	constexpr int32 Sha1DigestSize = 20;
	uint8 HashBytes[Sha1DigestSize];
	FSHA1::HashBuffer(InBinary.GetData(), InBinary.Num(), HashBytes);
	OutHash.SetNumUninitialized(Sha1DigestSize);
	FMemory::Memcpy(OutHash.GetData(), HashBytes, Sha1DigestSize);
}

bool UManaProgramAsset::ValidateCompiledBinary(FString& OutError) const
{
	if (FormatVersion != CurrentFormatVersion)
	{
		OutError = TEXT("Format version mismatch.");
		return false;
	}

	// 仮想マシンへ渡す前にここで止める。渡してしまうと例外になります
	if (!IsBytecodeVersionCurrent())
	{
		uint8 ExpectedMajor = 0;
		uint8 ExpectedMinor = 0;
		GetExpectedBytecodeVersion(ExpectedMajor, ExpectedMinor);
		OutError = FString::Printf(
			TEXT("Mana bytecode version mismatch: asset is %d.%d, runtime expects %d.%d."),
			BytecodeMajorVersion, BytecodeMinorVersion, ExpectedMajor, ExpectedMinor);
		return false;
	}

	if (CompiledBinary.Num() == 0)
	{
		OutError = TEXT("Compiled binary is empty.");
		return false;
	}

	if (CompiledBinarySize != CompiledBinary.Num())
	{
		OutError = TEXT("Compiled binary size metadata mismatch.");
		return false;
	}

	constexpr int32 Sha1DigestSize = 20;
	if (CompiledBinaryHash.Num() != Sha1DigestSize)
	{
		OutError = TEXT("Compiled binary hash is missing.");
		return false;
	}

	uint8 HashBytes[Sha1DigestSize];
	FSHA1::HashBuffer(CompiledBinary.GetData(), CompiledBinary.Num(), HashBytes);
	if (FMemory::Memcmp(HashBytes, CompiledBinaryHash.GetData(), Sha1DigestSize) != 0)
	{
		OutError = TEXT("Compiled binary hash mismatch.");
		return false;
	}

	OutError = TEXT("");
	return true;
}

#if WITH_EDITOR

bool UManaProgramAsset::EnsureProgramImageLoaded(FString& OutError) const
{
	if (ProgramImageCache && ProgramImageCache->IsLoaded())
	{
		OutError = TEXT("");
		return true;
	}

	TConstArrayView<uint8> BinaryView;
	if (!TryGetCompiledBinary(BinaryView, OutError))
	{
		return false;
	}

	const size_t BinarySize = static_cast<size_t>(BinaryView.Num());
	if (BinarySize == 0)
	{
		OutError = TEXT("Compiled binary is empty.");
		return false;
	}

	auto ProgramBuffer = std::shared_ptr<uint8_t[]>(new uint8_t[BinarySize], std::default_delete<uint8_t[]>());
	FMemory::Memcpy(ProgramBuffer.get(), BinaryView.GetData(), BinarySize);
	std::shared_ptr<const void> Program(ProgramBuffer, ProgramBuffer.get());

	auto NewImage = MakeShared<mana::ProgramImage>();
	if (!NewImage->LoadProgram(Program, BinarySize))
	{
		OutError = UTF8_TO_TCHAR(NewImage->GetLastError().c_str());
		return false;
	}

	ProgramImageCache = NewImage;
	OutError = TEXT("");
	return true;
}

#endif
