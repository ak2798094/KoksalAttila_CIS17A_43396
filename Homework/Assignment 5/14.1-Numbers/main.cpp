/* 
 * File:   main.cpp
 * Author: Attila Koksal
 * Created on May 21, 2021, 10:15 AM
 * Purpose:  CPP Template 
 *           To be copied for each Assignment Problem
 */

//System Libraries
#include <iostream>  //I/O Library
using namespace std;

class Numbers{
private:
    int number;
    static string lessThan20[20];
    static string hundred;
    static string thousand;
    static string tens[8];
public:
    Numbers(int num){
        while(true){
            if(num<0||num>9999){
                cout<<"Error! Give a number between 0-9999: ";
                cin>>num;
            }
            else{
                number=num;
                break;
            }
        }
    }
    void print(){
        while(number>0){
            if((number/1000)>0){
                cout<<lessThan20[number/1000]<<" "<<thousand;
                number=number%1000;
            }
            else if((number/100)>0){
                cout<<" "<<lessThan20[number/100]<<" "<<hundred<<" ";
                number=number%100;
            }
            else if(number>=20){
                cout<<tens[(number/10)-2]<<" ";
                number=number%10;
            }
            else{
                cout<<lessThan20[number];
                break;
            }
        }
    }
};

string Numbers::lessThan20[20]={"zero","one","two","three","four","five","six","seven","eight","nine","ten","eleven","twelve","thirteen","fourteen","fifteen","sixteen","seventeen","eighteen","nineteen"};
string Numbers::hundred="hundred";
string Numbers::thousand="thousand";
string Numbers::tens[8]={"twenty","thirty","forty","fifty","sixty","seventy","eighty","ninety"};

//User Libraries

//Global Constants
//Math, Science, Universal, Conversions, High Dimensioned Arrays

//Function Prototypes

//Execution Begins Here
int main(int argc, char** argv) {
    //Initialize the Random Number Seed
    
    //Declare Variables
    int input;
    
    //Initialize Variables
    
    //Map Inputs to Outputs -> Process
    
    //Display Inputs/Outputs
    cout<<"Enter a number between 0-9999 to convert to its English description: ";
    cin>>input;
    Numbers number(input);
    number.print();
    
    //Exit the Program - Cleanup
    return 0;
}