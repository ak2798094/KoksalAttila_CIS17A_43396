/* 
 * File:   main.cpp
 * Author: Attila Koksal
 * Created on April 30, 2021, 4:35 PM
 * Purpose:  CPP Template 
 *           To be copied for each Assignment Problem
 */

//System Libraries
#include <iostream>  //I/O Library
#include <fstream>
using namespace std;

//User Libraries

//Global Constants
const int SIZE=81;

//Math, Science, Universal, Conversions, High Dimensioned Arrays

//Function Prototypes

//Execution Begins Here
int main(int argc, char** argv) {
    //Initialize the Random Number Seed
    
    //Declare Variables
    ifstream inFile;
    ofstream outFile;
    char inName[SIZE];
    char outName[SIZE];
    char input;
    
    //Initialize Variables
    
    //Map Inputs to Outputs -> Process
    
    //Display Inputs/Outputs
    cout<<"Enter the input file name: ";
    cin.getline(inName,SIZE);
    inFile.open(inName);
    if(!inFile){
        exit(EXIT_FAILURE);
    }
    cout<<"Enter the output file name: ";
    cin.getline(outName,SIZE);
    outFile.open(outName);
    if(!outFile){
        exit(EXIT_FAILURE);
    }
    
    while(!inFile.eof()){
        inFile.get(input);
        input+=10; //Encryption
        outFile.put(input);
    }
    cout<<"The file has been encrypted."<<endl;
    
    //Exit the Program - Cleanup
    inFile.close();
    outFile.close();
    return 0;
}