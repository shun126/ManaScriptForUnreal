/**
 * @author		Shun Moriya
 * @copyright	2026- Shun Moriya
 * All Rights Reserved.
 */

#include "ManaDiagnosticBridge.h"

#include "ManaScriptRuntime.h"
#include "Mana/runner/common/Fault.h"
#include "Mana/runner/common/String.h"

#include <string>

namespace
{
	/**
	 * 改行が来るまで文字を溜める緩衝地帯。
	 *
	 * mana::Trace のハンドラは行単位で呼ばれるとは限りません。UE_LOG は
	 * 1回の呼び出しが1行になるので、改行まで溜めてから流します。
	 */
	class FLineBuffer final
	{
	public:
		void Append(const mana::TraceLevel Level, const char* Message, const std::size_t Length)
		{
			if (Message == nullptr || Length == 0)
			{
				return;
			}

			FScopeLock Lock(&CriticalSection);

			// 重大度が変わったら、溜まっている分を先に吐き出す。
			// そうしないと直前の行の続きが違う重大度で出てしまう
			if (!Pending.empty() && Level != PendingLevel)
			{
				FlushLocked();
			}
			PendingLevel = Level;
			Pending.append(Message, Length);

			for (;;)
			{
				const std::size_t Break = Pending.find('\n');
				if (Break == std::string::npos)
				{
					break;
				}
				EmitLocked(Level, Pending.substr(0, Break));
				Pending.erase(0, Break + 1);
			}
		}

		void Flush()
		{
			FScopeLock Lock(&CriticalSection);
			FlushLocked();
		}

	private:
		void FlushLocked()
		{
			if (!Pending.empty())
			{
				EmitLocked(PendingLevel, Pending);
				Pending.clear();
			}
		}

		static void EmitLocked(const mana::TraceLevel Level, const std::string& Line)
		{
			// 末尾の復帰を落とす。Windows で書かれたスクリプトの print が CRLF を流す
			std::string Trimmed = Line;
			while (!Trimmed.empty() && (Trimmed.back() == '\r' || Trimmed.back() == '\n'))
			{
				Trimmed.pop_back();
			}
			if (Trimmed.empty())
			{
				return;
			}

			const FUTF8ToTCHAR Converter(Trimmed.c_str(), static_cast<int32>(Trimmed.size()));
			const FString Text(Converter.Length(), Converter.Get());

			switch (Level)
			{
			case mana::TraceLevel::Error:
				UE_LOG(LogManaScriptRuntime, Error, TEXT("%s"), *Text);
				break;
			case mana::TraceLevel::Warning:
				UE_LOG(LogManaScriptRuntime, Warning, TEXT("%s"), *Text);
				break;
			case mana::TraceLevel::Info:
			default:
				// print() と実行トレースはここへ来る
				UE_LOG(LogManaScriptRuntime, Log, TEXT("%s"), *Text);
				break;
			}
		}

		FCriticalSection CriticalSection;
		std::string Pending;
		mana::TraceLevel PendingLevel = mana::TraceLevel::Info;
	};

	FLineBuffer& GetLineBuffer()
	{
		static FLineBuffer Buffer;
		return Buffer;
	}

	bool bInstalled = false;

	/**
	 * mana::TraceHandler の実体。
	 *
	 * Mana 側の契約により、この関数は例外を送出してはいけません。
	 */
	void OnTrace(void* /*UserData*/, const mana::TraceLevel Level, const char* Message, const std::size_t Length)
	{
		// UE_LOG も FString も投げ得るので、境界で止める。
		// ここで投げ返すと Mana 側の巻き戻しが壊れます
		try
		{
			GetLineBuffer().Append(Level, Message, Length);
		}
		catch (...)
		{
		}
	}

	/**
	 * mana::FaultHandler の実体。
	 *
	 * 不変条件が壊れた事の通知です。巻き戻しが始まる前に呼ばれるので、
	 * Mana 自体を追う際はここへブレークポイントを置いて下さい。
	 * 戻ると mana::FatalError が送出されます。
	 */
	void OnFault(void* /*UserData*/, const char* File, const int Line, const char* Message)
	{
		try
		{
			// 本文は mana::Trace 経由で既に出ているので、位置だけを補う
			GetLineBuffer().Flush();
			UE_LOG(LogManaScriptRuntime, Error,
				TEXT("Mana internal fault at %s(%d): %s"),
				UTF8_TO_TCHAR(File != nullptr ? File : "?"),
				Line,
				UTF8_TO_TCHAR(Message != nullptr ? Message : ""));
		}
		catch (...)
		{
		}
	}
}

void FManaDiagnosticBridge::Install()
{
	if (bInstalled)
	{
		return;
	}

	mana::SetTraceHandler(&OnTrace, nullptr);
	mana::SetFaultHandler(&OnFault, nullptr);
	bInstalled = true;
}

void FManaDiagnosticBridge::Uninstall()
{
	if (!bInstalled)
	{
		return;
	}

	// 改行で終わっていない出力が残っている事がある
	GetLineBuffer().Flush();

	mana::SetTraceHandler(nullptr, nullptr);
	mana::SetFaultHandler(nullptr, nullptr);
	bInstalled = false;
}
