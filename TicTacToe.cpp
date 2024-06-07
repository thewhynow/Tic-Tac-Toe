#include <iostream>
#include <ctime>

void drawBoard(char board[3][3]);

char detectWin(char board[3][3]);

void getInput(char board[3][3]);

void oSelect(char board[3][3]);

int main(){
   char board[3][3] = {
      {'#', '#', '#'},
      {'#', '#', '#'},
      {'#', '#', '#'}
   };
   char winner = 'N';
   srand(time(0));

   while (true){
      getInput(board);
      if (detectWin(board) == 'F'){
         drawBoard(board);
         std::cout << "oof, looks like no one can win this one! Maybe next time! \n";
         break;
      }
      oSelect(board);
      winner = detectWin(board);
      if (winner == 'X'){
         drawBoard(board);
         std::cout << "Congrats! You Won! \n";
         break;
      }
      else if (winner == 'O'){
         drawBoard(board);
         std::cout << "Oof, you just lost to a cpu >:( \n";
         break;
      }
      else if (winner == 'F'){
         drawBoard(board);
         std::cout << "oof, looks like no one can win this one! Maybe next time! \n";
         break;
      }
   }

   return 0;
}

void drawBoard(char board[3][3]){   // iterates through the board array and displays the values
   std::cout << "\n***********\n";
   for (int i = 0; i < 3; i++){
      for (int j = 0; j < 3; j++){
         std::cout << board[i][j] << " ";
      }
      std::cout << "\n";
   }
   std::cout << "***********\n";
}

void getInput(char board[3][3]){    // gets the input and displays the current board
   int xCoordinate = 1;
   int yCoordinate = 1;

   std::cout << "\n***********\n";

   for (int i = 0; i < 3; i++){
      std::cout << 3 - i << "  ";
      for (int j = 0; j < 3; j++){
         std::cout << board[i][j] << " ";
      }
      std::cout << "\n";
   }
   std::cout << "\n   1 2 3\n";
   std::cout << "***********\n";

   while (true){
      std::cout << "Enter the x coordinate of where you want to place your move: ";
      std::cin >> xCoordinate;

      std::cout << "Enter the y coordinate of where you want to place your move: ";
      std::cin >> yCoordinate;

      if (board[-(yCoordinate) + 3][xCoordinate - 1] != '#'){
         std::cout << "Enter a coordinate that has not already been filled! \n";
      }
      else{
         board[-(yCoordinate) + 3][xCoordinate - 1] = 'X';
         break;
      }
   }
}

void oSelect(char board[3][3]){     // picks a random position on the board
   while (true){
      int xCoordinate = (rand() % 3) + 1;
      int yCoordinate = (rand() % 3) + 1;
      if (board[yCoordinate - 1][xCoordinate - 1] == '#'){
         board[yCoordinate - 1][xCoordinate - 1] = 'O';
         break;
      }
   }
}

char detectWin(char board[3][3]){   // checks the board for any winning cases
   bool xWinner = false;
   bool oWinner = false;
   bool filled = false;
   char xWin[] = {'X', 'X', 'X'};
   char oWin[] = {'O', 'O', 'O'};

   for (int i = 0; i < 3; i++){     // checks for any horizontal rows
      for (int j = 0; j < 3; j++){  // checks for rows of X
         if (board[i][j] == xWin[j]){
            xWinner = true;
         }
         else{
            xWinner = false;
            break;
         }
      }
      
      if (xWinner == true){
         return 'X';
      }

      for (int j = 0; j < 3; j++){  // checks for rows of O
         if (board[i][j] == oWin[j]){
            oWinner = true;
         }
         else{
            oWinner = false;
            break;
         }
      }

      if (oWinner == true){
         return 'O';
      }
   }

   for (int j = 0; j < 3; j++){     // checks for any vertical rows
      for (int i = 0; i < 3; i++){
         if (board[i][j] == xWin[i]){
            xWinner = true;
         }
         else{
            xWinner = false;
            break;
         }
      }
      if (xWinner == true){
         return 'X';
      }

      for (int i = 0; i < 3; i++){
         if (board[i][j] == oWin[i]){
            oWinner = true;
         }
         else{
            oWinner = false;
            break;
         }
      }
      if (oWinner == true){
         return 'O';
      }
   }

   for (int i = 0; i < 3; i++){     // checks for diagonal (X)
      if (board[i][i] == 'X' || board[2-i][i] == 'X'){
         xWinner = true;
      }
      else{
         xWinner = false;
         break;
      }
   }
   if (xWinner == true){
      return 'X';
   }

   for (int i = 0; i < 3; i++){     //checks for diagonal (O)
      if (board[i][i] == 'O' || board[2-i][2-i] == 'O'){
         oWinner = true;
      }
      else{
         oWinner = false;
         break;
      }
   }
   if (oWinner == true){
      return 'O';
   }

   for (int i = 0; i < 3; i++){     // checks if the board is entirely filled
      for (int j = 0; j < 3; j++){
         if (board[i][j] != '#'){
            filled = true;
         }
         else{
            filled = false;
            break;
         }
      }
      if (filled == false){break;}
   }

   if (filled == true){
      return 'F';
   }

   return 'N';
}