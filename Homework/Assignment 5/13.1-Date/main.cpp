/* 
 * File:   main.cpp
 * Author: Attila Koksal
 * Created on May 20, 2021, 10:45 AM
 * Purpose:  CPP Template 
 *           To be copied for each Assignment Problem
 */

//System Libraries
#include <iostream>  //I/O Library
using namespace std;

class Date{
    int mnth,dy,yr;
public:
    Date(int month=1,int day=1,int year=2000){
        Date::mnth=month;
        Date::dy=day;
        Date::yr=year;
    };
    void Date1();
    void Date2();
    void Date3();
};

string monthName[12]={"January","February","March","April","May","June","July","August","September","October","November","December"};

//User Libraries

//Global Constants
//Math, Science, Universal, Conversions, High Dimensioned Arrays

//Function Prototypes

//Execution Begins Here
int main(int argc, char** argv) {
    //Initialize the Random Number Seed
    
    //Declare Variables
    int mnth,dy,yr;
    //Initialize Variables
    
    //Map Inputs to Outputs -> Process
    
    //Display Inputs/Outputs
    do{
        cout<<"Enter Month: ";
        cin>>mnth;
        if(mnth<1||mnth>12){
            cout<<"Error! Give a number between 1 and 12. Enter again."<<endl;
        }
    }while(mnth<1||mnth>12);
    do{
        cout<<"Enter Day: ";
        cin>>dy;
        if(dy<1||dy>31){
            cout<<"Error! Give a number between 1 and 31. Enter again."<<endl;
        }
    }while(dy<1||dy>31);
    do{
        cout<<"Enter Year: ";
        cin>>yr;
        if(yr<1||yr>3300){
            cout<<"Error! Give a number between 1 and 3300. Enter again."<<endl;
        }
    }while(yr<1||yr>3300);
    cout<<endl;
    
    Date newDate(mnth,dy,yr);
    
    newDate.Date1();
    newDate.Date2();
    newDate.Date3();
    
    //Exit the Program - Cleanup
    return 0;
}
void Date::Date1(){
    cout<<mnth<<"/"<<dy<<"/"<<yr<<endl;
}
void Date::Date2(){
    cout<<monthName[mnth-1]<<" "<<dy<<", "<<yr<<endl;
}
void Date::Date3(){
    cout<<dy<<" "<<monthName[mnth-1]<<" "<<yr<<endl;
}