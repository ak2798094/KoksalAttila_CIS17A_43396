/* 
 * File:   main.cpp
 * Author: Attila Koksal
 * Created on March 7, 2021, 11:00 PM
 * Purpose:  CPP Template 
 *           To be copied for each Assignment Problem
 */

//System Libraries
#include <iostream>  //I/O Library
#include <algorithm> //Algorithm Library
using namespace std;

//User Libraries

//Global Constants
//Math, Science, Universal, Conversions, High Dimensioned Arrays

//Function Prototypes
int binarySearch(const string[],int,string);
const int SIZE=20;

//Execution Begins Here
int main(int argc, char** argv) {
    //Initialize the Random Number Seed
    
    //Declare Variables
    string idString[SIZE]={"asdf101","zxclv142","qwer152","asdf101","jzxcv142","qwjer152","asdxfj102","zxcqjv172","qwjar1582","asxf1021","z3cv112","qwjr154","jasd1311","zxcv1112","jqwer152","asjdf171","zxcv1j42","qwer1k59","asdxfk111","zxcqv135"}; //Array with employee IDs not sorted
    int N = sizeof(idString)/sizeof(idString[0]);
    sort(idString,idString+N); //sorted array in ascending order
    int results; //To hold the string results
    string empID; //To hold an employee ID
    
    //Initialize Variables
    cout<<"Enter the employee ID you wish to search for: "; //Get an employee ID to search for
    cin>>empID;
    
    //Map Inputs to Outputs -> Process
    results=binarySearch(idString,SIZE,empID); //Search for the ID
    if(results==-1){ //If results contains -1 then the ID was not found
        cout<<"That number does not exist in the array."<<" \n";
    }else{ //Otherwise results contains the subscript of the specified employee ID in the array
    
    //Display Inputs/Outputs
        cout<<"That ID:"<<idString[results]<<" is found at element "<<results;
        cout<<" in the array.\n";
    }
    
    //Exit the Program - Cleanup
    return 0;
}
int binarySearch(const string array[],int size,string value){
    int first=0, //First array element
        last=size-1, //Last array element
       middle; //Midpoint of search
    int position=-1; //Position of search value
    bool found = false; //Flag
    
    while(!found&&first<=last){
        middle=(first+last)/2; //Calculate midpoint
        if(array[middle]==value){ //If value is found at mid
            found=true;
            position=middle;
        }else if(array[middle]>value){ //If value is in lower half
            last=middle-1;
        }else{
            first=middle+1; //If value is in upper half
        }
    }
    return position;
}