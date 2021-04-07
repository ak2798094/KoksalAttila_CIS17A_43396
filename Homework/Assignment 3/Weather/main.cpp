/* 
 * File:   main.cpp
 * Author: Attila Koksal
 * Created on April 3, 2021, 4:30 PM
 * Purpose:  CPP Template 
 *           To be copied for each Assignment Problem
 */

//System Libraries
#include <iostream>  //I/O Library
#include <iomanip>
using namespace std;

struct Weather{
    string month;
    float rainfall;
    float lowTemp;
    float highTemp;
    float avgTemp;
};

//User Libraries

//Global Constants
//Math, Science, Universal, Conversions, High Dimensioned Arrays

//Function Prototypes

//Execution Begins Here
int main(int argc, char** argv) {
    //Initialize the Random Number Seed
    
    //Declare Variables
    Weather months[12];
    int totalRain=0;
    float avgRain=0;
    int lowest=months[0].lowTemp;
    string lowMnth=months[0].month;
    int highest=months[0].highTemp;
    string highMnth=months[0].month;
    int totalAvg=0;
    float avgTotal=0;
    
    //Initialize Variables
    for(int i=0;i<12;i++){ //read in the inputs
        cin>>months[i].month;
        cin>>months[i].rainfall;
        cin>>months[i].lowTemp;
        while (months[i].lowTemp<-100||months[i].lowTemp>140){
            cout<<"Invalid input, please try again."<<endl;
            cin>>months[i].lowTemp;
        }
        cin>>months[i].highTemp;
        while (months[i].highTemp<-100||months[i].highTemp>140){
            cout<<"Invalid input, please try again."<<endl;
            cin>>months[i].highTemp;
        }
        months[i].avgTemp=(months[i].lowTemp+months[i].highTemp)/2;
    }
    
    //Map Inputs to Outputs -> Process
    for(int i=0;i<12;i++){ //calculate average rainfall
        totalRain+=months[i].rainfall;
        avgRain=totalRain/12.0;
    }
    for(int i=1;i<12;i++){ //calculate lowest temperature for that specific month
        if(lowest>months[i].lowTemp){
            lowest=months[i].lowTemp;
            lowMnth=months[i].month;
        }
    }
    for(int i=1;i<12;i++){ //calculate highest temperature for that specific month
        if(highest<months[i].highTemp){
            highest=months[i].highTemp;
            highMnth=months[i].month;
        }
    }
    for(int i=0;i<12;i++){ //calculate average temperature for all months combined
	totalAvg+=months[i].avgTemp;
	avgTotal=totalAvg/12.0;
    }
    
    //Display Inputs/Outputs
    cout<<"Average Rainfall "<<setprecision(2)<<avgRain<<" inches/month"<<endl;
    cout<<"Lowest  Temperature "<<lowMnth<<"  "<<lowest<<" Degrees Fahrenheit"<<endl;
    cout<<"Highest Temperature "<<highMnth<<"  "<<highest<<" Degrees Fahrenheit"<<endl;
    cout<<"Average Temperature for the year "<<avgTotal<<" Degrees Fahrenheit"<<endl;

    //Exit the Program - Cleanup
    return 0;
}