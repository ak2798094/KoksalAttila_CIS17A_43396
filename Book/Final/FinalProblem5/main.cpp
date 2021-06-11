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
    private:
        double Tax(float grossPay){//Utility Procedure
            if(grossPay<500){
                grossPay=grossPay*0.1;
            }
            else if(grossPay>500&&grossPay<1000){
                grossPay=grossPay*0.2;
            }
            else if(grossPay>1000){
                grossPay=grossPay*0.3;
            }
            return grossPay;
        }
        char MyName[20];//Property
        char JobTitle[20];//Property
        float HourlyRate;//Property
        int HoursWorked;//Property
        float GrossPay;//Property
        float NetPay;//Property
    public:
        Employee(char myName[],char jobTitle[],float hourlyRate){//Constructor
            MyName[20]=myName;
            JobTitle[20]=jobTitle;
            HourlyRate=hourlyRate;
            HoursWorked=0;
            GrossPay=0;
            NetPay=0;
        }
        float CalculatePay(float,int){//Procedure
            
        }
        float getGrossPay(float hourlyRate,int hoursWorked){//Procedure
            float grosspay=0;
            if(hoursWorked<40){
                grosspay=hourlyRate;
            }
            else if(hoursWorked>40&&hoursWorked<50){
                grosspay=hourlyRate*0.5;
            }
            else if(hoursWorked>50){
                grosspay=hourlyRate*2.0;
            }
            return grosspay;
        }
        float getNetPay(float gross){//Procedure
            float difference=gross-Tax(gross);
            return difference;
        }
        void toString(){//Procedure
            
        }
        int setHoursWorked(int){//Procedure
            
        }
        float setHourlyRate(float){//Procedure
            
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