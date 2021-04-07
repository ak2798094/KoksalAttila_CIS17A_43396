/* 
 * File:   main.cpp
 * Author: Attila Koksal
 * Created on April 3, 2021, 5:25 PM
 * Purpose:  CPP Template 
 *           To be copied for each Assignment Problem
 */

//System Libraries
#include <iostream>  //I/O Library
#include <iomanip>      // std::setw
#include <stdio.h>
using namespace std;

struct Drink {
    string name;
    float cost;
    int numDrnk;
};

//User Libraries

//Global Constants
const int NUM_DRINK=5;
const int MAX_NAME_LEN=50;

//Math, Science, Universal, Conversions, High Dimensioned Arrays

//Function Prototypes
void printList(Drink[]);

//Execution Begins Here

int main(int argc, char** argv) {
    //Initialize the Random Number Seed

    //Declare Variables
    Drink drnk[NUM_DRINK];

    //Initialize Variables
    int totalEarn=0;
    drnk[0]={"Cola",75,20};
    drnk[1]={"Root Beer",75,20};
    drnk[2]={"Lemon-Lime",75,20};
    drnk[3]={"Grape Soda",80,20};
    drnk[4]={"Cream Soda",80,20};

    //Map Inputs to Outputs -> Process
    int j=0;
    while(true){
        j++;
        string nameCalled;
        printList(drnk);

        string mPay="";
        int mPayInt=0;
        int mRet=0;
        int selectionIndex=-1;
        
        getline(cin,nameCalled);
        if(nameCalled=="Quit"){
            break;
        }
        for(int i=0;i<NUM_DRINK;i++){
            if(drnk[i].name==nameCalled){
                selectionIndex=i;
            }
        }
        // if no name match, restart and ask for new input after error message
        if(selectionIndex==-1){
            cout<<"incorrect Input:"<<nameCalled<<",Please try again"<<endl;
            continue;
        }
        // if no drink left, restart and ask for new input after error message
        if(drnk[selectionIndex].numDrnk<=0){
            cout<<"There is no "<<nameCalled<<" left please try again"<<endl;
            continue;
        }

        getline(cin,mPay);
        mPayInt=stoi(mPay);

        while(mPayInt<drnk[selectionIndex].cost){
            cout<<"Did you pay enough money. "<<drnk[selectionIndex].cost<<" is required, try again"<<endl;
            getline(cin,mPay);
            mPayInt=stoi(mPay);
        }
        while((mPayInt>100)||(mPayInt<0)){
            cout<<"Incorrect amount, try again "<<drnk[selectionIndex].cost<<" is required, try again"<<endl;
            getline(cin,mPay);
            mPayInt=stoi(mPay);
        }
        mRet=mPayInt-drnk[selectionIndex].cost;
        totalEarn+=drnk[selectionIndex].cost;
        drnk[selectionIndex].numDrnk--;
        cout<<mRet<<endl;

    }
    
    //Display Inputs/Outputs
    cout<<totalEarn<<endl;
    
    //Exit the Program - Cleanup
    return 0;
}

void printList(Drink drnks[]){
    for(int i=0;i<NUM_DRINK;i++){
        cout<<left<<setw(11)<<drnks[i].name<<left<<setw(4)<<drnks[i].cost<<drnks[i].numDrnk<<endl;
    }
    cout<<"Quit"<<endl;
}