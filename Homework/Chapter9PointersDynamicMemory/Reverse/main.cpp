  
/* 
 * File:   main.cpp
 * Author: Attila Koksal
 * Created on March 27, 2021, 3:35 PM
 * Purpose:  CPP Template 
 *           To be copied for each Assignment Problem
 */

//System Libraries
#include <iostream>  //I/O Library
#include <algorithm>
using namespace std;

//User Libraries

//Global Constants
//Math, Science, Universal, Conversions, High Dimensioned Arrays

//Function Prototypes
int *getData(int &);            //Fill the array
int *sort(const int *,int);     //Sort smallest to largest
int *reverse(const int *,int); //Sort in reverse order
void prntDat(const int *,int); //Print the array

//Execution Begins Here
int main(int argc, char** argv) {
    //Initialize the Random Number Seed
    
    //Declare Variables
    int size;
    int* input;
    int* sorted;
    int* reversed;
    //Initialize Variables
    cin>>size;
    input=getData(size);
    sorted=sort(input,size);
    reversed=reverse(sorted,size);
    
    //Map Inputs to Outputs -> Process
    
    //Display Inputs/Outputs
    prntDat(sorted,size);
    cout<<endl;
    prntDat(reversed,size);
		
    delete[]input;
    delete[]sorted;
    delete[]reversed;
	
    input = NULL;
    sorted=NULL;
    reversed=NULL;
    
    //Exit the Program - Cleanup
    return 0;
}
int *getData(int &size){ //Fill the array
    int* arr=new int[size];
    int i=0;
    while(cin>>arr[i]){
        i++;
    }
    if (i!=size){size=i;}
    return arr;
}

int *sort(const int *arr,int size){ //Sort smallest to largest
      int* sorted=new int[size];
      for(int i=0;i<size;i++){
          sorted[i]=arr[i];
      }
      sort(sorted,sorted+size);
    
    return sorted;
}

int *reverse(const int *arr,int size){ //Sort in reverse order
      int* reversed=new int[size];
      for(int i=size-1;i>=0;i--){
          reversed[i]=arr[(size-1)-i];
      }
    return reversed;
}

void prntDat(const int *arr,int size){ //Print the array
    if(size>0){cout<<arr[0];}
    for(int i=1;i<size;i++){
          cout<<" "<<arr[i];
    }
      
}    