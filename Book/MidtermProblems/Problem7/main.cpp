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
    prntPrm(p);
    
    //Exit the Program - Cleanup
    return 0;
}
Primes *factor(int num){
    int start=2;
    int facAry[10000];
    while(num>1){
        if(num%start==0){
            facAry[start]++;
            num=num/start;
        }
        else{
            start++;
        }
    }
    int i=0;
    start=0;
    while(i<10000){
        if(facAry[i]!=0){
            start++;
        }
        i++;
    }
    Primes *p=new Primes;
    p->nPrimes=start;
    p->prime=new Prime[start];
    i=0;
    start=0;
    while(i<10000){
        if(facAry[i]!=0){
            p->prime[start].prime=i;
            p->prime[start].power=facAry[i];
            start++;
        }
        i++;
    }
    return p;
}
void prntPrm(Primes *prme){
    int num=prme->nPrimes;
    int curr=0;
    while(num>curr){
        curr++;
        if(curr==num-1){
            break;
        }
        cout<<prme->prime[curr].prime<<"^"<<prme->prime[curr].power<<endl;
    }
}