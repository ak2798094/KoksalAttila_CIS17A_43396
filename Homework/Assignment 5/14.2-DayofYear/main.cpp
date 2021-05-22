/* 
 * File:   main.cpp
 * Author: Attila Koksal
 * Created on May 21, 2021, 11:30 AM
 * Purpose:  CPP Template 
 *           To be copied for each Assignment Problem
 */

//System Libraries
#include <iostream>  //I/O Library
using namespace std;

class DayofYear{
private:
    int day;
public:
    DayofYear(int num){
        while(true){
            if(num<1||num>365){
                cout<<"Error! Give a number between 1-365: ";
                cin>>num;
            }
            else{
                day=num;
                break;
            }
        }
    }
    void print(){
        if(day>=1&&day<=31){
            cout<<"January "<<day<<endl;
        }
        else if(day>=32&&day<=59){
            cout<<"February "<<day-31<<endl;
        }
        else if(day>=60&&day<=90){
            cout<<"March "<<day-59<<endl;
        }
        else if(day>=91&&day<=120){
            cout<<"April "<<day-90<<endl;
        }
        else if(day>=121&&day<=151){
            cout<<"May "<<day-120<<endl;
        }
        else if(day>=152&&day<=181){
            cout<<"June "<<day-151<<endl;
        }
        else if(day>=182&&day<=212){
            cout<<"July "<<day-181<<endl;
        }
        else if(day>=213&&day<=243){
            cout<<"August "<<day-212<<endl;
        }
        else if(day>=244&&day<=273){
            cout<<"September "<<day-243<<endl;
        }
        else if(day>=274&&day<=304){
            cout<<"October "<<day-273<<endl;
        }
        else if(day>=305&&day<=334){
            cout<<"November "<<day-304<<endl;
        }
        else if(day>=335&&day<=365){
            cout<<"December "<<day-334<<endl;
        }
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
    int input;
    
    //Initialize Variables
    
    //Map Inputs to Outputs -> Process
    
    //Display Inputs/Outputs
    cout<<"Give a number between 1-365: ";
    cin>>input;
    DayofYear day(input);
    day.print();
    
    //Exit the Program - Cleanup
    return 0;
}