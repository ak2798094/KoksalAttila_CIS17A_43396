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

class Date{
private:
	int month;
	int day;
	int year;
public:
	class InvalidDay{
	private:
            int value;
	public:
            InvalidDay(int val){
		value = val;
            }
            int getValue()const {
		return value;
            }
	};
	class InvalidMonth{
	private:
            int value;
	public:
            InvalidMonth(int val){
		value = val;
            }
            int getValue()const{
		return value;
            }
	};
	Date(){
            month=0;
            day=0;
            year=0;
	}
	Date(int,int,int);	
	void setDay(int d){
            if(!(d<1)&&!(d>31)){
		day = d;
            }else{
                throw InvalidDay(d);
            }
	}
	void setMonth(int m){
            if(!(m>12)&&!(m<1)){
                month=m;
            }else{
                throw InvalidMonth(m);
            }
	}
	void setYear(int y){
            year=y;
	}
	void format1()const;
	void format2()const;
	void format3()const;
};

//User Libraries

//Global Constants
//Math, Science, Universal, Conversions, High Dimensioned Arrays

//Function Prototypes

//Execution Begins Here
int main(int argc, char** argv) {
    //Initialize the Random Number Seed
    
    //Declare Variables
    int evMonth;
    int evDay;
    int evYear;
    Date myEvent;

    //Initialize Variables
    
    //Map Inputs to Outputs -> Process
    
    //Display Inputs/Outputs
    cout<<"Enter the month number: ";
    cin>>evMonth;
    cout<<"Enter the day number: ";
    cin>>evDay;
    cout<<"Enter the year number: ";
    cin>>evYear;
    try{
        myEvent.setMonth(evMonth);
        myEvent.setDay(evDay);
        myEvent.setYear(evYear);

        cout<<endl<<"The date of your event is:"<<endl;
        myEvent.format1();
        myEvent.format2();
        myEvent.format3();
    }
    catch (Date::InvalidDay e){
        cout<<"Error: "<<e.getValue()<<" is an invalid value"<<" for the date's day."<<endl;
    }catch (Date::InvalidMonth e){
        cout<<"Error: "<<e.getValue()<<" is an invalid value"<<" for the date's month."<<endl;
    }
    //Exit the Program - Cleanup
    return 0;
}
Date::Date(int d,int m,int y){
    if(!(d<1)&&!(d>31)){
        day=d;
    }else{
        throw InvalidDay(d);
    }
    if(!(m>12)&&!(m<1)){
        month=m;
    }else{
        throw InvalidMonth(m);
    }
    year=y;
}
void Date::format1()const{
    cout<<month<<"/"<<day<<"/"<<year<<endl;
}
void Date::format2()const{
    string whatMonth;

    switch(month){
    case 1:
        whatMonth="January";
        break;
    case 2:
        whatMonth="February";
        break;
    case 3:
        whatMonth="March";
        break;
    case 4:
        whatMonth="April";
        break;
    case 5:
        whatMonth="May";
        break;
    case 6:
        whatMonth="June";
        break;
    case 7:
        whatMonth="July";
        break;
    case 8:
        whatMonth="August";
        break;
    case 9:
        whatMonth="September";
        break;
    case 10:
        whatMonth="October";
        break;
    case 11:
        whatMonth="November";
        break;
    case 12:
        whatMonth="December";
        break;
    }
    cout<<whatMonth<<" "<<day<<", "<<year<<endl;
}

// displays date in format 3
void Date::format3()const{
    string whatMonth;

    switch(month){
    case 1:
        whatMonth="January";
        break;
    case 2:
        whatMonth="February";
        break;
    case 3:
        whatMonth="March";
        break;
    case 4:
        whatMonth="April";
        break;
    case 5:
        whatMonth="May";
        break;
    case 6:
        whatMonth="June";
        break;
    case 7:
        whatMonth="July";
        break;
    case 8:
        whatMonth="August";
        break;
    case 9:
        whatMonth="September";
        break;
    case 10:
        whatMonth="October";
        break;
    case 11:
        whatMonth="November";
        break;
    case 12:
        whatMonth="December";
        break;
    }
    cout<<day<<" "<<whatMonth<<" "<<year<<endl;
}