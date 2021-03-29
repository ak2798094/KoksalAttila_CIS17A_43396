/* 
 * File:   main.cpp
 * Author: Attila Koksal
 * Created on March 27, 2021, 12:05 PM
 * Purpose:  CPP Template 
 *           To be copied for each Assignment Problem
 */

//System Libraries
#include <iostream>  //I/O Library
#include <iomanip>   // std::setw
#include <algorithm>
using namespace std;

//User Libraries

//Global Constants
//Math, Science, Universal, Conversions, High Dimensioned Arrays

//Function Prototypes
int *getData(int &);         //Return the array size and the array
void prntDat(int *,int);    //Print the integer array
float *median(int *,int);  //Fill the median Array with the Float array size, the median, and the integer array data
void prntMed(float *);     //Print the median Array

//Execution Begins Here
int main(int argc, char** argv) {
    //Initialize the Random Number Seed
    
    //Declare Variables
    int size;
    int* input;
    float* medianArr;
    //Initialize Variables
    cin>>size;
    input=getData(size);
    medianArr=median(input,size);
    
    //Map Inputs to Outputs -> Process
    
    //Display Inputs/Outputs
    prntDat(input,size);
    prntMed(medianArr);
	
    delete[]input;
    delete[]medianArr;
    input = NULL;
    medianArr=NULL;
    
    //Exit the Program - Cleanup
    return 0;
}
int *getData(int &size){ //Return the array size and the array
    int* arr=new int[size];
 
    int i=0;
    while(cin>>arr[i]){
        i++;
    }
    if(i!=size){size=i;}
    
    return arr;
}       

void prntDat(int *arr,int size){ //Print the integer array
    if(size>0){
    cout<<arr[0];
    }
    for(int i=1;i<size;i++){
        cout<<" "<<arr[i];
    }
    cout<<endl;
}   

float *median(int *arr,int size){ //Fill the median Array with the Float array size, the median, and the integer array data
   bool even=(size%2==0);
   int newSize=size+2;
   int arrStart=0;
   
   float* medArr=new float[newSize];
   
   if(size==0){medArr[0]=0;}
   
   
   float* sorted=new float[size];
   
   medArr[0]=newSize;
 
  for (int i=0;i<size;i++){
      medArr[i+(newSize-size)]=(float) arr[i];
      sorted[i]=(float) arr[i];
  }
  sort(sorted,sorted+size);
  if (even){
      medArr[1]=((float)sorted[(size-1)/2]+(float)sorted[(size-1)/2+1])/2;
  }else{
      medArr[1]=sorted[(size-1)/2];
  }
   return medArr;
}  

void prntMed(float *medArr){ //Print the median Array
    cout<<medArr[0];
    if (medArr[0]==2){
        medArr[1]=0;
    }
    for (int i=1;i<medArr[0];i++){
        cout<<" "<<fixed<<setprecision(2)<<medArr[i];
    }
}     