/* 
 * File:   main.cpp
 * Author: Attila Koksal
 * Created on March 28, 2021, 2:40 PM
 * Purpose:  CPP Template 
 *           To be copied for each Assignment Problem
 */

//System Libraries
#include <iostream>  //I/O Library
using namespace std;

//User Libraries

//Global Constants
//Math, Science, Universal, Conversions, High Dimensioned Arrays

//Function Prototypes
int **getData(int &,int &);//Get the Matrix Data
void printDat(const int * const *,int,int);//Print the Matrix
int **augment(const int * const *,int,int);//Augment the original array
void destroy(int **,int);//Destroy the Matrix, i.e., reallocate memory

//Execution Begins Here
int main(int argc, char** argv) {
    //Initialize the Random Number Seed
    
    //Declare Variables
    int row,col;
    
    //Initialize Variables
    cin>>row;
    cin>>col;	
    int** input=new int*[row];
    int** aug=new int*[row+1];
    input=getData(row,col);
    aug=augment(input, row,col);
    
    //Map Inputs to Outputs -> Process
    
    //Display Inputs/Outputs
    printDat(input,row,col);
    cout<<endl;
    printDat(aug,row+1,col+1);
    destroy(input,row);
    destroy(aug,row+1);
    
    //Exit the Program - Cleanup
    return 0;
}
int **getData(int & row,int & col){ //Get the Matrix Data
  	int** input = new int*[row];
    for(int i=0;i<row;i++){
         input[i] = new int[col];
        for (int j=0;j<col;j++){
            cin>>input[i][j];
        }
    }
    return input;
}

void printDat(const int * const * arr,int row,int col){ //Print the Matrix
    for (int i=0;i<row;i++){
      if (col>0){cout<<arr[i][0];}
        for(int j=1;j<col;j++){
         cout<<" "<<arr[i][j];   
        }
        if (i<row-1){
        cout<<endl;
        }
    }
}

int **augment(const int * const *arr,int row,int col){ //Augment the original array
    int** result=new int*[row+1];
    for(int i =0;i<row+1;i++){
        result[i]=new int[col+1];
    }
    for(int i=0; i<col+1;i++){result[0][i]=0;}
    for(int i=1;i<row+1;i++){
        if(col>0){
        result[i][0]=0;
        }
        for(int j=1;j<col+1;j++){
        result[i][j]=arr[i-1][j-1];
        }
    }
    return result;
}

void destroy(int ** arr,int row){ //Destroy the Matrix, i.e., reallocate memory
  for (int i=0;i<row;i++){
        delete[] arr[i];
        arr[i]=NULL;
    }
    delete[] arr;
    arr=NULL;
}