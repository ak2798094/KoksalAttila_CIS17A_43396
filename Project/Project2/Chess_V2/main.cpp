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
    bool operator==(const Coordinate& other)const{
        return (x==other.x&&y==other.y);
    }
};

class Game{
private:
    string player1="";
    string player2="";
public:
    void announceWinner(int winner){
        string winnerName="";
        if(winner==0){
            winnerName=player1;
        }
        else{
            winnerName=player2;
        }
        cout<<"Congratulations, the winner is "<<winnerName<<endl;
    }
    void setPlayerName(int playerNumber,string name){
        if(playerNumber==0){
            player1=name;
        }
        else if(playerNumber==1){
            player2=name;
        }
    }
    string getPlayerName(int playerNumber){
        if(playerNumber==0){
            return player1;
        }
        else if(playerNumber==1){
            return player2;
        }
    }
};

class Board:public Game{
    Space board[ROW][COLUMN];
    Color turn=WHITE;
    
public:
    void initializeBoard();
    Space* getSpace(Coordinate);
    void movePiece(Color);
    void printBoard();
    void setPiece(Coordinate,Piece,Color);
    void searchAndAdd(Coordinate[],int &,Coordinate,int,int);
    void announceWinner(int winner){
        string winnerName="";
        string player1=getPlayerName(0);
        string player2=getPlayerName(1);
        string color="";
        
        if(winner==0){
            winnerName=player1;
            color="WHITE";
        }
        else{
            winnerName=player2;
            color="BLACK";
        }
        cout<<"Congratulations! The winner is "<<winnerName<<", who is playing the color "<<color<<"."<<endl;
    }
    
};


int main(int argc, char** argv) {

    Board board;
    
    board.initializeBoard();
    board.printBoard();
    cout<<endl;
    while(true){
        board.movePiece(WHITE);

        board.movePiece(BLACK);

    }
    cout<<endl;

    
}

void Board::initializeBoard(){
    
    string player1="";
    string player2="";
    cout<<"Welcome to the amazing Chess game! You're in for a treat!"<<endl;
    cout<<"Enter a player display name for the WHITE piece: ";
    cin>>player1;
    cout<<endl;
    cout<<"Enter a player display name for the BLACK piece: ";
    cin>>player2;
    cout<<endl;
    
    setPlayerName(0,player1);
    setPlayerName(1,player2);
    announceWinner(0);
    
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
    setPiece({0,3},Queen,WHITE);
    setPiece({0,4},King,WHITE);
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
    setPiece({7,3},Queen,BLACK);
    setPiece({7,4},King,BLACK);
    setPiece({7,5},Bishop,BLACK);
    setPiece({7,6},Knight,BLACK);
    setPiece({7,7},Rook,BLACK);
 
    
}
void Board::printBoard(){
    cout<<"-----------------------------------------------------------------------------"<<endl;
    for(int i=ROW-1;i>=0;i--){
        cout<<i+1<<" ";
        for(int j=0;j<COLUMN;j++){
            cout<<setw(10);
            string pieceString=pieceNames[getSpace({i,j})->getValue()];
            if(getSpace({i,j})->getColor()==WHITE){
                for(auto& x:pieceString){
                    x=toupper(x);
                }
            }
            cout<<pieceString<<" ";
            
        }
        cout<<endl;
    }
    char letters[8]={'A','B','C','D','E','F','G','H'};
    for(int i=0;i<COLUMN;i++){
        cout<<setw(10);
        cout<<letters[i]<<" "; // cheesy if elses here dude
    }
    cout<<endl;
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
    bool valid=false;
    char letter;
    Space* startSpace=new Space();
    Space* endSpace=new Space();
    Coordinate start;
    Coordinate end;
    Piece startPiece;
    while(!valid){
        cout<<endl;
        string colorString="";
        if(myColor==WHITE){
            colorString="WHITE";
        }
        else if(myColor==BLACK){
            colorString="BLACK";
        }
        cout<<"Player "<<colorString<<", enter which piece to move (enter row and column with space in between i.e (E 2))";
        cin>>letter;
        cin>>start.x;
        start.x--;
        start.y=tolower(letter)-'a';

        cout<<"Player "<<colorString<<", enter where to move to (enter row and column with space in between i.e (E 3))";
        cin>>letter;
        cin>>end.x;
        end.x--;
        end.y=tolower(letter)-'a';

        startSpace=getSpace(start);
        endSpace=getSpace(end);
        startPiece=startSpace->getValue();
        
        if(endSpace->getColor()==myColor){
            cout<<"how can you move there if there is already a piece there of yours";
            continue;
        }
        if(startSpace->getColor()!=myColor){
            cout<<"Sorry you can only move your piece"<<endl;
            continue;
        }
        
        Coordinate ableToMove[64];
        int size=0;
        if(startPiece==Pawn){

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
            Coordinate firstCheck={start.x+offset,start.y};
            Coordinate secondCheck={start.x+(offset*2),start.y};
            if(getSpace(firstCheck)->getValue()==Empty&&getSpace(secondCheck)->getValue()==Empty){
                if((getSpace(start)->getColor()==WHITE&&start.x==1)||(getSpace(start)->getColor()==BLACK&&start.x==6)){
                    ableToMove[size]=secondCheck;
                    size++;
                }
            }
        }
        else if(startPiece==Rook){
            searchAndAdd(ableToMove,size,start,1,0); // up
            searchAndAdd(ableToMove,size,start,0,1); // right
            searchAndAdd(ableToMove,size,start,0,-1); // left
            searchAndAdd(ableToMove,size,start,-1,0); // down
        }
        else if(startPiece==Bishop){
            searchAndAdd(ableToMove,size,start,1,1); // up right
            searchAndAdd(ableToMove,size,start,-1,-1); // bottom left
            searchAndAdd(ableToMove,size,start,1,-1); // up left
            searchAndAdd(ableToMove,size,start,-1,1); // bottom right
        }
        else if(startPiece==Knight){
            int availablePos[][2]={{1,2},{2,1},{-2,1},{-2,-1},{-1,2},{2,-1},{-1,-2},{1,-2}};
            for(int i=0;i<8;i++){
                Coordinate usedToCheck={start.x+availablePos[i][0],start.y+availablePos[i][1]};
                if(usedToCheck.x<ROW&&usedToCheck.y<COLUMN&&usedToCheck.x>=0&&usedToCheck.y>=0){
                    if(getSpace(usedToCheck)->getColor()!=myColor){
                        ableToMove[size]=usedToCheck;
                        size++;
                    }
                }
            }
        }
        else if(startPiece==Queen){
            searchAndAdd(ableToMove,size,start,1,0); // up
            searchAndAdd(ableToMove,size,start,0,1); // right
            searchAndAdd(ableToMove,size,start,0,-1); // left
            searchAndAdd(ableToMove,size,start,-1,0); // down
            searchAndAdd(ableToMove,size,start,1,1); // up right
            searchAndAdd(ableToMove,size,start,-1,-1); // bottom left
            searchAndAdd(ableToMove,size,start,1,-1); // up left
            searchAndAdd(ableToMove,size,start,-1,1); // bottom right
        }
        else if(startPiece==King){
            
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
            valid=true;
        }
        else{
            cout<<"Sorry you cannot move to that location."<<endl;
            continue;
        }
        Board::printBoard();
    }
}
void Board::searchAndAdd(Coordinate arr[],int &size,Coordinate startCoord,int xd,int yd){
    Coordinate currentCoord=startCoord;
    Color playerColor=getSpace(startCoord)->getColor();
    currentCoord.x+=xd;
    currentCoord.y+=yd;
    while(currentCoord.x<ROW&&currentCoord.y<COLUMN&&currentCoord.x>=0&&currentCoord.y>=0){
        if(getSpace(currentCoord)->getValue()==Empty){
            arr[size]=currentCoord;
            cout<<"I have added."<<arr[size].x<<":"<<arr[size].y<<endl;
            size++;
        }
        else if(getSpace(currentCoord)->getColor()!=playerColor&&getSpace(currentCoord)->getColor()!=NONE){
            arr[size]=currentCoord;
            cout<<"I have added.2"<<arr[size].x<<":"<<arr[size].y<<endl;
            size++;
            break;
        }
        else if(getSpace(currentCoord)->getColor()==playerColor){
            break;
        }
        currentCoord.x+=xd;
        currentCoord.y+=yd;
    }
}