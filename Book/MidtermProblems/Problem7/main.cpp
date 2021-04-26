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
    unsigned int prime;
    unsigned int power;
};

struct Primes{
    Prime *prime;
    unsigned int nPrimes;
};

//User Libraries

//Global Constants
//Math, Science, Universal, Conversions, High Dimensioned Arrays

//Function Prototypes
void factor(int);
void print(Primes *);

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
void factor(int num){
    int number=2;
    int primes[10000]={0}; // prime factor storage
    while(1<num){
        if(num%number==0){
            primes[number]++; // find prime factors
            num=num/number;
        }
        else{
            number++;
        }
    }
    int i=0;
    number=0;
    while(i<10000){
        if(primes[i]!=0){
            number++;
            i++;
        }
    }
    Primes *pr=new Primes;
    pr->nPrimes=number;
    pr->prime=new Prime[number];
    
    i=0;
    number=0;
    while(i<10000){
        if(primes[i]!=0){
            pr->prime[number].prime=i;
            pr->prime[number].power=primes[i];
            number++;
        }
        return pr;
    }
}
void print(Primes *pri){
    int prme=pri->nPrimes;
    int number=0;
    while(number<prme){
        something here
        if(number==prme-1){
            break;
        }
    }
    cout<<pri->prime[number].prime<<"^"<<pri->prime[number].power<<endl;
}