# Sudoku Solver (C++)

A C++ program that solves Sudoku puzzles using backtracking with bitmask optimization.

## Features

- Solves N×N Sudoku boards
- Tested on 4×4 and 9×9 Sudoku
- Uses bitmasking for fast constraint checks
- Option to find one solution or all solutions

## How it works

The solver fills the board using recursion and backtracking.
For each empty cell, valid numbers are computed using bitmasks
to avoid repeated row, column, and subgrid checks.

## How to run

Compile:
g++ main.cpp -o sudoku

Run:
./sudoku

## Input format

- Enter the board size (e.g. 9)
- Enter the board values (0 represents empty cells)
- Choose whether to print one solution or all solutions
