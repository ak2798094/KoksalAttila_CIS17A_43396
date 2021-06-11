/* 
 * File:   main.cpp
 * Author: Attila Koksal
 * Created on June 7, 2021, 5:40 PM
 * Purpose:  CPP Template 
 *           Problem 5 of Final
 */

//System Libraries
#include <iostream>  //I/O Library
using namespace std;

class Employee{
    public:
        Employee(char[],char[],float){//Constructor
            
        }
        float CalculatePay(float,int){//Procedure
            
        }
        float getGrossPay(float,int){//Procedure
            
        }
        float getNetPay(float){//Procedure
            
        }
        void toString(){//Procedure
            
        }
        int setHoursWorked(int){//Procedure
            
        }
        float setHourlyRate(float){//Procedure
            
        }
    private:
        double Tax(float){//Utility Procedure
            
        }
        char MyName[20];//Property
        char JobTitle[20];//Property
        float HourlyRate;//Property
        int HoursWorked;//Property
        float GrossPay;//Property
        float NetPay;//Property
};

//User Libraries

//Global Constants
//Math, Science, Universal, Conversions, High Dimensioned Arrays

//Function Prototypes

//Execution Begins Here
int main(int argc, char** argv) {
    //Initialize the Random Number Seed
    
    //Declare Variables
    Employee Mark("Mark","Boss",215.50);
    Employee Mary("Mary","VP",50.0);
    
    //Initialize Variables
    
    //Map Inputs to Outputs -> Process
    
    //Display Inputs/Outputs
    Mark.setHoursWorked(-3);
    Mark.toString();
    Mark.CalculatePay(Mark.setHourlyRate(20.0),
            Mark.setHoursWorked(25));
    Mark.toString();
    Mark.CalculatePay(Mark.setHourlyRate(40.0),
            Mark.setHoursWorked(25));
    Mark.toString();
    Mark.CalculatePay(Mark.setHourlyRate(60.0),
            Mark.setHoursWorked(25));
    Mark.toString();

    Mary.toString();
    Mary.CalculatePay(Mary.setHourlyRate(50.0),
            Mary.setHoursWorked(40));
    Mary.toString();
    Mary.CalculatePay(Mary.setHourlyRate(50.0),
            Mary.setHoursWorked(50));
    Mary.toString();
    Mary.CalculatePay(Mary.setHourlyRate(50.0),
            Mary.setHoursWorked(60));
    Mary.toString();
    
    //Exit the Program - Cleanup
    return 0;
}