/* 
 * File:   main.cpp
 * Author: Attila Koksal
 * Created on April 2, 2021, 1:30 PM
 * Purpose:  CPP Template 
 *           To be copied for each Assignment Problem
 */

//System Libraries
#include <iostream>  //I/O Library
#include <iomanip>
using namespace std;

enum mnth {Jan=0,Feb,Mar,Apr,May,Jun,Jul,Aug,Sep,Oct,Nov,Dec};

struct Weather{
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
    
    //Initialize Variables
    int size=6;
    int j=0;
    while(j<size){
        cout<<"Enter the total rainfall for the month:"<<endl;
        cin>>months[j].rainfall;
        cout<<"Enter the high temp:"<<endl;
        cin>>months[j].highTemp;
        while (months[j].highTemp<-100||months[j].highTemp>140){
            cin>>months[j].highTemp;
        }
        cout<<"Enter the low temp:"<<endl;
        cin>>months[j].lowTemp;
        while (months[j].lowTemp<-100||months[j].lowTemp>140){
            cin>>months[j].lowTemp;
        }
        months[j].avgTemp=(months[j].lowTemp+months[j].highTemp)/2;
        j++;
    }
    
    //Map Inputs to Outputs -> Process
    float totalRain=0;
    float avgRain=0;
    for(int i=Jan;i<size;i++){
        totalRain+=months[i].rainfall;
        avgRain=totalRain/size;
    }
    int highest=months[0].highTemp;
    for(int i=Jan;i<size;i++){
        if(highest<months[i].highTemp){
            highest=months[i].highTemp;
        }
    }
    int lowest=months[0].lowTemp;
    for(int i=Jan;i<Jun;i++){ 
        if(lowest>months[i].lowTemp){
            lowest=months[i].lowTemp;
        }
    }
    float totalAvg=0;
    float avgTotal=0;
    for(int i=Jan;i<size;i++){
	totalAvg+=months[i].avgTemp;
	avgTotal=totalAvg/size;
    }
    
    //Display Inputs/Outputs
    cout<<"Average monthly rainfall:"<<setprecision(3)<<avgRain<<endl;
    cout<<"High Temp:"<<highest<<endl;
    cout<<"Low Temp:"<<lowest<<endl;
    cout<<"Average Temp:"<<avgTotal;
    
    //Exit the Program - Cleanup
    return 0;
}