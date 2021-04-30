/* 
 * File:   main.cpp
 * Author: Attila Koksal
 * Created on April 25, 2021, 8:10 PM
 * Purpose:  Problem 7
 */

//System Libraries
#include <iostream>  //I/O Library
using namespace std;

struct Prime{
    unsigned short prime;
    unsigned char power;
};

struct Primes{
    Prime *prime;
    unsigned char nPrimes;
};

//User Libraries

//Global Constants
//Math, Science, Universal, Conversions, High Dimensioned Arrays

//Function Prototypes
Primes *factor(int);
void prntPrm(Primes *);

//Execution Begins Here
int main(int argc, char** argv) {
    //Initialize the Random Number Seed
    
    //Declare Variables
    int number;
    
    //Initialize Variables
    
    //Map Inputs to Outputs -> Process
    
    //Display Inputs/Outputs
    cout<<"Give me a number to factor: ";
    cin>>number;
    Primes *p=factor(number);
    cout<<"Factors of "<<number<<": ";
    print(p);
    
    //Exit the Program - Cleanup
    return 0;
}
Primes *factor(int num){
    
}
void print(Primes *prme){
    
}