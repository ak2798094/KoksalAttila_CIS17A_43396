/* 
 * File:   main.cpp
 * Author: Attila Koksal
 * Created on May 27, 2021, 6:55 PM
 * Purpose:  CPP Template 
 *           To be copied for each Assignment Problem
 */

//System Libraries
#include <iostream>  //I/O Library
using namespace std;

template <class T>
T total(T numVal){
    T total=0;
    T userNum;
    for(int count=0;count<numVal;count++){
        cout<<endl;
        cout<<"Enter value "<<count+1<<": ";
        cin>>userNum;
        total+=userNum;
    }
    return total;
}

//User Libraries

//Global Constants
//Math, Science, Universal, Conversions, High Dimensioned Arrays

//Function Prototypes

//Execution Begins Here
int main(int argc, char** argv) {
    //Initialize the Random Number Seed
    
    //Declare Variables
    int intVal=5;		
    double doubVal=4.0;
    
    //Initialize Variables
    
    //Map Inputs to Outputs -> Process
    
    //Display Inputs/Outputs
    cout<<"The total for int values is: "<<total(intVal)<<endl;
    cout<<endl<<"The total for double values is: "<<total(doubVal)<<endl;
    
    //Exit the Program - Cleanup
    return 0;
}