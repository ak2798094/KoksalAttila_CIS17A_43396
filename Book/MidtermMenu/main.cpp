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
    //Initialize the Random Number Seed
    
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
}

// Problem 2
void prblm2(){
    cout<<"Problem 2"<<endl;
}

// Problem 3
void prblm3(){
    cout<<"Problem 3"<<endl;
}

// Problem 4
void prblm4(){
    cout<<"Problem 4"<<endl;
}

// Problem 5
void prblm5(){
    cout<<"Problem 5"<<endl;
}

// Problem 6
void prblm6(){
    cout<<"Problem 6"<<endl;
}

// Problem 7
void prblm7(){
    cout<<"Problem 7"<<endl;
}