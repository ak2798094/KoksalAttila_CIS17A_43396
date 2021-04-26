/* 
 * File:   main.cpp
 * Author: Attila Koksal
 * Created on April 24, 2021, 12:45 PM
 * Purpose:  Problem 1
 */

//System Libraries
#include <iostream>  //I/O Library
using namespace std;

struct Customer{
    string name;
    string address;
    int account;
    float balance;
    float ctotal[100];
    float dtotal[100];
};

//User Libraries

//Global Constants
//Math, Science, Universal, Conversions, High Dimensioned Arrays

//Function Prototypes
bool fiveDigit(int);

//Execution Begins Here
int main(int argc, char** argv) {
    //Initialize the Random Number Seed
    
    //Declare Variables
    string name,address;
    int checks,deposits,account;
    float balance,sum=0,diff=0,total=0,current;
    Customer* customer=new Customer;
    
    //Initialize Variables
    
    //Map Inputs to Outputs -> Process
    
    //Display Inputs/Outputs
    cout<<"Bank Account"<<endl;
    cout<<"Enter the customer's name: ";
    getline(cin,name);
    customer->name=name;
    cout<<"Enter the address: ";
    getline(cin,address);
    customer->address=address;
    cout<<"Enter the five digit account number: ";
    cin>>account;
    while(!fiveDigit(account)){
        cout<<"Invalid account number. Please enter a 5 digit account number: ";
        cin>>account;
    }
    customer->account=account;
    cout<<"Enter the account balance: ";
    cin>>balance;
    sum=sum+balance;
    cout<<"How many checks did you write this month?: ";
    cin>>checks;
    for(int i=0;i<checks;i++){
        cout<<"Enter the current check amount: ";
        cin>>current;
        customer->ctotal[i]=current;
        diff+=current;
    }
    cout<<"Total amount from checks: "<<diff<<endl;
    cout<<"How many deposits would you like to enter for this month?: ";
    cin>>deposits;
    for(int i=0;i<deposits;i++){
        cout<<"Enter the current deposit amount: ";
        cin>>current;
        customer->dtotal[i]=current;
        sum+=current;
    }
    cout<<endl;
    cout<<"Deposits: "<<sum<<endl;
    total=sum-diff;
    cout<<"Account balance at the end of this month is: "<<total<endl;
    if(total<0){
        cout<<"The account has been overdrawn. An additional $20 dollar fee has been accessed. The new balance is: "<<total-20<<endl;
    }
    cout<<customer->name<<" at "<<customer->address<<" with the account number of "<<customer->account<<" has a balance of $"<<total<<endl;
    
    //Exit the Program - Cleanup
    return 0;
}
bool fiveDigit(int number){
    int a=0;
    while(number>0){
        a++;
        number=number/10;
    }
    if(a==5){
        return true;
    }
    else{
        return false;
    }
}