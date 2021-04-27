/* 
 * File:   main.cpp
 * Author: Attila Koksal
 * Created on April 25, 2021, 9:30 AM
 * Purpose:  Problem 5
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
    unsigned int number;
    int factor=1;
    
    //Initialize Variables
    
    //Map Inputs to Outputs -> Process
    
    //Display Inputs/Outputs
    cout<<"Enter a positive number for the factorial: ";
    cin>>number;
    if(number<0){
        cout<<"The number can't be negative. Please enter a positive number: ";
        cin>>number;
    }
    for(int i=number;i>=1;i--){
        factor=factor*i;
    }
    cout<<"Factorial = "<<factor;
    cout<<endl;
    
    //Exit the Program - Cleanup
    return 0;
}