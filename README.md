# Action Sword Combat

An Unreal Engine 5 C++ project implementing a lock-on targeting system, combo-based melee combat, and a modular component architecture.

## Features

### Combat System
- **Melee combo attacks** with animation notify states to chain inputs
- **Weapon trace component** that activates hitboxes during attack windows
- **Lock-on targeting** (`LockonComponent`) to orbit-strafe an enemy
- **Fighter / Enemy / MainPlayer interfaces** for clean cross-actor communication

## Acknowledgments
Built while following the [GameDevTV](https://github.com/GameDevTV) Unreal Engine course as a learning and portfolio project.
README written with the assistance of Claude (AI) to accurately reflect the implemented features.
(If you're wondering why the uproject name is JamSepticEyeee. Started it for a game jam, bailed on the jam, the name stuck)

## License

The original C++ source code in this repository is released under the **MIT License** — see [LICENSE](LICENSE) for details.

Engine template code (files bearing `// Copyright Epic Games, Inc. All Rights Reserved.`) and all binary content assets (`.uasset`, `.umap`, FBX meshes) are the property of Epic Games, Inc. and are subject to the [Unreal Engine EULA](https://www.unrealengine.com/eula/unreal). You must hold a valid Unreal Engine license to use them.

