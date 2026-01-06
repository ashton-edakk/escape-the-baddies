# Hero Escape Game (C++)

## Overview
This project is a **terminal-based adventure game written in C++**. The player controls a hero attempting to escape from a game board while avoiding obstacles and enemies. The game runs in a loop where the player enters commands, the board updates, and the game continues until a win or loss condition is met.

The program is split across multiple files. `main.cpp` handles the main game loop and user interaction, while supporting files manage the game board and game logic.

---

## Features
- Turn-based gameplay
- Text-based input and output
- Dynamic game board rendering
- Win and loss conditions
- Modular C++ design using header and source files

---

## File Structure
```text
.
├── main.cpp          # Entry point and main game loop
├── gameboard.h       # GameBoard class definition
├── gameboard.cpp     # GameBoard class implementation
├── README.md         # Project documentation
