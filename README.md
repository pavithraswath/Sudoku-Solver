# Sudoku Solver (C++)

A Sudoku solver implemented in C++ using backtracking with bitmask optimization, with a simple web-based UI for input and output.

## Features

- Solves N×N Sudoku boards
- Tested on 4×4 and 9×9 Sudoku
- Uses bitmasking for fast constraint checks
- Option to find one or all valid solutions
- Simple web interface to enter puzzles and display solutions

## How it works

The solver fills the board using recursion and backtracking.  
For each empty cell, valid numbers are computed using bitmasks  
to avoid repeated row, column, and subgrid checks.

The web interface sends the puzzle to a Node.js server, which runs  
the C++ solver and returns the solved grid to the page.

## How to run

### 1. Compile the solver

g++ main.cpp -o sudoku

### 2. Install dependencies

npm install express

### 3. Start the server

node server.js

### 4. Open in browser

http://localhost:3000/index.html

## Input format

- Choose board size (4×4 or 9×9) from the start page
- Enter numbers in the grid (leave empty cells blank or 0)
- Click **Solve** to display the solution
