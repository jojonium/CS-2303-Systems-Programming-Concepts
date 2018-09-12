CS2303 - Systems Programming Concepts
=====================================

Assignments and coursework for the WPI computer science class CS2303 - Systems Programming Concepts

## Assignment 1 - Calendar

The goal of this project is to learn about developing C programs on Linux, nested selection and
iteration, and advanced formatting of strings and conversion specifiers in C.

To compile the program, simply use the `make` command. You can then run it with the command `./PA1`.
The program will prompt the user to imput a year, then print out the 12 month calendar for that year
to the terminal. Because the first full year of the modern Gregorian calendar was 1583, entering any
year before this will result in an error.

## Assignment 2 - Game of Life

The goal of this assignment is to learn about two-dimensional arrays, memory allocation at run-time,
and passing arrays as arguments to functions in C.

This program plays Conway's Game of Life on a finite grid based on an input text file. Some example
input files are given in the assignment2 folder. Input files use `x`s to represent living cells and
`o`s to represent dead or unoccupied cells.

To compile the program, simply use the `make` command. You can then run it with the following command:

`./life NR NC gens input [print] [pause]`

where _NR_ and _NC_ are unsigned integers indicating the number of rows and columns of the board,
respectively. _gens_ is the maximum number of generations the game will play. _print_ and _pause_ are
optional paramters. If _print_ is `y`, the board state will be printed after each generation. If
_pause_ is 'y' the game will pause and wait for user input between each generation.

If the game ever reaches a state where nothing is moving, or the board is oscillating between two
states, it will exit with an informative message.
