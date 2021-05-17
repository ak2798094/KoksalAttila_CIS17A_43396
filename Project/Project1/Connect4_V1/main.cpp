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

void initialize(Space[ROW][COLUMN]);
void printGame(Space[ROW][COLUMN]);


int main(int argc, char** argv) {

    Space board[ROW][COLUMN]; 
    
    string player1 = "X";
    string player2 = "O";
    
    cout<<"Welcome to Connect 4. There are two players in this game, so let's play!"<<endl;
    
    initialize(board);
    printGame(board);
    
 
    
    return 0;   
}
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