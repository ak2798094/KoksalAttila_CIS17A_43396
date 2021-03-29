/* 
 * File:   main.cpp
 * Author: Attila Koksal
 * Created on March 28, 2021, 10:30 AM
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
int **getData(int &,int &);        //Return the 2-D array and its size.
void prntDat(const int* const *,int,int);//Print the 2-D Array
void destroy(int **,int,int);       //Deallocate memory
int sum(const int * const *, int,int);    //Return the Sum

//Execution Begins Here
int main(int argc, char** argv) {
    //Initialize the Random Number Seed
    
    //Declare Variables
    int row,col;
    
    //Initialize Variables
    cin>>row;
    cin>>col;
    int** input=new int*[row];
    input=getData(row,col);
    
    //Map Inputs to Outputs -> Process
    
    //Display Inputs/Outputs
    prntDat(input,row,col);
    cout<<sum(input,row,col);
    destroy(input,row,col);
    
    //Exit the Program - Cleanup
    return 0;
}
int **getData(int &row,int &col){ //Return the 2-D array and its size.
    int** input=new int*[row];
    for(int i=0;i<row;i++){
        int *rowArr=new int[col];
        for (int j=0;j<col;j++){
            cin>>rowArr[j];
        }
        input[i]=rowArr;
    }
    return input;
}

void prntDat(const int* const * arr,int row,int col){ //Print the 2-D Array
    for(int i=0;i<row;i++){
        if(col>0){cout<<arr[i][0];}
        for(int j=1;j<col;j++){
         cout<<" "<<arr[i][j];   
        }
        cout<<endl;
    }
}

void destroy(int **arr,int row,int col){ //Deallocate memory
    for (int i=0;i<row;i++){
        delete[] arr[i];
        arr[i]=NULL;
    }
    delete[] arr;
    arr = NULL;
}

int sum(const int * const * arr, int row,int col){ //Return the Sum
    int cummulator=0;
    for(int i=0;i<row;i++){
        for(int j=0;j<col;j++){
            cummulator=cummulator+arr[i][j];        
        }
    }
    return cummulator;
}    