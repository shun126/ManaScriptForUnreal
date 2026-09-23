/**
 * @author		Shun Moriya
 * @copyright	2026- Shun Moriya
 * All Rights Reserved.
 */

#pragma once

#include "CoreMinimal.h"
#include "Containers/ArrayView.h"
#include "ManaProgramAsset.generated.h"

namespace mana
{
	class ProgramImage;
}

UCLASS(BlueprintType)
class MANASCRIPTRUNTIME_API UManaProgramAsset : public UObject
{
	GENERATED_BODY()

public:
	static constexpr uint32 CurrentFormatVersion = 2;

#if WITH_EDITOR
	DECLARE_MULTICAST_DELEGATE_OneParam(FOnCompiledBinaryUpdated, UManaProgramAsset*);
	static FOnCompiledBinaryUpdated& OnCompiledBinaryUpdated();

	/**
	 * バイトコードの版数が食い違ったアセットを、原文から作り直す要求。
	 *
	 * コンパイラはエディタ側のモジュールにあるので、ここでは要求だけを出します。
	 * 束縛は ManaScriptEditor が行います。
	 */
	DECLARE_DELEGATE_OneParam(FOnRecompileRequest, UManaProgramAsset&);
	static FOnRecompileRequest& OnRecompileRequest();
#endif

	virtual void PostLoad() override;

	UPROPERTY(VisibleAnywhere, Category = "Mana|Compiled")
	TArray<uint8> CompiledBinary;

	UPROPERTY(VisibleAnywhere, Category = "Mana|Compiled")
	int32 CompiledBinarySize = 0;

	UPROPERTY(VisibleAnywhere, Category = "Mana|Compiled")
	TArray<uint8> CompiledBinaryHash;

	/** このアセットのレイアウトの版数。Mana のバイトコードの版数とは別物です */
	UPROPERTY(VisibleAnywhere, Category = "Mana")
	uint32 FormatVersion = CurrentFormatVersion;

	/**
	 * CompiledBinary を生成した Mana のバイトコード版数。
	 *
	 * 仮想マシンはメジャー・マイナーの完全一致を要求し、違えば読み込みに失敗します。
	 * Mana のコンパイラを直すたびに上がるため、ここに記録して食い違いを検知します。
	 */
	UPROPERTY(VisibleAnywhere, Category = "Mana")
	uint8 BytecodeMajorVersion = 0;

	UPROPERTY(VisibleAnywhere, Category = "Mana")
	uint8 BytecodeMinorVersion = 0;

	UPROPERTY(VisibleAnywhere, Category = "Mana")
	FString ManaCompilerVersion;

	UPROPERTY(VisibleAnywhere, Category = "Mana")
	FString SourceHash;

	UPROPERTY(EditAnywhere, Category = "Mana")
	TArray<FString> Diagnostics;

#if WITH_EDITORONLY_DATA
	UPROPERTY(VisibleAnywhere, Instanced, Category = "Mana|Import")
	TObjectPtr<class UAssetImportData> AssetImportData;

#endif

	bool IsCompiled() const;

	/** 記録されているバイトコード版数が、今の仮想マシンと一致すれば真 */
	bool IsBytecodeVersionCurrent() const;

	/** 今の仮想マシンが要求するバイトコード版数 */
	static void GetExpectedBytecodeVersion(uint8& OutMajorVersion, uint8& OutMinorVersion);

	bool TryGetCompiledBinary(TConstArrayView<uint8>& OutBinary, FString& OutError) const;

	void UpdateCompiledBinary(const TArray<uint8>& InBinary);

	void ResetCompiledBinary();

#if WITH_EDITOR
	bool GetActorNames(TArray<FString>& OutActorNames, FString& OutError) const;

	bool HasActor(const FString& ActorFullName, FString& OutError) const;

	bool GetActorActionNames(const FString& ActorFullName, TArray<FString>& OutActionNames, FString& OutError) const;

	bool HasActorAction(const FString& ActorFullName, const FString& ActionName, FString& OutError) const;
#endif

private:
	static void BuildBinaryHash(const TArray<uint8>& InBinary, TArray<uint8>& OutHash);

	bool ValidateCompiledBinary(FString& OutError) const;

#if WITH_EDITOR
	// プログラムイメージの展開は、上のアクター名照会 (WITH_EDITOR) だけが使います。
	// 実行時はバイトコードをそのまま仮想マシンへ渡すため、ここは要りません
	bool EnsureProgramImageLoaded(FString& OutError) const;

	mutable TSharedPtr<mana::ProgramImage> ProgramImageCache;
#endif
};
