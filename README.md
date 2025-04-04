Tic-Tac-Toe (5x5) Game in C

  Introduction

This is a console-based Tic-Tac-Toe game developed in C during my university studies. It features a 5x5 grid, supports two game modes (Single Player vs Computer and Multiplayer), and offers a challenging AI opponent.



  Objective

The game's objective is simple:

Two players compete by placing markers (X for Player 1, O for Player 2 or Computer).

The goal is to achieve 5 consecutive markers (horizontally, vertically, or diagonally).

The first player to achieve this wins; if no one can achieve this, the game ends in a draw.



  Features

Single-player mode with a computer opponent.

Multiplayer mode for two human players.

Clear instructions and interactive console-based UI.

Responsive validation of player inputs.

Game results clearly displayed with entertaining messages.



  How to Play

Choose Game Mode

Select between playing against another player (Multiplayer) or playing against the computer (Single-player).

Marker Selection

Player 1 always uses marker X.

Player 2 or Computer uses marker O.

Game Flow

The grid (5x5) displays coordinates clearly (X for columns, Y for rows).

Players take turns entering coordinates to place markers.

Coordinates must be entered sequentially: first X (column), then Y (row).

Win Condition

The first player to place five consecutive markers horizontally, vertically, or diagonally wins.

If the grid fills with no winner, the game is declared a tie.



  Input Validation

The program ensures smooth gameplay by handling incorrect inputs:

Invalid Game Mode Choice:

Displays:

csharp
Copy
Edit
The letter entered is not accepted! Please do enter the corrected letter again
Invalid or Occupied Coordinates:

Displays:

pgsql
Copy
Edit
Co-ordinate is not valid, enter again m8


Game Outputs
Clear messages enhance the game experience:

Player Win:

Copy
Edit
Nice! Player DESTROYED Computer!
Computer Win:

perl
Copy
Edit
Wow player you lost, Computer wins! Oh my God you're such a CASUL!
Draw:

vbnet
Copy
Edit
It's a tie! Too bad nobody wins!


  Computer  
  
The computer opponent has a built-in strategy to keep games engaging:

Offensive Play:

The Computer attempts to place markers to quickly achieve 5 consecutive markers.

Defensive Play:

It actively blocks the player's markers to prevent player victories.

Fallback Strategy:

If no immediate offensive or defensive moves are available, the computer randomly chooses a valid, unoccupied space.



  Project Structure
  
This project consists of a clear and maintainable structure:

Main Function (int main)

Handles game initialization and loop control.

Sub-functions:

Grid Display (void gridDisplay())

Prints the current state of the 5x5 grid and coordinates clearly.

Player Move (void playerMove())

Captures, validates, and places player markers based on user-entered coordinates.

Computer Move (void computerMove())

Computes and places the computer’s markers strategically.

Check Winner (int checkWin())

Determines if a player or computer has won, or if the game is a tie.

All functions and logic are encapsulated, and variables are managed within functions (minimal use of global variables).



  Language and Concepts Used
  
Programming Language: C

Core concepts:

Functions (void and int return types)

Loops (while, for)

Conditional statements (if, else if, else)

Arrays (used for grid representation and game logic)



  Running the Game
  
To compile and run the program, use any standard C compiler (GCC recommended):

bash
Copy
Edit
gcc tic-tac-toe.c -o tic-tac-toe
./tic-tac-toe


  Potential Improvements
  
Graphical user interface (GUI) for enhanced visual appeal.

More advanced AI algorithms for greater difficulty and engagement.

Additional game modes or larger grid sizes.


 Author
 
Mohammed Kekli

Assignment: Introduction to Programming C, Build a Tic-Tac-Toe Game (University Of Liverpool Project).
