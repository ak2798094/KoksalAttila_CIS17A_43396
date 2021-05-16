/* 
 * File:   main.cpp
 * Author: Attila Koksal
 * Created on April 17, 2021, 8:30 PM
 * Purpose:  CPP Template 
 *           To be copied for each Assignment Problem
 */

//System Libraries
#include <iostream>  //I/O Library
using namespace std;

struct Space{ // Whether if a spot on the board is filled or not
    string value;
};


struct Coordinate{ // Represents a spot on the board
    int x;
    int y;
};
const int ROW = 6; // Number of rows in the Connect 4 game
const int COLUMN = 7; // Number of columns in the Connect 4 game

void initialize(Space[ROW][COLUMN]); // Initializing the game board to where all the spots are empty and creates a board with given number of rows and columns
void printGame(Space[ROW][COLUMN]); // Prints the game board onto the screen
Coordinate playerMove(Space[ROW][COLUMN],string); // Plays and prints to a specific spot on the board according to the player's input
bool gameOver(Space[ROW][COLUMN],Coordinate); // Checks if the game is over by checking win conditions (Horizontal, Vertical, Diagonal Slash and Backslash, and Draw)

int main(int argc, char** argv) {

    Space board[ROW][COLUMN]; // Creates a game board with the designated number of rows and columns
    
    string player1 = "X"; // Creates player1 or Player X
    string player2 = "O"; // Creates player2 or Player O
    
    cout<<"Welcome to Connect 4. There are two players in this game, so let's play!"<<endl; // Prints a welcome message before game starts
    cout<<"This Connect 4 contains two players. The players are player1 or Player X and player2 or Player O."; // Gives info on how many players can play the game and how they are represented when playing the game
    
    initialize(board); // Cleans the board completely, making all spots empty
    printGame(board); // Prints the game board onto the screen
    
    
    
    while(true){ // Using a while loop to check if a player's move resulted in victory
        if(gameOver(board,playerMove(board,player1))){ // Checks if player1's move on the game board resulted in victory
            break; // If victory, the program exits out of the game
        }
        if(gameOver(board,playerMove(board,player2))){ // Checks if player2's move on the game board resulted in victory
            break; // If victory, the program exits out of the game
        }
    }
    
    return 0;   
}
void initialize(Space board[ROW][COLUMN]){ // Initializing the game board to where all the spots are empty and creates a board with given number of rows and columns
    for(int i=0;i<ROW;i++){ // For loop that goes through each row of the game board
	for(int j=0;j<COLUMN;j++){ // For loop that goes through each column of the game board
            board[i][j].value="_"; // Prints an string "_" to each spot on the game board using the nested for loops above
        }  
    }
}

void printGame(Space board[ROW][COLUMN]){ // Prints the game board onto the screen
    for(int i=0;i<COLUMN;i++){ // For loop that loops through the board from COLUMN 0 to COLUMN-1
        cout<<i<<" "; // Prints an empty space for each spot
    }
    cout<<endl; // Prints a newline
    
    for(int i=0;i<ROW;i++){ // For loop that goes through each row of the game board
      for(int j=0;j<COLUMN;j++){ // For loop that goes through each column of the game board
        cout<<board[i][j].value<<" "; // Prints the player's representation of play (X or O) on the chosen spot of the board according to the player's input
      }
      cout<<endl; // Prints a newline
    }
}

Coordinate playerMove(Space board[ROW][COLUMN],string myPlayer){ // Do the flowchart representation of this function
    int playRow = 0;
    int playCol=0;
    Coordinate coord;
    bool found=false;
    
    while(found==false){
        
        cout<<"Player: "<<myPlayer<<". Enter which column to put: (0-"<<COLUMN-1<<")"<<endl;
        cin>>playCol;
        while(playCol>=COLUMN || playCol<0){
           cout<<"Please enter again. Column Number needs to be less than "<<COLUMN<<" and greater than 0."<<endl;
           cin>>playCol;
        }
    
        for(int i=ROW-1;i>=0;i--){        
            if(board[i][playCol].value=="_"){
                found=true;
                playRow=i;
                break;
            }
        }
        if (found==false){
            printGame(board);
            cout<<"Sorry, column "<<playCol<<" is full, please select another column."<<endl<<endl;
        }
    }
    board[playRow][playCol].value=myPlayer;
    printGame(board);  
    coord.x=playRow;
    coord.y=playCol;
    return coord;
    
}

 bool gameOver(Space board[ROW][COLUMN],Coordinate myCoord){
    // Horizontal Win Test
    int counter=0;
    string myPlayer=board[myCoord.x][myCoord.y].value;
    for(int i=0;i<COLUMN;i++){
        if(board[myCoord.x][i].value==myPlayer){
            counter++;
        }
        else{
            counter=0;
        }
        if(counter==4){
            cout<<"Game Over. Player "<<myPlayer<<" has won the game!";
            return true;
        }
    }
    // Vertical Win Test
    counter=0;
    for(int i=0;i<ROW;i++){
        if(board[i][myCoord.y].value==myPlayer){
            counter++;
        }
        else{
            counter=0;
        }
        if(counter==4){
            cout<<"Game Over. Player "<<myPlayer<<" has won the game!";
            return true;
        }
    }
    // Diagonal Win Test
    counter=1;
    Coordinate* newCoord = new Coordinate();
    newCoord->x=myCoord.x;
    newCoord->y=myCoord.y;
    
    //slash
    //up
    newCoord->x=newCoord->x-1;
    newCoord->y=newCoord->y+1;
    while(newCoord->x>=0 && newCoord->y>=0 && newCoord->x<ROW && newCoord->y<COLUMN){
        if(board[newCoord->x][newCoord->y].value!=myPlayer){
            break;
        }else{
            counter++;
            if(counter==4){cout<<"Game Over. Player "<<myPlayer<<" has won the game!";delete newCoord;return true;}
            newCoord->x=newCoord->x-1;
            newCoord->y=newCoord->y+1;
        }
    }
    //down
    newCoord->x=myCoord.x+1;
    newCoord->y=myCoord.y-1;
    while(newCoord->x>=0 && newCoord->y>=0 && newCoord->x<ROW && newCoord->y<COLUMN){
        if(board[newCoord->x][newCoord->y].value!=myPlayer){
            break;
        }else{
            counter++;
            if(counter==4){cout<<"Game Over. Player "<<myPlayer<<" has won the game!";delete newCoord;return true;}
            newCoord->x=newCoord->x+1;
            newCoord->y=newCoord->y-1;
        }
    }
    //backslash
    //up
    newCoord->x=newCoord->x-1;
    newCoord->y=newCoord->y-1;
    while(newCoord->x>=0 && newCoord->y>=0 && newCoord->x<ROW && newCoord->y<COLUMN){
        if(board[newCoord->x][newCoord->y].value!=myPlayer){
            break;
        }else{
            counter++;
            if(counter==4){cout<<"Game Over. Player "<<myPlayer<<" has won the game!";delete newCoord;return true;}
            newCoord->x=newCoord->x-1;
            newCoord->y=newCoord->y-1;
        }
    }
    //down
    newCoord->x=myCoord.x+1;
    newCoord->y=myCoord.y+1;
    while(newCoord->x>=0 && newCoord->y>=0 && newCoord->x<ROW && newCoord->y<COLUMN){
        if(board[newCoord->x][newCoord->y].value!=myPlayer){
            break;
        }else{
            counter++;
            if(counter==4){cout<<"Game Over. Player "<<myPlayer<<" has won the game!";delete newCoord;return true;}
            newCoord->x=newCoord->x+1;
            newCoord->y=newCoord->y+1;
        }
    }
    delete newCoord; // Deallocates the new coordinate after usage
    return false; // Returns false automatically if no victory is in existence
}