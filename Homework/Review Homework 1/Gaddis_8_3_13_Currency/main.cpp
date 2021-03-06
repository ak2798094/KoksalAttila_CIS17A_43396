/* 
 * File:   main.cpp
 * Author: Attila Koksal
 * Created on March 5, 2021, 10:22 PM
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
    const float YenPrDlr=98.93; //Amount of Yen per U.S. dollar
    const float EUPrDlr=0.74; //Amount of Euros per U.S. dollar
    float dollar, //dollar amount
          yen, //yen amount
         euro; //euro amount
   
    //Initialize Variables
    cout<<"Input the dollar amount:"; 
    cin>>dollar;
    cout<<endl;
     //Map Inputs to Outputs -> Process
    yen=dollar*YenPrDlr; //U.S. dollar to Yen conversion
    euro=dollar*EUPrDlr; //U.S. dollar to Euro conversion
    
    //Display Inputs/Outputs
    cout<<"Yen Amount:"<<yen;
    cout<<endl;
    cout<<"Euro Amount:"<<euro;
    cout<<endl;
    //Exit the Program - Cleanup
    return 0;
}