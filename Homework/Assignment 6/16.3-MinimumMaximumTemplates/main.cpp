/* 
 * File:   main.cpp
 * Author: Attila Koksal
 * Created on May 27, 2021, 2:40 PM
 * Purpose:  CPP Template 
 *           To be copied for each Assignment Problem
 */

//System Libraries
#include <iostream>  //I/O Library
using namespace std;

template <class T>
T Min(T num1,T num2){
    if(num1<num2){
        return num1;
    }
    else{
        return num2;
    }
}

template <class T>
T Max(T num1,T num2){
    if(num1>num2){
        return num1;
    }
    else{
        return num2;
    }
}

//User Libraries

//Global Constants
//Math, Science, Universal, Conversions, High Dimensioned Arrays

//Function Prototypes

//Execution Begins Here
int main(int argc, char** argv) {
    //Initialize the Random Number Seed
    
    //Declare Variables
    int int1,int2;
    double doub1,doub2;
    string char1,char2;
    
    //Initialize Variables
    
    //Map Inputs to Outputs -> Process
    
    //Display Inputs/Outputs
    cout<<"Enter two integer values with an enter after the first:"<<endl;
    cin>>int1>>int2;
    cout<<"Lesser: "<<Min(int1,int2)<<endl;
    cout<<"Greater: "<<Max(int1,int2)<<endl;
    
    cout<<"Enter two float values with an enter after the first:"<<endl;
    cin>>doub1>>doub2;
    cout<<"Lesser: "<<Min(doub1,doub2)<<endl;
    cout<<"Greater: "<<Max(doub1,doub2)<<endl;
    
    cout<<"Enter two strings values with an enter after the first:"<<endl;
    cin>>char1>>char2; 
    cout<<"Lesser: "<<Min(char1,char2)<<endl;
    cout<<"Greater: "<<Max(char1,char2)<<endl;
    
    //Exit the Program - Cleanup
    return 0;
}