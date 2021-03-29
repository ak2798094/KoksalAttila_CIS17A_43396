/* 
 * File:   main.cpp
 * Author: Attila Koksal
 * Created on March 27, 2021, 6:32 PM
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
int *getData(int &);         //Return the array size and the array from the inputs
int *sumAry(const int *,int);//Return the array with successive sums
void prntAry(const int *,int);//Print the array

//Execution Begins Here
int main(int argc, char** argv) {
    //Initialize the Random Number Seed
    
    //Declare Variables
    int size;
    int* input;
    int* sumArr;
    
    //Initialize Variables
    cin>>size;
    input=getData(size);
    sumArr=sumAry(input,size);
    
    //Map Inputs to Outputs -> Process
    
    //Display Inputs/Outputs
    prntAry(input,size);
    cout<<endl;
    prntAry(sumArr,size);
			
    delete[]input;
    delete[]sumArr;
	
    input = NULL;
    sumArr=NULL;
    
    //Exit the Program - Cleanup
    return 0;
}
int *getData(int &size){ //Return the array size and the array from the inputs
    int* arr=new int[size];
    int i=0;
    while(cin>>arr[i]){
        i++;
    }
    if(i!=size){size=i;}
    return arr;
}

int *sumAry(const int *arr,int size){ //Return the array with successive sums
    int cummulator=0;
    int* newArr=new int[size];
    for (int i=0;i<size;i++){
        cummulator=cummulator+ arr[i];
        newArr[i]=cummulator;
    }
    return newArr;
}


void prntAry(const int *arr,int size){ //Print the array
    if(size>0){cout<<arr[0];}

    for(int i=1;i<size;i++){
        cout<<" "<<arr[i];
    }
}
