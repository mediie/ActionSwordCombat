# Action Sword Combat

An Unreal Engine 5 C++ project implementing a modular action-combat system with melee combos, lock-on targeting, AI enemies, and multiple gameplay variants.

Built while following the [GameDevTV](https://github.com/GameDevTV) Unreal Engine course as a learning and portfolio project.

## Features

### Combat System
- **Melee combo attacks** with animation notify states to chain inputs
- **Charged attacks** with a dedicated animation notify
- **Block / parry component** for defensive play
- **Weapon trace component** that activates hitboxes during attack windows
- **Lock-on targeting** (`LockonComponent`) to orbit-strafe an enemy
- **Stats component** tracking health and other attributes via `TMap`
- **Fighter / Enemy / MainPlayer interfaces** for clean cross-actor communication

### AI
- Behaviour driven by Unreal's **StateTree** plugin (`CombatStateTreeUtility`)
- Custom **Environment Query** context that targets the player (`EnvQueryContext_Player`)
- Spawner actor (`CombatEnemySpawner`) for runtime enemy management

### Gameplay Variants
The project contains three self-contained gameplay variants, each with its own character class, game mode, player controller, and any supporting actors:

| Variant | Key feature |
|---|---|
| `Variant_Combat` | Action sword combat with AI enemies, lava floors, damageable boxes, checkpoints |
| `Variant_Platforming` | 3D platformer with dash ability and soft/moving platforms |
| `Variant_SideScrolling` | Side-scrolling character with NPC AI, jump pads, pickups, and a UI life bar |

## License

The original C++ source code in this repository is released under the **MIT License** — see [LICENSE](LICENSE) for details.

Engine template code (files bearing `// Copyright Epic Games, Inc. All Rights Reserved.`) and all binary content assets (`.uasset`, `.umap`, FBX meshes) are the property of Epic Games, Inc. and are subject to the [Unreal Engine EULA](https://www.unrealengine.com/eula/unreal). You must hold a valid Unreal Engine license to use them.
