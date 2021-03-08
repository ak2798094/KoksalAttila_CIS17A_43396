/* 
 * File:   main.cpp
 * Author: Attila Koksal
 * Created on March 7, 2021, 8:55 PM
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
    int populate, //population
       numOfDays; //number of days
    double dailyInc; //daily increase
    
    //Initialize Variables
    cout<<"Please enter the Starting Number of Organisms:"<<endl;
    cin>>populate;
    cout<<endl;
    
    while(populate<2.00){
        cout<<"Starting Number needs to be larger than 2. Please enter the Starting Number of Organisms:"<<endl;
        cin>>populate;
        cout<<endl;
    }
    
    cout<<"Please enter the Average Daily Population Increase (as a percentage):"<<endl;
    cin>>dailyInc;
    cout<<endl;
    
    while(dailyInc<0.00){
        cout<<"Daily Increase Percentage needs to be a positive number. Please enter the Average Daily Population Increase (as a percentage):"<<endl;
        cin>>dailyInc;
        cout<<endl;
    }
    
    cout<<"Please enter the Number of Days they will multiply:"<<endl;
    cin>>numOfDays;
    cout<<endl;
    
    while(numOfDays<1){
        cout<<"Incorrect Input: Number of Days needs to be larger than 1. Please enter the Number of Days they will multiply:"<<endl;
        cin>>numOfDays;
        cout<<endl;
    }
    for(int i=0;i<numOfDays;i++){ //loops for every day until numOfDays
    
    //Map Inputs to Outputs -> Process
        populate=populate+(populate*dailyInc); //computes the total population for each day up till numOfDays
    
    //Display Inputs/Outputs
        cout<<"In Day "<<i+1<<", the population is "<<populate<<"\n";
    }
        
    //Exit the Program - Cleanup
    return 0;
}