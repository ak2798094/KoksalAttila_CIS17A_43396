/* 
 * File:   main.cpp
 * Author: Attila Koksal
 * Created on April 25, 2021, 8:10 PM
 * Purpose:  Problem 7
 */

//System Libraries
#include <iostream>  //I/O Library
#include <cmath>;
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
Primes factor(int);
void prntPrm(Primes);
void addToPrime(Primes&,int&,int,int&);

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
    cout<<"Factors of "<<number<<": ";
    prntPrm(factor(number));
    
    //Exit the Program - Cleanup
    return 0;
}
Primes factor(int num){
    Primes primes;
    int nPrimes=0;
    while (num%2==0){
       addToPrime(primes,nPrimes,2,num);
    }
    for(int j=3;j<=sqrt(num);j=j+2){
       while(num%j==0){
       addToPrime(primes,nPrimes,j,num);
        }
    }
    if(num!=0&&num!=1){
       addToPrime(primes,nPrimes,num,num);
    }
    primes.nPrimes=int(nPrimes);
    return primes;
}
void addToPrime(Primes &primes,int& nPrimes, int number,int& num){
    bool found=false;
    for(int i=0;i<nPrimes;i++){
        if (primes.prime[i].prime==number){
            primes.prime[i].power=(char)(int(primes.prime[i].power)+1);
            num=num/number;
            found=true;
            break;
        }
    }
    if(!found){
        Prime* newArr=new Prime[nPrimes+1];
        for(int i=0;i<nPrimes;i++){
            newArr[i] = primes.prime[i];   
        }
        Prime newPri;
        newPri.prime=number;
        newPri.power=(char)1; 
        newArr[nPrimes]=newPri;
        primes.prime=newArr;
        nPrimes=nPrimes+1;
        num=num/number;
        }
}
void prntPrm(Primes prme){
    if (prme.nPrimes>0){
        cout<<prme.prime[0].prime<<"^"<<(int)prme.prime[0].power;
    }
    for (int i =1; i<prme.nPrimes;i++){
        cout<<"*"<<prme.prime[i].prime<<"^"<<(int)prme.prime[i].power;
    }
}