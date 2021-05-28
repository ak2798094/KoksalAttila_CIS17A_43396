/* 
 * File:   main.cpp
 * Author: Attila Koksal
 * Created on May 27, 2021, 10:45 AM
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
    class BadHour{
    private:
        int hours;
        string msg="";
    public:
        BadHour(int h){
            hours=h;
        }
        string getMsg(){
            msg+=to_string(hours)+" is not a valid"+" value for hours in Military Time!"<<endl;
            return msg;
        }
    };
    class BadSeconds{
    private:
        int seconds;
        string msg="";
    public:
        BadSeconds(int s){
            seconds=s;
        }
        string getMsg(){
            msg+=to_string(seconds)+" is not a valid"+" value for seconds in Military Time!"<<endl;
            return msg;
        }
    };
    MilTime():Time(){
        milHours=0;
        milSeconds=0; 
    }
    MilTime(int milH,int milS):Time(milH/100,milH%100,milS){
        if(milH<0||milH>2359){
            throw BadHour(milH);
        }else if(milS<0||milS>59){
            throw BadSeconds(milS);
        }else{
            //set the values to member variables
            milHours=milH;
            milSeconds=milS;
        }
    }
    void setTime(int milH,int milS){
        if(milH<0||milH>2359){
            throw BadHour(milH);
        }else if(milS<0||milS>59){
            throw BadSeconds(milS);
        }else{
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
    MilTime time1(1345, 59);
    
    //Initialize Variables
    
    //Map Inputs to Outputs -> Process
    
    //Display Inputs/Outputs
    cout << "Military format: " << time1.getHours() << endl;
    cout << "Standard format: " << time1.getStandHr() << endl;

    try{
        time1.setTime(2500,10);
    }
    catch(MilTime::BadHour e){
        cout<<"Error caught!"<<endl;
        cout<<e.getMsg()<<endl;
    }
    catch(MilTime::BadSeconds e){
        cout<<"Error caught!"<<endl;
        cout<<e.getMsg()<<endl;
    }
    cout<<"Military format: "<<time1.getHours()<<endl;
    cout<<"Standard format: "<<time1.getStandHr()<<endl;
    
    try{
        time1.setTime(1630,65);
    }
    catch(MilTime::BadHour e){
        cout<<"Error caught!"<<endl;
        cout<<e.getMsg()<<endl;
    }
    catch(MilTime::BadSeconds e){
        cout<<"Error caught!"<<endl;
        cout<<e.getMsg()<<endl;
    }
    cout<<"Military format: "<<time1.getHours()<<endl;
    cout<<"Standard format: "<<time1.getStandHr()<<endl;
    
    //Exit the Program - Cleanup
    return 0;
}