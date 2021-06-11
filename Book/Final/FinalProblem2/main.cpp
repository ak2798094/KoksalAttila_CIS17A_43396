/* 
 * File:   main.cpp
 * Author: Attila Koksal
 * Created on June 4, 2021, 2:30 PM
 * Purpose:  CPP Template 
 *           Problem 2 of Final
 */

//System Libraries
#include <iostream>  //I/O Library
using namespace std;

template<class T>
class Prob2Sort{
    private:
        int *index;//Index that is utilized in the sort
    public:
        Prob2Sort(){index=NULL;};//Constructor
        ~Prob2Sort(){delete []index;};//Destructor
        T * sortArray(const T*,int,bool);//Sorts a single column array
        T * sortArray(const T*,int,int,int,bool);//Sorts a 2 dimensional array represented as a 1 dim array
}; 

//User Libraries

//Global Constants
//Math, Science, Universal, Conversions, High Dimensioned Arrays

//Function Prototypes

//Execution Begins Here
int main(int argc, char** argv) {
    //Initialize the Random Number Seed
    
    //Declare Variables
    Prob2Sort<char> rc;
    bool ascending=true;
    ifstream infile;
    infile.open("Problem2.txt",ios::in);
    char *ch2=new char[10*16];
    char *ch2p=ch2;
    
    //Initialize Variables
    
    //Map Inputs to Outputs -> Process
    
    //Display Inputs/Outputs
    cout<<"The start of Problem 2, the sorting problem"<<endl;
    while(infile.get(*ch2)){cout<<*ch2;ch2++;}
    infile.close();
    cout<<endl;
    cout<<"Sorting on which column"<<endl;
    int column;
    cin>>column;
    char *zc=rc.sortArray(ch2p,10,16,column,ascending);
    for(int i=0;i<10;i++){
        for(int j=0;j<16;j++){
            cout<<zc[i*16+j];
        }
    }
    
    //Exit the Program - Cleanup
    delete []zc;
    cout<<endl;
    return 0;
}