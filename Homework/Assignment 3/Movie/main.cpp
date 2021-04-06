/* 
 * File:   main.cpp
 * Author: Attila Koksal
 * Created on April 3, 2021, 6:30 PM
 * Purpose:  CPP Template 
 *           To be copied for each Assignment Problem
 */

//System Libraries
#include <iostream>  //I/O Library
#include <iomanip>
using namespace std;

struct MovieInfo {
    string movName;
    char *dirName;
    unsigned short yrRlsd;
    unsigned short runTime;
};

//User Libraries

//Global Constants
//Math, Science, Universal, Conversions, High Dimensioned Arrays

//Function Prototypes

//Execution Begins Here
int main(int argc, char** argv) {
    //Initialize the Random Number Seed
    
    //Declare Variables
    MovieInfo *mveInfo;
    int nMovies;
    
    //Initialize Variables
    cout<<"This program reviews structures"<<endl;
    cout<<"Input how many movies, the Title of the Movie, Director, Year Released, and the Running Time in (minutes)."<<endl;
    cin>>nMovies;

    mveInfo=new MovieInfo[nMovies];
    
    //Map Inputs to Outputs -> Process
    for (int mvees=0;mvees<nMovies;mvees++) {
        cin.ignore();
        getline(cin,mveInfo[mvees].movName);
        int size=81;
        mveInfo[mvees].dirName=new char[size];
        cin.getline(mveInfo[mvees].dirName,size - 1);
        cin>>mveInfo[mvees].yrRlsd;
        cin>>mveInfo[mvees].runTime;
        
    //Display Inputs/Outputs
        cout<<left<<endl;
        cout<<setw(11)<<"Title:"<<mveInfo[mvees].movName<<endl;
        cout<<setw(11)<<"Director:"<<mveInfo[mvees].dirName<<endl;
        cout<<setw(11)<<"Year:"<<mveInfo[mvees].yrRlsd<<endl;
        cout<<setw(11)<<"Length:"<<mveInfo[mvees].runTime<<endl;
    }
    //Exit the Program - Cleanup
    for (int mvees=0;mvees<nMovies;mvees++) {
        delete [] mveInfo[mvees].dirName;
    }
    delete [] mveInfo;
    
    return 0;
}