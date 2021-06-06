/* 
 * File:   main.cpp
 * Author: Attila Koksal
 * Created on June 6, 2021, 12:35 PM
 * Purpose:  CPP Template 
 *           Problem 3 of Final
 */

//System Libraries
#include <iostream>  //I/O Library
using namespace std;

class SavingsAccount{
    public:
        SavingsAccount(float);               //Constructor
        void  Transaction(float);            //Procedure
        float Total(float=0,int=0);	         //Savings Procedure
        float TotalRecursive(float=0,int=0);
        void  toString();                    //Output Properties
    private:
        float Withdraw(float);               //Utility Procedure
        float Deposit(float);                //Utility Procedure
        float Balance;                       //Property
        int   FreqWithDraw;                  //Property
        int   FreqDeposit;                   //Property
};

//User Libraries

//Global Constants
//Math, Science, Universal, Conversions, High Dimensioned Arrays

//Function Prototypes

//Execution Begins Here
int main(int argc, char** argv) {
    //Initialize the Random Number Seed
    
    //Declare Variables
    SavingsAccount mine(-300);
    
    //Initialize Variables
    
    //Map Inputs to Outputs -> Process
    
    //Display Inputs/Outputs
    for(int i=1;i<=10;i++)
    {
        mine.Transaction((float)(rand()%500)*(rand()%3-1));
    }
    mine.toString();
    cout<<"Balance after 7 years given 10% interest = "
            <<mine.Total((float)(0.10),7)<<endl;
    cout<<"Balance after 7 years given 10% interest = "
            <<mine.TotalRecursive((float)(0.10),7)
            <<" Recursive Calculation "<<endl;
    
    //Exit the Program - Cleanup
    return 0;
}