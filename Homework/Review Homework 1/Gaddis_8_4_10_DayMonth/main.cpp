/* 
 * File:   main.cpp
 * Author: Attila Koksal
 * Created on March 5, 2021, 10:56 PM
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
    int day, //day
        month, //month
       year; //year
    int dInMonth[12]={31,28,31,30,31,30,31,31,30,31,30,31}; //Array of number of days in each month in order, Feb defaulted as common year (28 days)
    
    //Initialize Variables
    cout<<"Enter the month (1-12):"; 
    cin>>month;
    cout<<endl;
    
    while (month>12 || month<1){ //Checks for incorrect input for month
        cout<<"Incorrect Input Range, Enter the month (1-12):"; 
        cin>>month;
        cout<<endl;
    }
    cout<<"Enter a year:"; 
    cin>>year;
    cout<<endl;
    
     //Map Inputs to Outputs -> Process
    if(year%100==0){ //Detects if a leap year exists
        if(year%400==0){
        dInMonth[1]=29;
        }
    }else{
        if(year%4==0){
        dInMonth[1]=29;
        }
    }
    day = dInMonth[month-1]; //Set day to corresponding number of days in the particular month
    
    //Display Inputs/Outputs
    cout<<day<<" days";
    cout<<endl;
    
    //Exit the Program - Cleanup
    return 0;
}