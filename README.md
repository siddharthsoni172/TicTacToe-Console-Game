# Retro Tic-Tac-Toe Game

An elegant, console-based implementation of the classic Tic-Tac-Toe game written in C++. Developed as part of an engineering internship submission, this project showcases clean separation of logic using 2D matrix arrays, algorithm optimization for game-state tracking, and comprehensive command-line UI re-rendering features.

## 🚀 Key Features
* **Dynamic Grid Render Engine:** Flushes and updates the interface after each move to mimic a clean, smooth digital screen display.
* **Algorithmic Evaluation Structure:** Actively monitors matrix paths to handle real-time win, loss, and draw conditions.
* **Linear-to-Matrix Coordinate Mapping:** Maps straightforward single-digit user choices (1–9) onto precise 2D grid coordinates.
* **Input-Fault Handling:** Uses internal stream error management to process input cleanly and prevent game loop crashes from invalid selections.
* **Replay Mechanics:** Offers an instant loop option to start a fresh match without needing to relaunch the program.

## 🛠️ Technical Concepts Implemented
* **Multidimensional Data Frameworks:** Uses a 3x3 array structure to hold the active playfield and cross-reference token placement.
* **Conditional Logic Matrixing:** Iterates across grid coordinates to check rows, columns, and diagonal patterns for winning sets.
* **Process Flow Engineering:** Implements specialized modular functions to decouple presentation rules from core calculations.

## 📂 Architecture Map
* `main.cpp` - Houses the primary game loop, state evaluations, matrix mapping, and command-line display rendering rules.
