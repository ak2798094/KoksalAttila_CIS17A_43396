/* 
 * File:   main.cpp
 * Author: Attila Koksal
 * Created on May 26, 2021, 12:15 PM
 * Purpose:  CPP Template 
 *           To be copied for each Assignment Problem
 */

//System Libraries
#include <iostream>  //I/O Library
using namespace std;

class Time{
protected:
    int hour;
    int min;
    int sec;
public:
    Time(){
        hour=0;
        min=0;
        sec=0;
    }
    Time(int h,int m,int s){ 
        hour=h;
        min=m;
        sec=s;
    }
    int getHour()const{ 
        return hour; 
    }
    int getMin()const{ 
        return min; 
    }
    int getSec()const{ 
        return sec; 
    }
    void setHour(int h){ 
        hour=h; 
    }
    void setMin(int m){ 
        min=m; 
    }
    void setSec(int s){ 
        sec=s; 
    }
};

class MilTime:public Time{
protected:
    int milHours;
    int milSeconds;
public:
    MilTime():Time(){ 
       milHours=0;
       milSeconds=0; 
    }
    MilTime(int milH,int milS):Time(milH/100,milH%100,milS){
        if(milH<0||milH>2359){
            cout<<milH<<" is not a valid";
            cout<<" value for Military Time!"<<endl;
            exit(0);
        }
        else if(milS<0||milS>59){
            cout<<milS<<" is not a valid";
            cout<<" value for Military Time!"<<endl;
            exit(0);
        }
        else{
            milHours=milH;
            milSeconds=milS;
        }
    }
    void setTime(int milH,int milS){
        if(milH<0||milH>2359){
            cout<<milH<<" is not a valid";
            cout<<" value for Military Time!"<<endl;
            exit(0);
        }
        else if(milS<0||milS>59){
            cout<<milS<<" is not a valid";
            cout<<" value for Military Time!"<<endl;
            exit(0);
        }
        else{
            milHours=milH;
            milSeconds=milS;
            setHour(milH/100);
            setMin(milH%100);
            setSec(milS);
        }
    }
    int getHours()const{ 
        return milHours; 
    }
    string getStandHr()const{   
        string res="";
        res+=to_string(getHour())+":"+to_string(getMin())+":"+to_string(getSec());
        return res;
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
    MilTime time1(1545, 35);
    
    //Initialize Variables
    
    //Map Inputs to Outputs -> Process
    
    //Display Inputs/Outputs
    cout<<"Military format: "<<time1.getHours()<<endl;
    cout<<"Standard format: "<<time1.getStandHr()<<endl;
    time1.setTime(1235, 42);
    cout<<"------Time Changed------"<<endl;
    cout << "Military format: " << time1.getHours() << endl;
    cout << "Standard format: " << time1.getStandHr() << endl;
    
    //Exit the Program - Cleanup
    return 0;
}