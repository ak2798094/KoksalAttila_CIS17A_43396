  /* 
 * File:   main.cpp
 * Author: Attila Koksal
 * Created on May 21, 2021, 2:30 PM
 * Purpose:  CPP Template 
 *           To be copied for each Assignment Problem
 */

//System Libraries
#include <iostream>  //I/O Library
using namespace std;

class NumDays{
private:
    int hours;
    float days;
public:
    NumDays(){
        hours=0;
        days=hours/8.0;
    }
    NumDays(int a){
        hours=a;
        days=hours/8.0;
    }
    void setHours(int);
    int getHour()const{return hours;}
    float getDay()const{return days;}
    int operator+(NumDays &);
    int operator-(NumDays &);
    int operator++(int);
    int operator++();
    int operator--(int);
    int operator--();
};

//User Libraries

//Global Constants
//Math, Science, Universal, Conversions, High Dimensioned Arrays

//Function Prototypes

//Execution Begins Here
int main(int argc, char** argv) {
    //Initialize the Random Number Seed
    
    //Declare Variables
    
    //Initialize Variables
    
    //Map Inputs to Outputs -> Process
    
    //Display Inputs/Outputs
    
    //Exit the Program - Cleanup
    return 0;
}
void NumDays::setHours(int a){
    hours=a;
}
int NumDays::operator+(NumDays &right){
    int totalHours;
    totalHours=hours+right.hours;
    return totalHours;
}
int NumDays::operator-(NumDays &right){
    int totalHours;
    totalHours=hours-right.hours;
    return totalHours;
}
int NumDays::operator++(int){
    int num=hours;
    hours++;
    days=hours/8.0;
    return num;
}
int NumDays::operator++(){
    hours++;
    days=hours/8.0;
    return hours;
}
int NumDays::operator--(int){
    int num=hours;
    hours--;
    days=hours/8.0;
    return num;
}
int NumDays::operator--(){
    hours--;
    days=hours/8.0;
    return hours;
}