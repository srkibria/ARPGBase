# ARPGBase
## A Starter Project for an Action RPG Style game

This is a starter project for making an Action RPG game with Unreal Engine. This project intends to have all the starting code for you to start making your own stats-driven Action RPG game. Towards That end, this game has a base implementation of the Gameplay Ability System, Gameplay Attributes, Damage sweeps, Damage calculation, and Gameplay Tags in order to make a modular Action RPG framework.

## Current Features
### Game Ability System
The Base character is configured to use the ability system and has a basic Attribute set with RPG-like stats. This combined with abilities allows for Damage calculations and modularized abilities that eventually will be able to be enabled and disabled based on the current context. The HP has been clamped between zero and an editable MAX HP that can be updated throughout the gameplay
### Damage sweep
Basic implementation to ensure that multiple overlap events do not deal multiple damage during a single attack. 
### Physical Animation (damage reaction)
Reduce the need to add manual animation for hit reactions. 
### Faction System
The game starter project has a faction system using Unreal Engines  for use in preventing friendly fire as well as for use  
### Pickups
Currently Have Health and Mana pickups that allow for the recovery of these stats.
## Features In Progress
### Ability Pickups
### Ability Addition and Removal
## Planned Features
### Inventory System
### Equipment System
### Physical Animation(recovery after falling)
