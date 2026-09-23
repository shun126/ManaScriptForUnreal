# ManaScriptRuntimeForUnreal

**ManaScriptRuntimeForUnreal** は、ゲーム向けのアクター指向スクリプト言語 **Mana** を Unreal Engine のエディタおよびランタイムに統合するプラグインです。

このリポジトリは Unreal に馴染むワークフローに注力しています:

- **Unreal Editor で Mana スクリプトをコンパイル**
- **コンパイル済み Mana バイナリ** を **Unreal アセット** に格納
- ランタイムでそのアセットを **読み込み・実行** し、ゲームプレイロジックや UE のアクター制御に利用

## Mana とは？

**Mana** はゲーム向けの *アクター指向スクリプト言語* で、アクターモデルに基づくキャラクター/ゲームの挙動実装を目的としています。提供機能は以下の通りです:

- CLI でのコンパイル/実行（`-o` でバイナリ出力、`--execute` でバイナリ実行）
- VM をネイティブアプリに埋め込むための API（VM の tick、ネイティブ関数/メソッドのバインド）

Mana リポジトリ: https://github.com/shun126/Mana

## ハイレベル設計

### Runtime（ゲーム）
- **`UManaProgramAsset`**
  - **コンパイル済み Mana バイナリ**（`TArray<uint8>`）を cook 可能な Unreal アセットとして保持。
  - コンパイル済みバイナリのサイズ/ハッシュ、フォーマットバージョン、コンパイラバージョン、ソースハッシュ、診断結果を保持。
- **`AManaVirtualMachine`**（World Runner）
  - レベルに配置して「このマップでどの Mana プログラムを動かすか」を定義。
  - `UManaProgramAsset` を読み込み、`UManaRuntimeVM` を生成して tick。
  - **Authority のみで実行**し、複数の VM Actor が存在する場合は起動しない。
  - `UManaBindableComponent` を介して Mana アクターと UE アクターをバインドするレジストリを管理。
- **`UManaRuntimeVM`**
  - `mana::VM` を所有し、コンパイル済みバイナリのロードとランタイムバインディング登録を行う。
  - `mana::Actor` ハンドルを UE `AActor` に解決してゲームプレイコマンドを実行。

### Editor
- **`UManaProgramAssetImportFactory`**
  - `.mn` の Mana ソースファイルを `UManaProgramAsset` としてインポート。
  - `AssetImportData` にソースパスを保存して再インポートに対応。
- **コンパイラ統合**
  - `ManaScriptCompiler` モジュールでプロセス内コンパイル。`mana::Compile()` がバイトコードを値で返すため、ファイルは一切書きません。
  - 診断はファイル名と行番号を保ったまま渡るので、メッセージログから該当行を直接開けます。
  - 診断結果とコンパイラメタ情報をアセットに保存し、失敗時はバイナリをクリア。
  - Mana のバイトコード版数をアセットに記録。読み込み時に食い違っていれば、エディタでは原文から作り直し、クック済みではエラーとして報告。
- **アセットアクション**
  - コンテキストメニューに `Compile` / `Validate` / `Open Source` を提供。

## UE アクターのバインド

ランタイムのバインドは **`UManaBindableComponent`** を中心に行います:

- Mana から制御したい UE `AActor` に `UManaBindableComponent` を追加。
- `ManaActorName` を、コンパイル済み Program Asset に定義される Mana アクター名に設定。
- `AManaVirtualMachine` がバインド対象を検出し、対応する Mana アクターハンドルと紐付け。
- Mana アクターがまだ存在しない場合は保留して再試行。

また `RequestTo(...)` を使うことで、別のバインド済みアクターに対して優先度付きのアクション要求を送れます。

## Mana スクリプトに公開されるランタイム API

`FManaRuntimeBindings` で登録されているネイティブ API は以下の通りです:

- `set_location(handle, x, y, z, sweep, teleport)`
- `play_montage(handle, montage_name, play_rate, section_name)`
- `move_to_location(handle, x, y, z)`（到達するまで繰り返し）
- `move_to_actor(handle, target_handle)`
- `look_at_location(handle, x, y, z)`
- `look_at_actor(handle, target_handle)`
- `set_anim_param(handle, param_name, value)`

これらは整数の成功値を返し、バインド済み UE アクターに即時反映されます。

## ネットワーク前提（サーバー権限）

本プロジェクトは一般的なマルチプレイヤー制約を想定しています:

- Mana VM は **サーバー（Authority）でのみ実行**。
- スクリプトによる UE Actor 変更はサーバーで行われ、Unreal のネットワークで複製。

## ステータス

本リポジトリは開発中です。現時点で実装されている機能は以下の通りです:

- コンパイル済みバイナリ + メタデータを持つ `UManaProgramAsset`
- `.mn` ソース向けのエディタのインポート/コンパイルパイプライン
- バインド対象の発見を備えた Runtime VM ランナー（`AManaVirtualMachine`）
- Transform、移動、視線、アニメーションパラメータ向けの UE バインディング

## コントリビュート

Issue や Pull Request は歓迎します。提案時には以下を含めてください:
- 解決したい問題
- Runtime / Editor への影響
- Cooking/Packaging の考慮（アセット参照、決定性）
- ネットワークへの影響（Authority 制御、レプリケーション）

## ライセンス

本リポジトリのライセンスは `LICENSE` に記載されています。
Mana 本体は別ライセンスです。詳細は Mana リポジトリを参照してください。
