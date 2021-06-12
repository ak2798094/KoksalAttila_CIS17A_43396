/* 
 * File:   main.cpp
 * Author: Attila Koksal
 * Created on June 6, 2021, 12:35 PM
 * Purpose:  CPP Template 
 *           Problem 4 of Final
 */

//System Libraries
#include <iostream>  //I/O Library
using namespace std;

class SavingsAccount{
    public:
        SavingsAccount(float balance){//Constructor
            Balance=balance;
            FreqWithDraw=0;
            FreqDeposit=0;
        }
        void Transaction(float transAmount){//Procedure
            if(transAmount>0){
                Balance=Deposit(transAmount);
            }
            else if(transAmount<0){
                Balance=Withdraw(-transAmount);
            }
        }
        float Total(float savings=0,int time=0){//Savings Procedure
            float newBalance=Balance;
            for(int i=0;i<time;i++){
                newBalance=newBalance*(savings+1.0);
            }
            return newBalance;
        }
        float TotalRecursive(float savings=0,int timeLeft=0){
            Balance=Balance*(savings+1.0);
            timeLeft--;
            if(timeLeft>0){
                TotalRecursive(savings,timeLeft);
            }
            return Balance;
        }
        string toString(){//Output Properties
            cout<<"Balance="<<Balance<<endl;
            cout<<"WithDraws="<<FreqWithDraw<<endl;
            cout<<"Deposit="<<FreqDeposit<<endl;
            return ("Balance="+to_string(Balance)+"WithDraws="+to_string(FreqWithDraw)+"Deposit="+to_string(FreqDeposit));
        }
    private:
        float Withdraw(float transA){//Utility Procedure
            FreqWithDraw++;
            float newBalance=Balance-transA;
            if(newBalance<0){
                cout<<"WithDraw not Allowed"<<endl;
                newBalance=Balance;
            }
            return newBalance;
        }
        float Deposit(float transA){//Utility Procedure
            FreqDeposit++;
            return Balance+transA;
        }
        float Balance;//Property
        int FreqWithDraw;//Property
        int FreqDeposit;//Property
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
    for(int i=1;i<=10;i++){
        mine.Transaction((float)(rand()%500)*(rand()%3-1));
    }
    mine.toString();
    cout<<"Balance after 7 years given 10% interest = "<<mine.Total((float)(0.10),7)<<endl;
    cout<<"Balance after 7 years given 10% interest = "<<mine.TotalRecursive((float)(0.10),7)<<" Recursive Calculation "<<endl;
    cout<<"I did the modification of the toString() so that it returns a string."<<endl;

    
    //Exit the Program - Cleanup
    return 0;
}