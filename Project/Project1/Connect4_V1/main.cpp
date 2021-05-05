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



int main(int argc, char** argv) {

    Space board[ROW][COLUMN]; 
		String player1 = "X";
    String player2 = "O";


	 

		initialize(board); do this
    printGame(); do this and this
    X 	playerMove(board,"X"); //maybe
  
  
  
  
		//headsOrTails();  // let user 1 chose heads or tails, then random generate result to chose order;
    
    while(true){
    
      coord1= playerMove(board,player1);      

     if (gameOver(board,coord1)){
        cout<<"Game Over, player"<<player1<<"won";
        break;
      }
	

      coord2= playerMove(board,player2);
       if (gameOver(board,coord2)){cout<<"Game Over, player "<<player2<<"won"; break;}
	


    }
    

    
    
    
    
    return 0;
}

 bool gameOver(Space board[Row][Column],Coordinate myCoord){



  if (myCoordCausedWin){
    return ;
  }else{
    return xxxx.
  }

}





void initialize(Space board[ROW][COLUMN]){
    for(int i=0;i<ROW;i++){
	for(int j=0;j<COLUMN;j++){		
            board[i][j].value = " ";
        }  
    }
}






XXX playerMove(){

cout<<enter which column to put;



printGame();

}



