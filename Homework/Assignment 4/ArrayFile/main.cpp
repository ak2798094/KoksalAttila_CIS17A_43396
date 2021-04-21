/* 
 * File:   main.cpp
 * Author: Attila Koksal
 * Created on April 20, 2021, 9:05 PM
 * Purpose:  CPP Template 
 *           To be copied for each Assignment Problem
 */

//System Libraries
#include <iostream>  //I/O Library
#include <fstream>
using namespace std;

//User Libraries

//Global Constants
const int arraySize=10;
const int nameSize=20;

//Math, Science, Universal, Conversions, High Dimensioned Arrays

//Function Prototypes
void arrayToFile(char[],int[],int);
void fileToArray(char[],int[],int);

//Execution Begins Here
int main(int argc, char** argv) {
    //Initialize the Random Number Seed
    
    //Declare Variables
    int array[]={1,2,3,4,5,6,7,8,9,10};
    int array2[arraySize];
    int* pointer1;
    int* pointer2;
    pointer1=array;
    pointer2=array2;
    char fileName[nameSize];

    //Initialize Variables
    
    //Map Inputs to Outputs -> Process
    
    //Display Inputs/Outputs
    cout<<"Enter the file name:"<<endl;
    cin.getline(fileName,nameSize);
    arrayToFile(fileName,pointer1,arraySize);
    fileToArray(fileName,pointer2,arraySize);
    for(int count=0;count<arraySize;count++){
        cout<<pointer1[count]<<" ";
    }
    
    //Exit the Program - Cleanup
    return 0;
}
void arrayToFile(char file[],int pointer[],int arrSize){
    fstream dataFile;
    dataFile.open(file,ios::in|ios::binary);
    for(int count=0;count<arrSize;count++){
        dataFile.write(reinterpret_cast<char *>(pointer), sizeof(pointer));
    }
    dataFile.close();
}
void fileToArray(char file[],int pointer[],int arrSize){
    fstream dataFile;
    dataFile.open(file,ios::out|ios::binary);
    for(int count=0;count<arrSize;count++){
        dataFile.read(reinterpret_cast<char *>(pointer), sizeof(pointer));
    }
    dataFile.close();
}