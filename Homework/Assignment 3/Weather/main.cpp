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
        cin>>months[i].highTemp;
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
    
    //Display Inputs/Outputs
    
    //Exit the Program - Cleanup
    return 0;
}

#include <iostream>
#include <iomanip>

using namespace std;

struct Weather{
    string month;
    float rainfall;
    float lowTemp;
    float highTemp;
    float avgTemp;
};

int main(){
    
    Weather months[12];
    
    for(int i=0;i<12;i++){
        cin>>months[i].month;
        cin>>months[i].rainfall;
        cin>>months[i].lowTemp;
        cin>>months[i].highTemp;
        months[i].avgTemp=(months[i].lowTemp+months[i].highTemp)/2;
    }
    
    int totalRain=0;
    float avgRain=0;
    for(int i=0;i<12;i++){
        totalRain+=months[i].rainfall;
        avgRain=totalRain/12.0;
    }
    cout<<"Average Rainfall "<<setprecision(2)<<avgRain<<" inches/month"<<endl;
    
    int lowest=months[0].lowTemp;
    string lowMnth=months[0].month;
    for(int i=1;i<12;i++){ 
        if(lowest>months[i].lowTemp){
            lowest=months[i].lowTemp;
            lowMnth=months[i].month;
        }
    }
	cout<<"Lowest  Temperature "<<lowMnth<<"  "<<lowest<<" Degrees Fahrenheit"<<endl;
	
	int highest=months[0].highTemp;
	string highMnth=months[0].month;

    for(int i=1;i<12;i++){
        if(highest<months[i].highTemp){
            highest=months[i].highTemp;
            highMnth=months[i].month;
        }
    }
	cout<<"Highest Temperature "<<highMnth<<"  "<<highest<<" Degrees Fahrenheit"<<endl;
	
	int totalAvg=0;
	float avgTotal=0;
	for(int i=0;i<12;i++){
	    totalAvg+=months[i].avgTemp;
	    avgTotal=totalAvg/12.0;
	}
	cout<<"Average Temperature for the year "<<avgTotal<<" Degrees Fahrenheit"<<endl;
	
	return 0;
}