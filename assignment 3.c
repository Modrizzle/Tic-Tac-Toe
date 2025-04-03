#include <stdio.h> // The library is used for almost all functions in this algorithm 
#include <stdlib.h> // The library is here for the random number generator inside the function for the computer
#define Rows 5 // This is defined for the value of 5 to be assigned for the word Rows - this is an indication of grid having 5 Rows
#define Cols 5 // This is defined for the value of 5 to be assigned for the word Cols - this is an indication of grid having 5 Cols

void displayGrid(char Grid [Rows][Cols]) //The function of void displayGrid(char grid[Rows][Cols]) is used to display the Grid of the X/O game on the screen 
{
//  In this grid the %c is assigned a coordinate position number due to Grid[Rows][Cols], this enables the player to insert the correct co-ordinate into the program 
 printf("\n");
 printf("    1     2     3     4     5\n");
 printf(" |-----|-----|-----|-----|-----|\n");
 printf("1|  %c  |  %c  |  %c  |  %c  |  %c  |\n", Grid[0][0], Grid[0][1], Grid[0][2], Grid[0][3],
Grid[0][4]);
 printf(" |-----|-----|-----|-----|-----|\n");
 printf("2|  %c  |  %c  |  %c  |  %c  |  %c  |\n", Grid[1][0], Grid[1][1], Grid[1][2], Grid[1][3],
Grid[1][4]);
 printf(" |-----|-----|-----|-----|-----|\n");
 printf("3|  %c  |  %c  |  %c  |  %c  |  %c  |\n", Grid[2][0], Grid[2][1], Grid[2][2], Grid[2][3],
Grid[2][4]);
 printf(" |-----|-----|-----|-----|-----|\n");
 printf("4|  %c  |  %c  |  %c  |  %c  |  %c  |\n", Grid[3][0], Grid[3][1], Grid[3][2], Grid[3][3],
Grid[3][4]);
 printf(" |-----|-----|-----|-----|-----|\n");
 printf("5|  %c  |  %c  |  %c  |  %c  |  %c  |\n", Grid[4][0], Grid[4][1], Grid[4][2], Grid[4][3],
Grid[4][4]);
 printf(" |-----|-----|-----|-----|-----|\n");
 printf("\n");
 
}
void choosePos(char Grid [Rows][Cols], int Player_Number) //The function of void choosePos(char grid [Rows][Cols], int Player_Number) is used to display the marker on the grid inserted by the players
{
	
 int f; // Declared f as an Intiger
 int d; //Declared d as an Intiger  
 int Row; //  Declared  Row as an Intiger
 int Column;// Declared Coulumn as an Intiger
 int x;//Declared x as an Intiger
 int valid = 0; //a value of 0 is assigned to the int valid which begins from zero
 
 while (Player_Number == 1 && valid == 0)//this is when player_number equals 1 and valid equals 0
 
 {
 	
 printf("\nPlayer number 1 plays first:\n");
 printf("\nInsert x co-ordinate please:\n");
 scanf("%i", &d);//an intiger that is inserted which agrees to the grid
 fflush(stdin);//gets rid of buffers
 printf("\nInsert y co-ordinate please:\n");
 scanf("%i", &f);//an intiger that is inserted which agrees to the grid
 fflush(stdin);//gets rif of buffers
 Row = f - 1;//this is used for assigning a real value instead of the computer value
 Column = d - 1;
 
 if (Grid[Row][Column] == ' ' && Row>=0 && Row<=4 && Column>=0 && Column<=4)
 
 {
 	
 Grid[Row][Column] = 'X';//As soon as the above criteria is achieved the X marker is placed on the grid
 displayGrid(Grid);
 x++;//the while loop is repeated
 valid = 1;
 
 }
 
 else
 
 printf("\nCo-ordinate not valid\n");// This apears on the screen when a incorrect co-rdinate is inserted
 
 }
 
while (Player_Number == 2 && valid == 0)//this is when player_number equals 2 and valid equals 0

 {
 	
// repeated for player number 2 just like player number 1

 printf("\nPlayer number 2's turn:");
 printf("\nInsert x co-ordinate please:\n");
 scanf("%i", &d);
 fflush(stdin);
 printf("\nInsert y co-ordinate please:\n");
 scanf("%i", &f);
 fflush(stdin);
 Row = f - 1;
 Column = d - 1;
 
 if (Grid[Row][Column] == ' ' && Row>=0 && Row<=4 && Column>=0 && Column<=4)
 
 {
 	
 Grid[Row][Column] = 'O';// As soon as the above criteria is achieved the O marker is placed on the grid
 displayGrid(Grid);
 x++;
 valid = 1;
 
 }
 
 else
 
 printf("\nCo-ordinate is not valid, enter again m8\n");
 
 }
 
}
void compPos(char Grid [Rows][Cols], int computer_number, int player_number)//This function is used to display the X/O on the grid when the coordinates are entred
{
	
 int x = 0; //a value of 0 is assigned to the integer x which starts from 0
 int y = 0; //a value of 0 is assigned to the integer y which starts from 0
 char computer_Character; //declared computer_Character as a character 
 char player_Character; //declared player_Character as a character 
 int moved = 0; //a value of 0 is assigned to moved which starts from 0  
 if(player_number == 1)//Computer uses O and player uses X
 {
 	
 player_Character = 'X';
 computer_Character = 'O';
 }
 
 else //Computer uses X and player uses O
 
 {
 	
 computer_Character = 'X';
 player_Character = 'O';
 
 }
 
 while (x <=4 && moved == 0) //Part 1_deciding if computer can win
 
 {
 	
 y = 0;
 
 while (y <=4 && moved == 0) //This is when y is < than 4 and moved = 0
 
 {
 	
 if (Grid[x][y] == ' ')
 
 {
 	
 Grid[x][y] = computer_Character;//computer decides weather 
 
 if(checkWin(Grid) == computer_number)//it has the ability to win the following
 
 {
 	
 moved = 1;
 printf("\na. Computer made its move to (%i, %i)", y+1, x+1);//a value is assigned but it isnt the computer value
 
 } 
 
 else
 
 {
 	
 Grid[x][y] = ' ';//Nothing occurs
 
 }
 
 }
 
 y++;//the loops goes over again with a variety of values
 
 }
 
 x++;//the loops goes over again with a variety of values
 
 }
 
 x = 0;
 
 y = 0;
 
 while (x <=4 && moved == 0) //Part 2 - close off player_number
 
 {
 	
 y = 0;
 
 while (y <=4 && moved == 0)//This is when y is < than 4 and moved = 0
 
 {
 	
 if (Grid[x][y] == ' ')
 
 {
 	
 Grid[x][y] = player_Character;//computer decides weather 
 
 if(checkWin(Grid) == player_number)//player has the ability to win the following round
 
 {
 	
 moved = 1;
 Grid[x][y] = computer_Character;//If it does then computer makes its move there
 printf("\nb. Computer made its move to (%i, %i)", y+1, x+1);
 
 } 
 
 else
 
 {
 	
 Grid[x][y] = ' ';
 
 }
 
 }
 
 y++;//the loops goes over again with a variety of values
 
 }
 
 x++;//the loops goes over again with a variety of values
 
 }
 
 x = 0;
 
 y = 0;
 
 while(moved ==0) //Computer given a random position
 
 {
 	
 x=rand() %5;//<stdlib.h> is used to find this fuction, %5 is limited to a value of 5 for int x
 y=rand() %5;//<stdlib.h> is used to find this fuction, %5 is limited to a value of 5 for int y
 
 if(Grid[x][y] == ' ')
 
 {
 	
 Grid[x][y] = computer_Character;//computer places its marker there
 moved = 1;
 printf("\nc. Computer moves to (%i, %i)", y+1, x+1);
 
 }
 
 }
 
 displayGrid(Grid);//after the manoeuvre is made the grid is displayed on screed
 
}
int main()//All the functions are grouped togather inside the main function to create the overall algorithim
{
 char Grid [Rows][Cols];//a character grid is declared along with values defined as rows = 5 and cols = 5
 char KORM; //a character of KORM is declared, K stands for 2-Player and M stands for Computer
 int player_number = 1; //In the computer game, iether player 1st or 2st, player_number declared as an integer
 int winner = 0;// a value of 0 is assigned to the integer Winner which starts from zero
 int x = 0;//  a value of 0 is assigned to x which starts from zero
 int y = 0;//  a value of 0 is assigned to x which starts from zero
 char HORG;// HORG is declared as a character, h stands for First and g stands for Second
 int KORM_Turn = 1; // 1 equals = K turn || 2 equals = M turn.
 
 while (x<=4)
 
 {
 	
 y = 0;
 
 while (y<=4)
 
 {
 	
 Grid[x][y] = ' ';
 
 y++;
 
 }
 
 x++;
 
 }
 
 printf("([-])([+])([-])([+])([-])\n");
 printf("()X/ O TIC-TAC-TOE GAME()\n");
 printf("([-])([+])([-])([+])([-])\n");
 
 printf("\nDo you wish to start the game with Player 2 or Computer?\n");
 printf("'K' = 2-player, 'M' = computer:\n");
 scanf("%c", &KORM);//iether the K character is used or M character is used
 fflush(stdin);
 KORM = tolower(KORM);//If a capital letter is entered it is lowerd to a lower case so its not case sensitive
 
 while(KORM != 'k' && KORM != 'm'){ //if nor K or M is inserted then the scentence below will be shown and program will ask the player to enter again
 printf("\nThe letter entered is not accepted! Please do enter the corrected letter again\n");
 printf("\nDo you wish to start the game with Player 2 or Computer?\n");
 printf("'K' = 2-player, 'M' = computer:\n");
 scanf("%c", &KORM);
 
 fflush(stdin);
 
 }
 
 if (KORM == 'k')//is the case if player choose K
 
 {
 	
 printf("\n Now we start with inserting numbers by enetring a number for x as well as y co-ordinates:\n");
 printf("the combination of Co-ordinates (5, 1) is at the top right of the grid\n\n");
 displayGrid(Grid);//the function is called in from the top which is much easier than processing everything in the main function
 
 x = 0;
 
 while (x < 25 && winner==0)
 
 {
 	
 choosePos(Grid, player_number);//fucntion is called in from the top
 winner = checkWin(Grid);// fucntion is called in from the top
 
 x++;
 
 if (player_number == 1) //if playernum is assigned 1 then player to is give the value of 2
 
 {
 	
 player_number = 2;
 
 }
 
 else
 
 {
 	
 player_number = 1;// else playernum 1 is given the value of 1
 
 }
 
 }
 
 if (winner ==0)// happens when nobody wins 
 
 {
 	
 printf("it's a tie! Too bad nobody wins!\n");
 
 } 
 
 else//happens if sombody does win
 
 {
 	
 printf("Nice! Ya boi Player %i has won!\n", winner);
 
 }
 
 }
 
 if(KORM == 'm')// if computer is chosen
 
 {
 	
 printf("\nDo you Wish to start first or play seconed?");
 printf("\n'h' = player 1, 'g' = player 2:\n");
 scanf("%c", &HORG);
 fflush(stdin);
 
 while(HORG != 'h' && HORG != 'g')
 
 {
 	
 printf("\nThe letter entered is not correct! try again bruh\n");
 printf("\nDo you wish to start or play seconed?");
 printf("\n'h' = player 1, 'g' = player 2:\n");
 scanf("%c", &HORG);
 
 fflush(stdin);
 
 }
 
 do//A while a loop is used because the function needs the algorithm to check this before looking at the following condition
 
 {
 	
 int computer_number = 2; //I rather declared this here as this is only needed for computer and not for player vs player 
 
 if(HORG == 'g')// if seconed is the chosen option then these are the values given to the wordds
 
 {
 	
 player_number = 2;
 KORM_Turn = 2;
 computer_number = 1;
 
 }
 
 printf("\nWe shall enter the numbers in terms of x as well as y co-ordinates\n");
 printf("the Co-ordinate (1,1) is placed on the top left of the grid\n\n");
 displayGrid(Grid);
 
 x = 0;
 
 while (x < 25 && winner==0)//only 25 squares are available, so that is the amount used
 
 {
 	
 if(KORM_Turn == 1) //if players turn
 
 {
 	
 choosePos(Grid, player_number);//this is the function is used
 
 }
 
 if(KORM_Turn ==2) //if computers turn
 
 {
 	
 compPos(Grid, computer_number, player_number); //this function is used
 
 }
 
 winner = checkWin(Grid);//post who is the winner is checked
 
 x++;
 
 if (KORM_Turn == 1)
 
 {
 	
 KORM_Turn =2;
 
 }
 
 else
 
 {
 	
 KORM_Turn = 1;
 
 }
 
 }
 
 if (winner == 0)
 
 {
 	
 printf("it's a tie! Too bad nobody wins!\n");
 
 } 
 
 else if(winner == player_number)
 
 {
 	
 printf("Nice! player DESTROYED computer!\n");
 
 }
 
 else
 
 {
 	
 printf("Wow player you lost, Computer wins! Oh my God your such a CASUL!\n");
 
 }
 
 }
 
 while(HORG == 'h' && HORG == 'g');
 
 }
 
 return 0;
 
}
int checkWin(char Grid [Rows][Cols]) //this functions declares which player won
{
 int x = 0; //a value of 0 is assigned to integer x which starts from zero
 int y = 0; //a value of 0 is assigned to integer y which starts from zero
 int player_number_1_win; //player_number_1_win is declared as an integer
 int player_number_2_win; //player_number_2_win is declared as an integer
//to see who has won for ROWS - 'X' or 'O'
 while (x <=4) // When the row is under 4 (which can be considered as 5 because computer starts from 0 instead of 1) only then does this function work
 
 {
 	
 y = 0; //this is used from the above assigned integer in this loop
 player_number_1_win = 1; // player_number_1_win is assigned the number 1
 player_number_2_win = 2;// player_number_2_win is assigned the number 1
 while (y <=4) // when the value is less than 4
 
 {
 	
 if (Grid[x][y] != 'X') //the case when grid rows does not meet 1
 player_number_1_win = 0; //nothing occurs
 if (Grid[x][y] != 'O') //the case when the grid rows does not meet 0
 player_number_2_win = 0; //Nothing occurs
 
 y++; //every column is be repeated
 
 }
 
 if (player_number_1_win == 1 || player_number_2_win == 2 ) //if player_number_1 equates to exactly 1 or if that is the case with player_number_2 but equates exactly 2. The loop ends and flows to the conditions below
 
 {
 	
 break; //Ends the loop
 
 }
 
 x++; // then is repeated for rows
 
 }
 
 if(player_number_1_win == 1)// if grid rows equates to 1 the player_number_1 wins
 
 {
 	
 return 1;
 
 }
 
 else if(player_number_2_win == 2)//if grid rows equates to 2 the player_number_2 wins
 
 {
 	
 return 2;
 
 }
 
//A cheking process is carried out for diagonal left to right for who won _ 'X' or 'O'
// this is used from the above assigned integer in this loop - values are reset

 x = 0;
 player_number_1_win = 1;
 player_number_2_win = 2;
 while (x <=4)
// Within the grid x is equal to x so the numbers are equal to each other therefore (1,1), (2,2), (3,3), (4,4), (5,5) shall only win diagnoly 
 {
 	
 if (Grid[x][x] != 'X') //if x=x doesent have 'X' then that means player_number_1 does not win 
 player_number_1_win = 0;
 if (Grid[x][x] != 'O') //if x=x doesent have 'O' then that means player_number_2 does not win 
 player_number_2_win = 0;
 
 x++; //the loop for diagonals is repeated
 
 }
 
 if(player_number_1_win == 1) //if the grid diagonals equates to 1 then player_number_1 wins
 
 {
 	
 return 1;
 
 }
 
 else if(player_number_2_win == 2) //if the grid diagonals equates to 2 then player_number_2 wins
 
 {
 	
 return 2;
 
 }
 
//A cheking process is carried out for diagonal right to left for who won _ 'X' or 'O'
//this is used from the above assigned integer in this loop - values are reset
 x = 0;
 player_number_1_win = 1;
 player_number_2_win = 2;
 
while (x <=4)

//Within the grid x is equal to x so the numbers are equal to each other therefore (1,5), (2,4), (3,3), (4,2), (5,1)  shall only win diagnoly 

 {
 	
 if (Grid[x][4-x] != 'X')//this is the case if the grid diagonal does not equate to X
 player_number_1_win = 0;//Nothing occurs
 if (Grid[x][4-x] != 'O')//this is the case if the grid diagonal does not equate to O
 player_number_2_win = 0;//Nothing occurs
 
 x++;
 
 }
 
 if(player_number_1_win == 1)//, if the grid diagonals equates to 1 then player_number_1 wins
 
 {
 	
 return 1;
 
 }
 
 else if(player_number_2_win == 2) //if the grid diagonals equates to 2 then player_number_2 wins
 
 {
 	
 return 2;
 
 }
 
//process of checking who won for columns _ 'X' or 'O'
//this is used from the above assigned integer in this loop - values are reset
 x = 0;
 
 y = 0;
while (x <=4)

 {
 	
 y = 0;
 player_number_1_win = 1;
 player_number_2_win = 2;
 while (y <=4)
 
 {
 	
 if (Grid[y][x] != 'X') //this is the case if the grid diagonal does not equate to X
 player_number_1_win = 0;//Nothing occurs
 if (Grid[y][x] != 'O')//this is the case if the grid diagonal does not equate to O
 player_number_2_win = 0;//Nothing occurs
 
 y++;
 
 }
 
 if (player_number_1_win == 1 || player_number_2_win ==2 ) //if player_number_1 equates to exactly 1 or if that is the case with player_number_2 but equates exactly 2. The loop ends and flows to the conditions below
 
 {
 	
 break;
 
 }
 
 x++;//this is repeated for the columns
 
 }
 
 if(player_number_1_win == 1)//if the grid diagonals equates to 1 then player_number_1 wins
 
 {
 	
 return 1;
 
 }
 else//if the grid diagonals equates to 2 then player_number_2 wins
 
 {
 	
 return player_number_2_win;
 
 }
 
}
