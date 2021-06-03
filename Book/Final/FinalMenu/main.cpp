/* 
 * File:   main.cpp
 * Author: Attila Koksal
 * Created on June 3, 2021, 3:30 PM
 * Purpose:  Menu using Functions, extend for final       
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
            default: cout<<"Exiting Menu"<<endl;
        }
    }while(choice<'7');
    
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
}

// Problem 1
void prblm1(){
    cout<<"Problem 1"<<endl;
    
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