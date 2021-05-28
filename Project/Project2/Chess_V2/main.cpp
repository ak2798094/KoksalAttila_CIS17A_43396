/* 
 * File:   main.cpp
 * Author: Attila Koksal
 * Created on May 26, 2021, 11:43 PM
 * Purpose:  CPP Template 
 *           To be copied for each Assignment Problem
 */

//System Libraries
#include <iostream>  //I/O Library
#include<iomanip>
#include <valarray>
using namespace std;
const int ROW = 8;
const int COLUMN = 8;
const string pieceNames[7]={"Pawn","Rook","Bishop","Knight","Queen","King","____"};

enum Piece{//Piece represents all possible values of a spot on a board can be, in traditional board, its spot can be either red or yellow, or empty. Here we use X and O to represent yellow and empty
    Pawn=0,
    Rook=1,
    Bishop=2,
    Knight=3,
    Queen=4,
    King=5,
    Empty=6
};

enum Color{
    WHITE,
    BLACK,
    NONE
};


class Space{ // Whether if a spot on the board is filled or not
    Piece value;
    Color color;
    
public:
    Color getColor();
    Piece getValue();
    void setValue(Piece,Color);
    
};

struct Coordinate{
    int x;
    int y;
};

class Board{
    Space board[ROW][COLUMN];
    Color turn=WHITE;
    
public:
    void initializeBoard();
    Space* getSpace(Coordinate);
    void movePiece(Color);
    void printBoard();
    void setPiece(Coordinate,Piece,Color);
    
};




int main(int argc, char** argv) {

    Board board;
    
    board.initializeBoard();
    board.printBoard();
    while(true){
        board.movePiece(WHITE);

        board.movePiece(BLACK);

    }

    
}

void Board::initializeBoard(){
    for(int i=0;i<ROW;i++){
        for(int j=0;j<COLUMN;j++){
            Space defaultSpace;
            defaultSpace.setValue(Empty,NONE);
            board[i][j]=defaultSpace;
        }
    }
    setPiece({0,0},Rook,WHITE);
    setPiece({0,1},Knight,WHITE);
    setPiece({0,2},Bishop,WHITE);
    setPiece({0,3},King,WHITE);
    setPiece({0,4},Queen,WHITE);
    setPiece({0,5},Bishop,WHITE);
    setPiece({0,6},Knight,WHITE);
    setPiece({0,7},Rook,WHITE);
    for(int i=0;i<COLUMN;i++){
        setPiece({1,i},Pawn,WHITE);
        setPiece({6,i},Pawn,BLACK);
        for(int j=2;j<=5;j++){  
            setPiece({j,i},Empty,NONE);
        }
    }
    setPiece({7,0},Rook,BLACK);
    setPiece({7,1},Knight,BLACK);
    setPiece({7,2},Bishop,BLACK);
    setPiece({7,3},King,BLACK);
    setPiece({7,4},Queen,BLACK);
    setPiece({7,5},Bishop,BLACK);
    setPiece({7,6},Knight,BLACK);
    setPiece({7,7},Rook,BLACK);
 
    
}
void Board::printBoard(){
    for(int i=0;i<ROW;i++){
        for(int j=0;j<COLUMN;j++){
            cout<<setw(10);
            cout<<pieceNames[getSpace({i,j})->getValue()]<<" ";
            
        }
        cout<<endl;
    }
}
void Board::setPiece(Coordinate coor,Piece pece,Color clr){
    getSpace(coor)->setValue(pece,clr);
}
Space* Board::getSpace(Coordinate coor){
    return &board[coor.x][coor.y];
}

//-------------SPACE-------------------------------
Piece Space::getValue(){
    return value;
}

Color Space::getColor(){
    return color;
}


void Space::setValue(Piece pece,Color clr){
    value = pece;
    color = clr;

}

void Board::movePiece(Color myColor){
    
    char letter;
    Space* startSpace=new Space();
    Space* endSpace=new Space();
    Coordinate start;
    Coordinate end;
    cout<<"Enter which piece to move (enter row and column with space in between i.e (E 2))";
    cin>>letter;
    cin>>start.x;
    start.x--;
    start.y=tolower(letter)-'a';
    
    cout<<"Enter where to move to (enter row and column with space in between i.e (E 3))";
    cin>>letter;
    cin>>end.x;
    end.x--;
    end.y=tolower(letter)-'a';

    startSpace = getSpace(start);
    endSpace=getSpace(end);
    Piece startPiece = startSpace->getValue();
    
    
    if(endSpace->getColor()==myColor){
        cout<<"how can you move there if there is already a piece there of yours";
    }
    if (startSpace->getColor()!=myColor){
        cout<<"Sorry you can only move your piece"<<endl;
    }
    
    
    
    
    
    Coordinate ableToMove[64];
    int size=0;
      cout<<"Start Piece"<<startPiece;

    if (startPiece==Pawn){
        
        int offset;
        if(startSpace->getColor()==WHITE){
            offset=1;
        }
        else if(startSpace->getColor()==BLACK){
            offset=-1;
        }
        
        if(getSpace({start.x+offset,start.y})->getValue()==Empty){
            ableToMove[size]={start.x+offset,start.y};
            size++;
        }
        if((start.y-1)>0){
            if(getSpace({start.x+offset,start.y-1})->getColor()!=myColor&&getSpace({start.x+offset,start.y-1})->getColor()!=NONE){
                ableToMove[size]={start.x+offset,start.y-1};
                size++;
            }
        }
        if(start.y+1<COLUMN){
            if(getSpace({start.x+offset,start.y+1})->getColor()!=myColor&&getSpace({start.x+offset,start.y+1})->getColor()!=NONE){
                ableToMove[size]={start.x+offset,start.y+1};
                size++;
            }
        }
    }
    else if(startPiece==Rook){
        
    }
    else if(startPiece==Bishop){
        
    }
    else if(startPiece==Knight){
        
    }
    else if(startPiece==Queen){
        
    }
    else if(startPiece==King){
        
    }
    else if(startPiece==Empty){
        
    }
    //----------------------check if valid move
    //end.x end.y

    bool found=false;
    for(int i=0;i<size;i++){
         cout<<"ableToMoveElement"<<ableToMove[i].x<<":"<<ableToMove[i].y<<endl;
        if(ableToMove[i].x==end.x&&ableToMove[i].y==end.y){
            found=true;
            break;
        }
    }
    
    
    if(found){
        endSpace->setValue(startPiece,myColor);
        startSpace->setValue(Empty,NONE);
    }
    Board::printBoard();
}