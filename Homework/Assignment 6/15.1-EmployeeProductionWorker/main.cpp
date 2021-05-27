/* 
 * File:   main.cpp
 * Author: Attila Koksal
 * Created on May 26, 2021, 10:30 AM
 * Purpose:  CPP Template 
 *           To be copied for each Assignment Problem
 */

//System Libraries
#include <iostream>  //I/O Library
using namespace std;

class Employee{
private:
    string name;
    int number;
    int hireDay;
    int hireMonth;
    int hireYear;
public:
    //default constructor
    Employee(){
        name="";
        number=0;
        hireDay=0;
        hireMonth=0;
        hireYear=0;
    }

    //overloaded constructor
    Employee(string n,int num,int d,int m,int y){
        name=n;
        number=num;
        if(d<0||d>31||m<0||m>12||y<1900||y>2018){
            cout<<"Error! Invalid hire date! Exiting!"<<endl;
            exit(0);
           }
        else{
            hireDay=d;
            hireMonth=m;
            hireYear=y;
        }
    }

    //getter functions
    string getName()const{
        return name;
    }

    int getNumber()const{
        return number;
    }

    string getHireDate()const{
        //create empty string
        string dt="";
        dt+=to_string(hireDay)+"/"+to_string(hireMonth)+"/"+to_string(hireYear);
        return dt;
    }

    void setName(string n){
        name=n;
    }

    void setNumber(int num){
        number=num;
    }

    void setHireDate(int d,int m,int y){
        if(d<0||d>31||m<0||m>12||y<1900||y>2018){
            cout<<"Error! Invalid hire date! Exiting!"<<endl;
            exit(0);
        }
        else{
            hireDay=d;
            hireMonth=m;
            hireYear=y;
        }
    }
};

class ProductionWorker:public Employee{
private:
    int shift;
    double payRate;
public:
    ProductionWorker():Employee(){
        shift=1;
        payRate=0.0;
    }
    ProductionWorker(string n,int num,int d,int m,int y,int sh,double p):Employee(n,num,d,m,y){
        if((sh!=1&&sh!=2)||p<0){
           cout<<"Error! Invalid input for shift ";
           cout<<"and/or pay rate! ";
           cout<<"Exiting!"<<endl;
           exit(0);
        }
        else{
           shift=sh;
           payRate=p;
        }
    }

    //getter functions
    string getShift()const{
        if(shift==1)
            return "Day";
        return "Night";
    }

    double getPayRate()const{
        return payRate;
    }

    //setter functions
    void setShift(int sh){
        //check for invalid input
        if(sh!=1&&sh!=2){
            cout<<"Error! Invalid input! Shift ";
            cout<<"can only be 1 or 2! Now terminating!"<<endl;
            exit(0);
        }
        else{
            //otherwise set shift
            shift=sh;
        }
    }

    void setPayRate(double p){
        if(p<0){
            cout<<"Error! Pay rate cannot be negative ";
            cout<<"number! Now terminating!"<<endl;
            exit(0);
        }
        else{
            payRate=p;
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
    ProductionWorker worker;
    
    //Initialize Variables
    
    //Map Inputs to Outputs -> Process
    
    //Display Inputs/Outputs
    worker.setName("Sam Flynn");
    worker.setNumber(3456);
    worker.setHireDate(15,6,2017);
    worker.setShift(1);
    worker.setPayRate(10.5);

    cout<<"Name: "<<worker.getName()<<endl;
    cout<<"Employee Number: "<<worker.getNumber()<<endl;
    cout<<"Hire Date: "<<worker.getHireDate()<<endl;
    cout<<"Working shift: "<<worker.getShift()<<endl;
    cout<<"Pay rate: $"<<worker.getPayRate()<<"/hr"<<endl;
    
    //Exit the Program - Cleanup
    return 0;
}