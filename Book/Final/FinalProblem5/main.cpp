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
        Employee(char myName[],char jobTitle[],float hourlyRate){//Constructor
            for(int i=0;i<(sizeof(&myName)/(sizeof(char)));i++){
                MyName[i]=myName[i];
            }
            for(int i=0;i<(sizeof(&jobTitle)/(sizeof(char)));i++){
                JobTitle[i]=jobTitle[i];
            }
            if(hourlyRate<=0.0||hourlyRate>=200.0){
                cout<<"Unacceptable Hourly Rate"<<endl;
                HourlyRate=0;
            }
            else{
                HourlyRate=hourlyRate;
            }            
            HoursWorked=0;
            GrossPay=0;
            NetPay=0;
        }
        float CalculatePay(float hourlyR,int hoursWorked){//Procedure
            return getNetPay(getGrossPay(setHourlyRate(hourlyR),setHoursWorked(hoursWorked)));
        }
        float getGrossPay(float hourlyRate,int hoursWorked){//Procedure
            float grosspay=0;
            if(hoursWorked<=40){
                grosspay=hourlyRate*hoursWorked;
            }
            else if(hoursWorked>40&&hoursWorked<=50){
                float straightPay=hourlyRate*40;
                grosspay=straightPay+((hourlyRate*(hoursWorked-40))*1.5);
            }
            else if(hoursWorked>50){
                grosspay=(hourlyRate*40)+((hourlyRate*10)*1.5)+((hourlyRate*(hoursWorked-50))*2.0);
            }
            cout<<grosspay<<"---------------------------"<<endl;
            GrossPay=grosspay;
            return grosspay;
        }
        float getNetPay(float gross){//Procedure
            float difference=gross-Tax(gross);
            NetPay=difference;
            return difference;
        }
        void toString(){//Procedure
            cout<<"Name = "<<MyName<<" Job Title = "<<JobTitle<<endl;
            cout<<"Hourly Rate = "<<HourlyRate<<" Hours Worked = "<<HoursWorked<<" Gross Pay = "<<GrossPay<<" Net Pay = "<<NetPay<<endl;
        }
        int setHoursWorked(int hoursWorked){//Procedure
            if(hoursWorked<=0||hoursWorked>=84){
                cout<<"Unacceptable Hours Worked"<<endl;
                HoursWorked=0;
            }
            else{
                HoursWorked=hoursWorked;
            }
            return HoursWorked;
        }
        float setHourlyRate(float hourlyRate){//Procedure
            if(hourlyRate<=0.0||hourlyRate>=200.0){
                cout<<"Unacceptable Hourly Rate"<<endl;
                HourlyRate=0;
            }
            else{
                HourlyRate=hourlyRate;
            }
            return HourlyRate;
        }
    private:
        double Tax(float grossPay){//Utility Procedure
            double tax=0;
            if(grossPay<=500){
                tax=grossPay*0.1;
            }
            else if(grossPay>500&&grossPay<=1000){
                tax=(500*0.1)+((grossPay-500)*0.2);
            }
            else if(grossPay>1000){
                tax=(500*0.1)+(500*0.2)+((grossPay-1000)*0.3);
            }
            return tax;
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
    Mark.CalculatePay(Mark.setHourlyRate(20.0),Mark.setHoursWorked(25));
    Mark.toString();
    Mark.CalculatePay(Mark.setHourlyRate(40.0),Mark.setHoursWorked(25));
    Mark.toString();
    Mark.CalculatePay(Mark.setHourlyRate(60.0),Mark.setHoursWorked(25));
    Mark.toString();

    Mary.toString();
    Mary.CalculatePay(Mary.setHourlyRate(50.0),Mary.setHoursWorked(40));
    Mary.toString();
    Mary.CalculatePay(Mary.setHourlyRate(50.0),Mary.setHoursWorked(50));
    Mary.toString();
    Mary.CalculatePay(Mary.setHourlyRate(50.0),Mary.setHoursWorked(60));
    Mary.toString();
    
    //Exit the Program - Cleanup
    return 0;
}