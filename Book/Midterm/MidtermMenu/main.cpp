/* 
 * File:   main.cpp
 * Author: Attila Koksal
 * Created on April 24, 2021, 11:30 AM
 * Purpose:  Menu using Functions, extend for midterm       
 */

//System Libraries
#include <iostream>  //I/O Library
using namespace std;

//User Libraries

//Global Constants
//Math, Science, Universal, Conversions, High Dimensioned Arrays

//Function Prototypes
void menu();
void prblm1();
void prblm2();
void prblm3();
void prblm4();
void prblm5();
void prblm6();
void prblm7();

//Execution Begins Here
int main(int argc, char** argv) {
    //Declare Variables
    char choice;
    
    //Loop and Display Menu
    do{
        menu();
        cin>>choice;
        
        //Map Inputs to Outputs -> Process
        switch(choice){
            case '1':{prblm1();break;}
            case '2':{prblm2();break;}
            case '3':{prblm3();break;}
            case '4':{prblm4();break;}
            case '5':{prblm5();break;}
            case '6':{prblm6();break;}
            case '7':{prblm7();break;}
            default: cout<<"Exiting Menu"<<endl;
        }
    }while(choice<'8');
    
    //Exit the Program - Cleanup
    return 0;
}
void menu(){
    //Display Menu
    cout<<endl<<"Choose from the following Menu"<<endl;
    cout<<"Type 1 for Problem 1"<<endl;
    cout<<"Type 2 for Problem 2"<<endl;
    cout<<"Type 3 for Problem 3"<<endl;
    cout<<"Type 4 for Problem 4"<<endl;
    cout<<"Type 5 for Problem 5"<<endl;
    cout<<"Type 6 for Problem 6"<<endl;
    cout<<"Type 7 for Problem 7"<<endl;
}

// Problem 1
void prblm1(){
    cout<<"Problem 1"<<endl;
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
    cout<<"Account balance at the end of the month is: "<<total<<endl;
    if(total<0){
        cout<<"The account has been overdrawn. An additional $20 dollar fee has been accessed. The new balance is: "<<total-20<<endl;
    }
    cout<<customer->name<<" at "<<customer->address<<" with the account number of "<<customer->account<<" has a balance of $"<<total<<endl;
    
    //Exit the Program - Cleanup
    return 0;
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
}    
// Problem 2
void prblm2(){
    cout<<"Problem 2"<<endl;
}

// Problem 3
void prblm3(){
    cout<<"Problem 3"<<endl;
    cout<<"It's in another project called Midterm.";
}

// Problem 4
void prblm4(){
    cout<<"Problem 4"<<endl;
}

// Problem 5
void prblm5(){
    cout<<"Problem 5"<<endl;
    cout<<"a) Using a byte variable, both unsigned and signed, the largest n where n!factorial that can be calculated is 5, because 6!=720, which is largest than the bounds of byte variable ranging from -128 to 127."<<endl;
    cout<<"b) The largest factorial using unsigned char is 5."<<endl;
    cout<<"b) The largest factorial using signed char is 5."<<endl;
    cout<<"b) The largest factorial using unsigned short is 8."<<endl;
    cout<<"b) The largest factorial using signed short is 7."<<endl;
    cout<<"b) The largest factorial using unsigned int is 12."<<endl;
    cout<<"b) The largest factorial using signed int is 12."<<endl;
    cout<<"b) The largest factorial using long int is 12."<<endl;
    cout<<"b) The largest factorial using signed long int is 12."<<endl;
    cout<<"b) The largest factorial using unsigned long int is 12."<<endl;
    cout<<"b) The largest factorial using float is 12."<<endl;
    cout<<"b) The largest factorial using double is 12."<<endl;
}

// Problem 6
void prblm6(){
    cout<<"Problem 6"<<endl;
    cout<<"a) The conversion of 2.875 into binary, octal, and hex"<<endl<<"Binary: "<<"10.111"<<endl<<"Octal: "<<"2.7"<<endl<<"Hex: "<<"2E"<<endl;
    cout<<"The conversion of 0.1796875 into binary, octal, and hex"<<endl<<"Binary: "<<"0010111"<<endl<<"Octal: "<<"0.134"<<endl<<"Hex: "<<"0.2E"<<endl;
    cout<<"b) The conversion of -2.875 into binary, octal, and hex"<<endl<<"Binary: "<<"-10.111"<<endl<<"Octal: "<<"-2.7"<<endl<<"Hex: "<<"-2E"<<endl;
    cout<<"The conversion of -0.1796875 into binary, octal, and hex"<<endl<<"Binary: "<<"-0010111"<<endl<<"Octal: "<<"-0.134"<<endl<<"Hex: "<<"-0.2E"<<endl;
    cout<<"c) The decimal number of 59999901 is 0.1503238401."<<endl;
    cout<<"The decimal number of 59999902 is 0.1503238402."<<endl;
    cout<<"The decimal number of A66667FE is -0.2791729150."<<endl;
}

// Problem 7
void prblm7(){
    cout<<"Problem 7"<<endl;
}