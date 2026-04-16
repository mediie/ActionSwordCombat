# Action Sword Combat

An Unreal Engine 5 C++ project implementing a lock-on targeting system, combo-based melee combat, and a modular component architecture.

Built while following the [GameDevTV](https://github.com/GameDevTV) Unreal Engine course as a learning and portfolio project.

(if you're wondering why the uproject name is JamSepticEyeee, its cause i wanted to participate in the game jam but cancelled, and I already started playing around lol)

## Features

### Combat System
- **Melee combo attacks** with animation notify states to chain inputs
- **Block / parry component** for defensive play
- **Weapon trace component** that activates hitboxes during attack windows
- **Lock-on targeting** (`LockonComponent`) to orbit-strafe an enemy
- **Fighter / Enemy / MainPlayer interfaces** for clean cross-actor communication

## License

The original C++ source code in this repository is released under the **MIT License** — see [LICENSE](LICENSE) for details.

Engine template code (files bearing `// Copyright Epic Games, Inc. All Rights Reserved.`) and all binary content assets (`.uasset`, `.umap`, FBX meshes) are the property of Epic Games, Inc. and are subject to the [Unreal Engine EULA](https://www.unrealengine.com/eula/unreal). You must hold a valid Unreal Engine license to use them.
