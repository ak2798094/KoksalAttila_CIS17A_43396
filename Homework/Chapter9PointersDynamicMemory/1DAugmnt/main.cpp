/* 
 * File:   main.cpp
 * Author: Attila Koksal
 * Created on March 28, 2021, 12:35 PM
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
int *getData(int &);//Read the array
int *augment(const int *,int);//Augment and copy the original array
void prntAry(const int *,int);//Print the array

//Execution Begins Here
int main(int argc, char** argv) {
    //Initialize the Random Number Seed
    
    //Declare Variables
    int size;
    int* input;
    int* aug;
    
    //Initialize Variables
    cin>>size;
    input = getData(size);
    aug=augment(input,size);
    
    //Map Inputs to Outputs -> Process
    
    //Display Inputs/Outputs
    prntAry(input,size);
    cout<<endl;
    prntAry(aug,size+1);
    
    //Exit the Program - Cleanup
    return 0;
}
int *getData(int &size){ //Read the array
    int* input=new int[size];
    for(int i=0;i<size;i++){
        cin>>input[i];
    }
    return input;
}

int *augment(const int *arr,int size){ //Augment and copy the original array
    int* aug=new int[size+1];
    aug[0]=0;
    for (int i=1;i<size+1;i++){
        aug[i]=arr[i-1];
    }
    return aug;
}

void prntAry(const int *arr,int size){ //Print the array
    if (size>0){cout<<arr[0];}
    for (int i=1;i<size;i++){
        cout<<" "<<arr[i];
    }
}