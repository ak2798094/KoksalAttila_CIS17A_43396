/* 
 * File:   main.cpp
 * Author: Attila Koksal
 * Created on April 4, 2021, 12:10 PM
 * Purpose:  CPP Template 
 *           To be copied for each Assignment Problem
 */

//System Libraries
#include <iostream>  //I/O Library
using namespace std;

struct Speaker{
    string name;
    string phone;
    string topic;
    float fee;
};

//User Libraries

//Global Constants
//Math, Science, Universal, Conversions, High Dimensioned Arrays

//Function Prototypes
void Get(Speaker *);
void Print(Speaker *);
void Edit(Speaker *);

//Execution Begins Here
int main(int argc, char** argv) {
    //Initialize the Random Number Seed
    
    //Declare Variables
    Speaker spkr[10];
    int menu;
    
    //Initialize Variables
    int numSpeak=10;
    const int enter=1,change=2,print=3,leave=4;
    
    //Map Inputs to Outputs -> Process
    
    //Display Inputs/Outputs
    do{
        cout<<"Please select one of the following from this menu."<<endl;
        cout<<"1) Enter Speaker Information."<<endl;
        cout<<"2) Change Speaker Information."<<endl;
        cout<<"3) Print Speaker Information."<<endl;
        cout<<"4) Leave menu."<<endl;
        cout<<"Selection: ";
        cin>>menu;
        
        switch(menu){
            case enter:{
                Get(spkr);
            }
            break;
            case change:{
                Edit(spkr);
            }
            break;
            case print:{
                Print(spkr);
            }
            break;
        }
    }
    while(menu!=leave);
    
    //Exit the Program - Cleanup
    return 0;
}
void Get(Speaker *speaker){
    int counter=0;
    int size=10;
    for(int counter;i<size;i++){
        cout<<"Enter the information for Speaker"<<i<<":"<<endl;
        cout<<"Speaker Name:";
        cin.ignore();
        getline(cin,speaker[counter].name);
        cout<<"Speaker Phone Number:";
        getline(cin,speaker[counter].phone);
        cout<<"Speaker Topic:";
        getline(cin,speaker[counter].topic);
        cout<<"Fee Required:";
        cin>>speaker[counter].fee;
    }
}
