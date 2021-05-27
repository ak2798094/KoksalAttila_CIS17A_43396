/* 
 * File:   main.cpp
 * Author: Attila Koksal
 * Created on May 26, 2021, 8:51 PM
 * Purpose:  CPP Template 
 *           To be copied for each Assignment Problem
 */

//System Libraries
#include <iostream>  //I/O Library
using namespace std;

enum Piece{//Piece represents all possible values of a spot on a board can be, in traditional board, its spot can be either red or yellow, or empty. Here we use X and O to represent yellow and empty
    Pawn,
    Rook,
    Bishop,
    Knight,
    Queen,
    King,
    Empty
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
    void setValue(Piece);
    
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
    Piece getPiece(Coordinate);
    void movePiece(Coordinate,Coordinate);
    void printBoard();
    void setPiece();
};

const int ROW = 8;
const int COLUMN = 8;

int main(int argc, char** argv) {
    
    Board board;
    
    board.initializeBoard();
    
    
    
}

void Board::initializeBoard(){
    
}