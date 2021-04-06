/* 
 * File:   main.cpp
 * Author: Attila Koksal
 * Created on April 1, 2021, 12:05 PM
 * Purpose:  CPP Template 
 *           To be copied for each Assignment Problem
 */
//System Libraries
#include <iostream>
#include <iomanip>
using namespace std;

struct MonthlyBudget {
    float housing;
    float utility;
    float houseExp;
    float transprt;
    float food;
    float medical;
    float insurnce;
    float entertn;
    float cloth;
    float misc;
};

//User Libraries

//Global Constants - No Global Variables
//Only Universal Constants, Math, Physics, Conversions, Higher Dimensions

//Function Prototypes
MonthlyBudget getBgt();
float getExpense(string name);
void checkExpense(string name,float cost,float limit);
void checkBudget(MonthlyBudget bgt);

//Execution Begins Here

int main(int argc, char** argv) {
    //Set Random Number seed

    //Declare Variable Data Types and Constants


    //Initialize Variables

    //Process or map Inputs to Outputs

    //Display Outputs
    MonthlyBudget bgt=getBgt();
    checkBudget(bgt);

    //Exit stage right!
    return 0;
}
// asks the user for the expense for "name" and returns the cost of that expense

float getExpense(string name) {
    cout<<"Enter "<<name<<" cost for the month:$"<<endl;
    float value;
    cin>>value;
    return value;
}

// Asks the user for expenses and returns a budget

MonthlyBudget getBgt() {
    MonthlyBudget bgt;
    bgt.housing=getExpense("housing");
    bgt.utility=getExpense("utilities");
    bgt.houseExp=getExpense("household expenses");
    bgt.transprt=getExpense("transportation");
    bgt.food=getExpense("food");
    bgt.medical=getExpense("medical");
    bgt.insurnce=getExpense("insurance");
    bgt.entertn=getExpense("entertainment");
    bgt.cloth=getExpense("clothing");
    bgt.misc=getExpense("miscellaneous");
    return bgt;
}
// gets an expense's name, cost and limit, and prints accordingly 

void checkExpense(string name,float cost,float limit) {
    cout<<name;
    if(cost>limit){
        cout<<" Over"<<endl;
    }else if(cost < limit){
        cout<<" Under"<<endl;
    }else{
        cout<<" Even"<<endl;
    }
}
// Gets a budget and checks each expense and the total

void checkBudget(MonthlyBudget bgt) {
    checkExpense("Housing",bgt.housing,500.0);
    checkExpense("Utilities",bgt.utility,150.0);
    checkExpense("Household Expenses",bgt.houseExp,65.0);
    checkExpense("Transportation",bgt.transprt,50.0);
    checkExpense("Food",bgt.food,250.0);
    checkExpense("Medical",bgt.medical,30.0);
    checkExpense("Insurance",bgt.insurnce,100.0);
    checkExpense("Entertainment",bgt.entertn,150.0);
    checkExpense("Clothing",bgt.cloth,75.0);
    checkExpense("Miscellaneous",bgt.misc,50.0);
    float total_bgt=bgt.housing+bgt.utility+bgt.houseExp+bgt.transprt+bgt.food+bgt.medical+bgt.insurnce+bgt.entertn+bgt.cloth+bgt.misc;
    float total_limits=1420.0;
    if(total_bgt>total_limits){
        printf("You were $%.2f over budget",total_bgt-total_limits);
    }else if(total_bgt<total_limits){
        printf("You were $%.2f under budget",total_limits-total_bgt);
    }else{
        printf("You were $%.2f even budget",total_bgt-total_limits);
    }
}