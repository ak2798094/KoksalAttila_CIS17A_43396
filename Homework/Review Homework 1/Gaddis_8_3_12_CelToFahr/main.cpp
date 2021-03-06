/* 
 * File:   main.cpp
 * Author: Attila Koksal
 * Created on March 5, 2021, 9:04 PM
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

//Execution Begins Here
int main(int argc, char** argv) {
    //Initialize the Random Number Seed
    
    //Declare Variables
    float Cel, Fahr; //Celsius and Fahrenheit
   
    //Initialize Variables
    cout<<"Input the Celsius (in degrees):"; 
    cin>>Cel;
    cout<<endl;
     //Map Inputs to Outputs -> Process
    Fahr=(9.0/5.0)*Cel+32; //Converts Celsius into Fahrenheit
    
    //Display Inputs/Outputs
    cout<<"Fahrenheit (in degrees):"<<Fahr;
    cout<<endl;
    //Exit the Program - Cleanup
    return 0;
}