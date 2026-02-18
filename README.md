# Unreal Engine Inventory, Crafting, and Save System (C++)

This repository showcases the core C++ systems developed for my Unreal Engine 5 game “The Core: Lockdown”. The full game source code cannot be made public due to licensed assets.

**Playable game:** [The Core: Lockdown](https://thecoredev.itch.io/the-core-lockdown)

---

## Overview

This repository contains three interconnected systems, an inventory system, crafting system, and a save & load system. They are all modular and designed for extensibility. They have also been designed to be future-proof such that most additions I make to the game won't require significant changes to the source code.

---

## Key Features

### 1. Inventory System
- Supports consumables, stackable and non-stackable items and unique items.
- Creates inventory change events through dynamic multicast delegates for UI updates.
- Easy retrieval, categorisation and organisation of items.

### 2. Crafting System
- Works with the inventory system to check item requirements and adds crafted items to the inventory.
- Uses crafting recipe data assets to prevent hard coding recipes.
- Easy to add new recipes and items.

### 3. Save & Load System
- Saves player inventory state and world position.
- Supports save overwrites, save deletion, and loading from save data.
- Implemented through the game instance.
