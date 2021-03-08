/* 
 * File:   main.cpp
 * Author: Attila Koksal
 * Created on March 7, 2021, 9:48 PM
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
double fahToCel(double); //creates a function to convert Celsius to Fahrenheit

//Execution Begins Here
int main(int argc, char** argv) {
    //Initialize the Random Number Seed
    
    //Declare Variables
    
    
    //Initialize Variables
    
    
    //Map Inputs to Outputs -> Process
    cout<<"Fahrenheit   Celsius"<<endl;
    cout<<"---------------------"<<endl;
    
    for(int i=0;i<=20;i++){ //Loops until 20
    
    //Display Inputs/Outputs
        cout<<i<<"      "<<fahToCel(i)<<endl; //Displays corresponding Celsius and Fahrenheits
    }
        
    //Exit the Program - Cleanup
    return 0;
}
double fahToCel(double fah){
    return (5.00/9.00)*(fah-32); //Conversion of Fahrenheit to Celsius
}