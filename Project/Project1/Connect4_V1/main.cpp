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


struct Coordinate{
    int x;
    int y;
};
const int ROW = 6;
const int COLUMN = 7;

void initialize(Space board[ROW][COLUMN]){
    for(int i=0;i<ROW;i++){
	for(int j=0;j<COLUMN;j++){		
            board[i][j].value="_";
        }  
    }
}

void printGame(Space board[ROW][COLUMN]){
    
    for(int i=0;i<COLUMN;i++){
        cout<<i<<" ";
    }
    cout<<endl;
    
    for(int i=0;i<ROW;i++){
      for(int j=0;j<COLUMN;j++){
        cout<<board[i][j].value<<" ";
      }
      cout<<endl;
    }
}

void playerMove(Space board[ROW][COLUMN],string myPlayer){
    int playRow = 0;
    int playCol=0;
    cout<<"Player: "<<myPlayer<<". Enter which column to put: (0-"<<COLUMN-1<<")"<<endl;
    cin>>playCol;
    while(playCol>=COLUMN || playCol<0){
        cout<<"Please enter again. Column Number needs to be less than "<<COLUMN<<" and greater than 0."<<endl;
        cin>>playCol;
    }
    board[playRow][playCol].value=myPlayer;
    printGame(board);
}

int main(int argc, char** argv) {

    Space board[ROW][COLUMN]; 
    
    
    string player1 = "X";
    string player2 = "O";
    
    initialize(board);
    printGame(board);
    
    while(true){
    playerMove(board,player1);
    playerMove(board,player2);

    }
    
    return 0;   
}

 bool gameOver(Space board[ROW][COLUMN],Coordinate myCoord){
     return false;

}












