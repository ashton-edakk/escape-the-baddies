Hero Escape Game (C++)
Overview

This project is a simple terminal-based adventure game written in C++. The player controls a hero attempting to escape from a game board while avoiding obstacles and enemies. Each turn, the player inputs a movement command, the game state updates, and the board is re-rendered until the hero either escapes or the game ends.

The project is structured across multiple files, with main.cpp handling the main game loop and user interaction, and supporting files (such as gameboard.h and its implementation) managing the game logic and board state.

Features

Turn-based movement system

Text-based user input

Dynamic game board display

Win and lose conditions

Modular design using header and source files

File Structure
.
├── main.cpp          # Entry point and main game loop
├── gameboard.h       # GameBoard class definition
├── gameboard.cpp     # GameBoard implementation
├── README.md         # Project documentation


Additional supporting files may be included depending on your implementation.

How the Game Works

The game initializes a GameBoard object.

The board is displayed to the player.

Each turn:

The player is prompted to enter a move (e.g., 's' to stay, other keys for movement).

The game updates the hero and other entities.

The updated board is displayed.

The game ends when:

The hero successfully escapes (win condition), or

The hero fails to escape (loss condition).

At the end, the game prints the result and exits.

Controls

When prompted, enter a single character to indicate your move:

s – Stay in place

Other movement keys depend on how movement is defined in GameBoard

(Refer to gameboard.h for exact movement rules.)

Building and Running
Compile

Using g++:

g++ main.cpp gameboard.cpp -o hero_escape

Run
./hero_escape

Requirements

C++ compiler supporting C++11 or later

Standard C++ libraries only (no external dependencies)

Notes

Input is case-sensitive.

The game uses standard input/output (cin / cout).

Random elements may be seeded using the system clock.

Future Improvements (Optional)

Add difficulty levels

Improve board visualization

Add replay support

Add more enemy or obstacle types

If you want, I can tailor this README to a class assignment, add screenshots, or rewrite it to match a professor’s rubric.
