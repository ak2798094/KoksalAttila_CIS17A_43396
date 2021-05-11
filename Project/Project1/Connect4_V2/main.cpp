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

Coordinate playerMove(Space board[ROW][COLUMN],string myPlayer){
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
    
    
    return false;

}
int main(int argc, char** argv) {

    Space board[ROW][COLUMN]; 
    
    string player1 = "X";
    string player2 = "O";
    
    cout<<"Welcome to Connect 4. There are two players in this game, so let's play!"<<endl;
    
    initialize(board);
    printGame(board);
    
    
    
    while(true){
        if(gameOver(board,playerMove(board,player1))){
            break;
        }
        if(gameOver(board,playerMove(board,player2))){
            break;
        }
    }
    
    return 0;   
}