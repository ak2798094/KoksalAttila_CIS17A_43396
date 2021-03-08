/* 
 * File:   main.cpp
 * Author: Attila Koksal
 * Created on March 7, 2021, 10:30 PM
 * Purpose:  CPP Template 
 *           To be copied for each Assignment Problem
 */

//System Libraries
#include <iostream>  //I/O Library
#include <fstream> //Fstream Library
using namespace std;

//User Libraries

//Global Constants
//Math, Science, Universal, Conversions, High Dimensioned Arrays

//Function Prototypes

//Execution Begins Here
int main(int argc, char** argv) {
    //Initialize the Random Number Seed
    
    //Declare Variables
    int numOfMon=3; //Number of months
    int numOfDay=30; //Number of days
    string array[3][30]; //Array to store data
    int sumCollect[numOfMon][3]; //the second dimension collects in order: number of rainy, cloudy, and sunny
    string monNames[]={"June","July","August"}; //Contains the names of the months
    ifstream myfile;
    int maxRainD=-1; //Maximum rainy days
    int maxRainM=-1; //Maximum rainy months
    
    //Initialize Variables
    myfile.open("RainOrShine.txt");
    
    //Map Inputs to Outputs -> Process
    for(int i=0;i<numOfMon;i++){ //Initialize sum collection array to zeros
        for(int j=0;j<3;j++){
            sumCollect[i][j]=0;
        }
    }
    
    for(int i=0;i<numOfMon;i++){ //Loop through data file and processed data
        for(int j=0;j<numOfDay;j++){
            string line;
            if(getline(myfile,line)){
                array[i][j]=line.substr(0,1);
            }
            if(string(array[i][j])=="R"){sumCollect[i][0]++;}
            else if(string(array[i][j])=="C"){sumCollect[i][1]++;}
            else if(string(array[i][j])=="S"){sumCollect[i][2]++;}
        }
    }
    
    myfile.close();
    
    for(int i=0;i<numOfMon;i++){ //find out month with most sunny days
        if(sumCollect[i][0]>maxRainD){
            maxRainD=sumCollect[i][0];
            maxRainM=i;
        }
    }
    
    //Display Inputs/Outputs
    cout<<"Summary"<<endl;
    cout<<"-----------"<<endl;
    cout<<"Number of Rainy Days in June:"<<sumCollect[0][0]<<endl;
    cout<<"Number of Cloudy Days in June:"<<sumCollect[0][1]<<endl;
    cout<<"Number of Sunny Days in June:"<<sumCollect[0][2]<<endl;
    cout<<"Number of Rainy Days in July:"<<sumCollect[1][0]<<endl;
    cout<<"Number of Cloudy Days in July:"<<sumCollect[1][1]<<endl;
    cout<<"Number of Sunny Days in July:"<<sumCollect[1][2]<<endl;
    cout<<"Number of Rainy Days in August:"<<sumCollect[2][0]<<endl;
    cout<<"Number of Cloudy Days in August:"<<sumCollect[2][1]<<endl;
    cout<<"Number of Sunny Days in August:"<<sumCollect[2][2]<<endl;
    cout<<"Number of Rainy Days:"<<sumCollect[0][0]+sumCollect[1][0]+sumCollect[2][0]<<endl;
    cout<<"Number of Cloudy Days:"<<sumCollect[0][1]+sumCollect[1][1]+sumCollect[2][1]<<endl;
    cout<<"Number of Sunny Days:"<<sumCollect[0][2]+sumCollect[1][2]+sumCollect[2][2]<<endl;
    cout<<"Month with the most rainy days is "<<monNames[maxRainM];
    
    //Exit the Program - Cleanup
    return 0;
}