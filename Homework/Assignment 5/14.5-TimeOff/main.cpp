/* 
 * File:   main.cpp
 * Author: Attila Koksal
 * Created on May 21, 2021, 5:30 PM
 * Purpose:  CPP Template 
 *           To be copied for each Assignment Problem
 */

//System Libraries
#include <iostream>  //I/O Library
#include "NumDays.h" // NumDays class file
using namespace std;

class NumDays;

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
#endif
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