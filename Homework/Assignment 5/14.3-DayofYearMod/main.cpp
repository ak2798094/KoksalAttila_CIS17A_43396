/* 
 * File:   main.cpp
 * Author: Attila Koksal
 * Created on May 21, 2021, 12:45 PM
 * Purpose:  CPP Template 
 *           To be copied for each Assignment Problem
 */

//System Libraries
#include <iostream>  //I/O Library
using namespace std;

class DayofYear{
private:
    int day=0;
    static string months[12];
    static int numberOfDays[12];
    int month=0;
public:
    DayofYear(int d){
        if(d<1||d>365){
            cout<<"Error! Can't accept this number. Exiting."<<endl;
            exit(0);
        }
        else{
            day=d;
        }
    }
    DayofYear(string m,int d){
        int counter;
        for(counter=0;counter<12;counter++){
            if(m==months[counter]){
                break;
            }
            if(counter==11){
                cout<<"Month input error! "<<m<<" doesn't exist! Exiting."<<endl;
                exit(0);
            }
        }
        if(d<1||d>numberOfDays[counter]){
            cout<<"Day number input error! "<<m<<" doesn't exist! Exiting."<<endl;
            exit(0);
        }
        if(counter==0){
            day+=d;
        }
        else{
            while(counter>=0){
                day+=numberOfDays[--counter];
            }
            day+=d;
        }
    }
    DayofYear operator++(){
        if(day==365){
            day=1;
        }
        else{
            ++day;
        }
        return *this;
    }
    DayofYear operator++(int){
        if(day==365){
            day=1;
        }
        else{
            day++;
        }
        return *this;
    }
    DayofYear operator--(){
        if(day==1){
            day=365;
        }
        else{
            --day;
        }
        return *this;
    }
    DayofYear operator--(int){
        if(day==1){
            day=365;
        }
        else{
            day--;
        }
        return *this;
    }
    void print(){
        int d=day;
        for(int counter=0;counter<12;counter++){
            if(d<=numberOfDays[counter]){
                break;
            }
            else{
                d-=numberOfDays[counter];
                month++;
            }
        }
        cout<<months[month]<<" "<<d<<endl;
        month=0;
    }
};

string DayofYear::months[12]={"January","February","March","April","May","June","July","August","September","October","November","December"};
int DayofYear::numberOfDays[12]={31,28,31,30,31,30,31,31,30,31,30,31};

//User Libraries

//Global Constants
//Math, Science, Universal, Conversions, High Dimensioned Arrays

//Function Prototypes

//Execution Begins Here
int main(int argc, char** argv) {
    //Initialize the Random Number Seed
    
    //Declare Variables
    int input;
    
    //Initialize Variables
    
    //Map Inputs to Outputs -> Process
    
    //Display Inputs/Outputs
    cout<<"Please enter a number between 1-365: ";
    cin>>input;
    DayofYear test1(input);
    test1.print();
    ++test1;
    test1.print();
    test1++;
    test1.print();
    --test1;
    test1.print();
    test1--;
    test1.print();
    cout<<"----------------"<<endl;
    
    DayofYear test2("December",30);
    test2.print();
    ++test2;
    test2.print();
    test2++;
    test2.print();
    --test2;
    test2.print();
    test2--;
    test2.print();
    
    //Exit the Program - Cleanup
    return 0;
}