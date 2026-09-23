# ManaScriptRuntimeForUnreal

**ManaScriptRuntimeForUnreal** is an Unreal Engine plugin that integrates **Mana**, an actor-oriented scripting language for games, into Unreal’s Editor and Runtime workflows.

This repository focuses on an Unreal-friendly pipeline:

- **Compile Mana scripts in the Unreal Editor**
- Store the **compiled Mana binary** inside a **Unreal asset**
- **Load and execute** that asset at runtime to drive gameplay logic and control UE Actors

## What is Mana?

**Mana** is an *actor-oriented scripting language for games* designed around the actor model to implement character/game actions, and it provides:
- A CLI workflow to compile source and/or run compiled binaries (`-o` outputs a compiled binary, `--execute` runs a compiled binary)
- A VM that can be embedded into native applications, including APIs for ticking the VM and binding native functions/methods into scripts

Mana repository: https://github.com/shun126/Mana

## High-level Design

### Runtime (Game)
- **`UManaProgramAsset`**
  - Stores **compiled Mana binary data** (`TArray<uint8>`) as a cookable Unreal asset.
  - Tracks the compiled binary size/hash, format version, compiler version, source hash, and compile diagnostics.
- **`AManaVirtualMachine`** (World Runner)
  - Placed in a Level to define “which Mana program runs in this map”.
  - Loads a `UManaProgramAsset`, creates a `UManaRuntimeVM`, and ticks it.
  - Runs only on Authority and refuses to start if multiple VM actors are present.
  - Maintains a registry that binds Mana actors to UE actors via `UManaBindableComponent`.
- **`UManaRuntimeVM`**
  - Owns the underlying `mana::VM`, loads the compiled binary, and registers runtime bindings.
  - Resolves `mana::Actor` handles to UE `AActor` instances for gameplay commands.

### Editor
- **`UManaProgramAssetImportFactory`**
  - Imports `.mn` Mana source files into `UManaProgramAsset`.
  - Stores the source path in `AssetImportData` for reimport.
- **Compiler integration**
  - Compiles in process through the `ManaScriptCompiler` module. Nothing is written to disk: `mana::Compile()` returns the bytecode as a value.
  - Diagnostics keep their filename and line number, so the message log links straight to the offending line.
  - Stores diagnostics and compiler metadata on the asset; failed compiles clear the compiled binary.
  - Records the Mana bytecode version on the asset. On load, a mismatch is rebuilt from source in the editor, and reported as an error in cooked builds.
- **Asset actions**
  - Context menu actions include `Compile`, `Validate`, and `Open Source`.

## Binding UE Actors to Mana Actors

Runtime bindings are driven by **`UManaBindableComponent`**:

- Add `UManaBindableComponent` to any UE `AActor` you want to control from Mana.
- Set the component’s `ManaActorName` to a Mana actor defined in the compiled program asset.
- `AManaVirtualMachine` discovers bindable components, requests the matching Mana actor handle, and tracks the binding.
- If a Mana actor isn’t available yet, the binding is queued and retried.

The component also exposes `RequestTo(...)`, which uses `AManaVirtualMachine` to request a Mana action on another bound actor with a priority and optional sender name.

## Runtime API exposed to Mana scripts

The current native bindings are registered in `FManaRuntimeBindings`:

- `set_location(handle, x, y, z, sweep, teleport)`
- `play_montage(handle, montage_name, play_rate, section_name)`
- `move_to_location(handle, x, y, z)` (repeats until the actor is within a threshold)
- `move_to_actor(handle, target_handle)`
- `look_at_location(handle, x, y, z)`
- `look_at_actor(handle, target_handle)`
- `set_anim_param(handle, param_name, value)`

These bindings return integer success values to the script and operate on the bound UE actors immediately.

## Networking Assumption (Server-authoritative)

This project is designed with a common multiplayer constraint in mind:

- The Mana VM runs **only on the server (Authority)**.
- All UE Actor mutations caused by scripts occur on the server and replicate normally through Unreal networking.

## Status

This repository is under active development. The current implementation includes:

- `UManaProgramAsset` for compiled binaries + metadata
- Editor import/compile pipeline for `.mn` sources
- Runtime VM runner (`AManaVirtualMachine`) with bindable component discovery
- Built-in UE bindings for transforms, movement, look-at, and animation parameters

## Contributing

Issues and pull requests are welcome. When proposing changes, please include:
- The problem being solved
- Runtime/Editor impact
- Cooking/packaging considerations (asset references, determinism)
- Networking implications (Authority gating, replication)

## License

This repository’s license is defined in the `LICENSE` file in this repo.
Mana itself is licensed separately; please refer to the Mana repository for its license and details.
