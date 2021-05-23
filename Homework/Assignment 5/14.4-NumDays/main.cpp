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
    float hours;
    float days;
public:
    NumDays(float h=0){
        hours=h;
        days=h/(8.00);
    }
    float getHours(){
        return hours;
    }
    float getDays(){
        return days;
    }
    void setHours(float h){
        hours=h;
        days=h/(8.00);
    }
    void setDays(float d){
        days=d;
        hours=d*(8.00);
    }
    float operator+(const NumDays &right){
        return hours+right.hours;
    }
    float operator-(const NumDays &right){
        if(hours<right.hours){
            cout<<"Error! Can't solve. Exiting";
            exit(0);
        }
        return hours-right.hours;
    }
    NumDays operator++(){
        ++hours;
        days=hours/(8.00);
        return *this;
    }
    NumDays operator++(int){
        hours++;
        days=hours/(8.00);
        return *this;
    }
    NumDays operator--(){
        --hours;
        days=hours/(8.00);
        return *this;
    }
    NumDays operator--(int){
        hours--;
        days=hours/(8.00);
        return *this;
    }
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
    //create first test
    cout<<"Creating test with 12 hours..."<<endl;
    NumDays test1(12);
    cout<<test1.getHours()<<" hours = "<<test1.getDays()<<" days."<<endl;

    //create second test
    cout<<endl<<"Creating test with 18 hours..."<<endl;
    NumDays test2(18);
    cout<<test2.getHours()<<" hours = "<<test2.getDays()<<" days."<<endl;

    //test overloaded + operator
    cout<<endl<<"Adding hours... "<<test1+test2<<" hours."<<endl;

    //test overloaded - operator
    cout<<endl<<"Subtracting hours... "<<test2-test1<<" hours."<<endl<<endl;

    //test overloaded ++ operators
    cout<<"Pre- and post-incrementing first test..."<<endl;
    ++test1;
    cout<<test1.getHours()<<" hours = "<<test1.getDays()<<" days."<<endl;
    test1++;
    cout<<test1.getHours()<<" hours = "<<test1.getDays()<<" days."<<endl;

    //test overloaded -- operators
    cout<<endl<<"Pre- and post-decrementing second test..."<<endl;
    --test2;
    cout<<test2.getHours()<<" hours = "<<test2.getDays()<<" days."<<endl;
    test2--;
    cout<<test2.getHours()<<" hours = "<<test2.getDays()<<" days."<<endl;
    
    //Exit the Program - Cleanup
    return 0;
}