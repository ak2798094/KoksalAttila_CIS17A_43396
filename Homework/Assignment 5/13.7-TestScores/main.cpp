/* 
 * File:   main.cpp
 * Author: Attila Koksal
 * Created on May 20, 2021, 10:30 PM
 * Purpose:  CPP Template 
 *           To be copied for each Assignment Problem
 */

//System Libraries
#include <iostream>  //I/O Library
using namespace std;

class TestScores{
private:
    int score1;
    int score2;
    int score3;
public:
    TestScores(){
        score1=0;
        score2=0;
        score3=0;
    }
    TestScores(int s1,int s2,int s3){
        score1=s1;
        score2=s2;
        score3=s3;
    }
    void setScore1(int s){
        score1=s;
    }
    void setScore2(int s){
        score2=s;
    }
    void setScore3(int s){
        score3=s;
    }
    int getScore1(){
        return score1;
    }
    int getScore2(){
        return score2;
    }
    int getScore3(){
        return score3;
    }
    float getAverage(){
        return (score1+score2+score3)/3.0;
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
    int value;
    TestScores myScores;
    
    //Initialize Variables
    
    //Map Inputs to Outputs -> Process
    
    //Display Inputs/Outputs
    cout<<"Enter the first test score: ";
    cin>>value;
    myScores.setScore1(value);
    cout<<"Enter the second test score: ";
    cin>>value;
    myScores.setScore2(value);
    cout<<"Enter the third test score: ";
    cin>>value;
    myScores.setScore3(value);
    
    cout<<"Here are your test scores:"<<endl;
    cout<<"Test Score #1: "<<myScores.getScore1()<<endl;
    cout<<"Test Score #2: "<<myScores.getScore2()<<endl;
    cout<<"Test Score #3: "<<myScores.getScore3()<<endl;
    cout<<"Average: "<<myScores.getAverage()<<endl;
    
    //Exit the Program - Cleanup
    return 0;
}