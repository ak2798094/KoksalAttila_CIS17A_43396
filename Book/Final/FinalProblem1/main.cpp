/* 
 * File:   main.cpp
 * Author: Attila Koksal
 * Created on June 3, 2021, 5:30 PM
 * Purpose:  CPP Template 
 *           Problem 1 of Final
 */

//System Libraries
#include <iostream>  //I/O Library
#include <cmath>
using namespace std;

class Prob1Random{
    private:
        char*set;//The set of numbers to draw random numbers from
        char nset;//The number of variables in the sequence
        int *freq;//Frequency of all the random numbers returned
        int numRand;//The total number of times the random number function is called
    public:
        Prob1Random(const char numSize,const char *arraySet){//Constructor
            nset=numSize;
            numRand=0;
            set=new char[numSize];
            for(int i=0;i<nset;i++){
                set[i]=arraySet[i];
            }
            freq=new int[numSize];
            for(int i=0;i<nset;i++){
                freq[i]=0;
            }
        }
        ~Prob1Random(void){//Destructor
            delete []set;
            delete []freq;
        }
        char randFromSet(void){//Returns a random number from the set
            int random=set[rand()%nset]; 
            numRand++;
            for(int i=0;i<nset;i++){
                if(set[i]==random){
                    freq[i]++;
                }
            }
            return random;
        }
        int *getFreq(void)const{//Returns the frequency histogram
            return freq;
        }
        char *getSet(void)const{//Returns the set used
            return set;
        }
        int getNumRand(void)const{//Gets the number of times randFromSet has been called
            return numRand;
        }
};

//User Libraries

//Global Constants
//Math, Science, Universal, Conversions, High Dimensioned Arrays

//Function Prototypes

//Execution Begins Here
int main(int argc, char** argv) {
    //Initialize the Random Number Seed
    
    //Declare Variables
    char n=5;
    char rndseq[]={18,33,56,79,124};
    int ntimes=100000;
    Prob1Random a(n,rndseq);
    
    //Initialize Variables
    
    //Map Inputs to Outputs -> Process
    
    //Display Inputs/Outputs
    for(int i=1;i<=ntimes;i++){
        a.randFromSet();
    }
    int *x=a.getFreq();
    char *y=a.getSet();
    for(int i=0;i<n;i++){
        cout<<int(y[i])<<" occurred "<<x[i]<<" times"<<endl;
    }
    cout<<"The total number of random numbers is "<<a.getNumRand()<<endl;
    
    //Exit the Program - Cleanup
    return 0;
}