/* 
 * File:   main.cpp
 * Author: Attila Koksal
 * Created on April 20, 2021, 7:35 PM
 * Purpose:  CPP Template 
 *           To be copied for each Assignment Problem
 */

//System Libraries
#include <iostream>  //I/O Library
#include <fstream>
#include <string>
using namespace std;

//User Libraries

//Global Constants
//Math, Science, Universal, Conversions, High Dimensioned Arrays

//Function Prototypes

//Execution Begins Here
int main(int argc, char** argv) {
    //Initialize the Random Number Seed
    
    //Declare Variables
    string inputNme;
    string outputNme;
    string sentence;
    char var;
    
    //Initialize Variables
    cout<<"Enter input file name: "<<endl;
    cin>>inputNme;
    cout<<"Enter output file name: "<<endl;
    cin>>outputNme;
    cin.ignore();
    
    //Map Inputs to Outputs -> Process
    
    //Display Inputs/Outputs
    ifstream inputFile(inputNme);
    ofstream outputFile(outputNme);
    
    if(!inputFile && !outputFile){
        cout<<"Error in opening the files!"<<endl;
        cout<<"Try again!"<<endl;
        return 0;
    }
    
    while(getline(inputFile,sentence,'.')){
        bool Capitalze=false;
        for(int count=0;count<<sentence.length();count++){
            if(!isalpha(sentence[count])){
                outputFile<<sentence[count];
            }
            if(!Capitalze && isalpha(sentence[count])){
                outputFile<<(char)toupper(sentence[count]);
                Capitalze=true;
            }
            else if(Capitalze){
                outputFile<<(char)tolower(sentence[count]);
            }
        }
        outputFile<<".";
    }
    
    //Exit the Program - Cleanup 
    inputFile.close();
    outputFile.close();
    
    return 0;
}