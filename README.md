# 🐬 So Long

## 🎮 Project Summary

**So Long** is a small 2D game built using the **MiniLibX** graphical library. The objective is to collect all collectibles on the map and reach the exit while avoiding walls. The project helps reinforce basic concepts in game development like map parsing, input handling, image rendering, and path validation.

---

## 📋 Table of Contents

- [Project Summary](#-project-summary)
- [Features](#-features)
- [Requirements](#-requirements)
- [Installation](#-installation)
- [Usage](#-usage)
- [Map Format](#-map-format)
- [Controls](#-controls)

---

## 🚀 Features

- 2D top-down view using **MiniLibX**
- Real-time movement via keyboard
- Terminal output of movement count
- Valid path-checking algorithm
- Wall collision prevention
- Clean window and memory management
- Customizable sprites and assets
- Support for `.ber` map files

---

## ⚙️ Requirements

- GCC compiler
- `make`
- `MiniLibX` installed
- macOS or Linux (Linux may require additional setup for MiniLibX)
- Your own implementation of `libft` (if used)

---

## 🔧 Installation

Clone the repository and run:

```bash
make
```
If MiniLibX is not installed system-wide, make sure it's available in your project structure and linked properly in your Makefile.

## ▶️ Usage
Run the game by providing a valid map file with .ber extension:

```bash
./so_long path/to/map.ber
```
Example:

```bash
./so_long maps/sample.ber
```
## 🗺️ Map Format
A valid map consists only of the following characters:

- Character	Meaning
- 1	Wall
- 0	Empty space
- C	Collectible
- E	Exit
- P	Player's start point

Example
```bash
1111111
1P0C0E1
1000001
1111111
```
Map rules:
- Must be rectangular

- Must be enclosed by walls

- Must contain exactly one P and E

- Must contain at least one C

- Must have a valid path from P to all C and to E

## 🎮 Controls
- W – Move up

- A – Move left

- S – Move down

- D – Move right

- ESC – Exit the game

- Clicking the window close button also exits the game

- Each move is displayed in the terminal as a movement counter.

## 🏁 Credits
Developed as part of the 42 School core curriculum project.
