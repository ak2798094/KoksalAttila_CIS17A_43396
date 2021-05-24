/* 
 * File:   main.cpp
 * Author: Attila Koksal
 * Created on May 21, 2021, 5:30 PM
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

class TimeOff{
private:
    string name;
    string IDnum;
    NumDays maxSickDays,sickTaken,maxVacation,vacTaken,maxUnpaid,unpaidTaken;

public:
    TimeOff(string n="", string id=""){
        name=n;
        IDnum=id;
    }
    string getName()const{
        return name;
    }
    string getID()const{
        return IDnum;
    }
    float getMaxSickDays(){
        return maxSickDays.getDays();
    }
    float getSickTaken(){
        return sickTaken.getDays();
    }
    float getMaxVacation(){
        return maxVacation.getDays();
    }
    float getVacTaken(){
        return vacTaken.getDays();
    }
    float getMaxUnpaid(){
        return maxUnpaid.getDays();
    }
    float getUnpaidTaken(){
        return unpaidTaken.getDays();
    }

    //-------------------------------------------------

    void setName(string n){
        name=n;
    }
    void setID(string id){
        IDnum=id;
    }
    void setMaxSickDays(float h){
        maxSickDays.setHours(h);
    }
    void setSickTaken(float h){
        sickTaken.setHours(h);
    }
    void setMaxVacation(float h){
        if(h>240){
            maxVacation.setHours(240);
        }
        else{
            maxVacation.setHours(h);
        }
    }
    void setVacTaken(float h){
        vacTaken.setHours(h);
    }
    void setMaxUnpaid(float h){
        maxUnpaid.setHours(h);
    }
    void setUnpaidTaken(float h){
        unpaidTaken.setHours(h);
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
    
    //Exit the Program - Cleanup
    return 0;
}