/**
 * @author		Shun Moriya
 * @copyright	2026- Shun Moriya
 * All Rights Reserved.
 */

#pragma once

#include "CoreMinimal.h"

/**
 * Mana の出力を Unreal Engine のログへ橋渡しします。
 *
 * Mana は print()、実行トレース、エラー、アサートの全てを mana::Trace へ流します。
 * 既定の出力先は標準出力なので、パッケージ化したゲームでは誰にも届きません。
 * ここで UE_LOG へ振り替えます。
 *
 * 不変条件が壊れた事の通知 (mana::FaultHandler) も併せて受け取ります。
 * 通知は巻き戻しが始まる前に行われるため、Mana 自体を追う際は
 * OnFault() にブレークポイントを置くと原因のスタックが残っています。
 */
class FManaDiagnosticBridge
{
public:
	/**
	 * 出力先を Unreal Engine のログへ差し替えます。
	 *
	 * Mana 側の契約により、利用を開始する前に一度だけ呼びます。
	 * 二重に呼んでも安全です。
	 */
	static void Install();

	/**
	 * 出力先を既定へ戻し、溜まっている分を吐き出します。
	 */
	static void Uninstall();
};
