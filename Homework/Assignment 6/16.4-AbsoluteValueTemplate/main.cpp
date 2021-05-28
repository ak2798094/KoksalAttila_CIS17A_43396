/* 
 * File:   main.cpp
 * Author: Attila Koksal
 * Created on May 27, 2021, 4:50 PM
 * Purpose:  CPP Template 
 *           To be copied for each Assignment Problem
 */

//System Libraries
#include <iostream>  //I/O Library
#include <cmath> //Math Library
using namespace std;

template <class T>
T absolute(T v){
    return abs(v);
}

//User Libraries

//Global Constants
//Math, Science, Universal, Conversions, High Dimensioned Arrays

//Function Prototypes

//Execution Begins Here
int main(int argc, char** argv) {
    //Initialize the Random Number Seed
    
    //Declare Variables
    int input1;
    double input2;
    long input3;
    
    //Initialize Variables
    
    //Map Inputs to Outputs -> Process
    
    //Display Inputs/Outputs
    cout<<"Enter an value and this program will return its absolute value."<<endl;
    cout<<"Enter integer value: ";
    cin>>input1;
    cout<<"Absolute value: "<<absolute(input1)<<endl;
    cout<<"Enter double value: ";
    cin>>input2;
    cout<<"Absolute value: "<<absolute(input2)<<endl;
    cout<<"Enter long value: ";
    cin>>input3;
    cout<<"Absolute value: "<<absolute(input3)<<endl;

    //Exit the Program - Cleanup
    return 0;
}