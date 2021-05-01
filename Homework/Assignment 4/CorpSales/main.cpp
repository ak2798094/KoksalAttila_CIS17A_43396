/* 
 * File:   main.cpp
 * Author: Attila Koksal
 * Created on April 21, 2021, 11:30 AM
 * Purpose:  CPP Template 
 *           To be copied for each Assignment Problem
 */

//System Libraries
#include <iostream>  //I/O Library
#include <fstream>
using namespace std;

const int LENGTH=4;

struct CorpInfo{
    static string Division[LENGTH];
    int QtrNum[LENGTH];
    float QtrSales;
};

string CorpInfo::Division[LENGTH]={"East","West","North","South"};

//User Libraries

//Global Constants

//Math, Science, Universal, Conversions, High Dimensioned Arrays

//Function Prototypes

//Execution Begins Here
int main(int argc, char** argv) {
    //Initialize the Random Number Seed
    
    //Declare Variables
    CorpInfo sale;
    
    //Initialize Variables
    
    //Map Inputs to Outputs -> Process
    
    //Display Inputs/Outputs
    fstream file("salesinfo.txt",ios::out|ios::binary);
    if(!file){
        cout<<"Error occurred when opening file. Program ended.";
        return 0;
    }
    
    cout<<"Enter the quarterly sales for each division:"<<endl;
    for(int i=0;i<LENGTH;i++){
        cout<<sale.Division[i]<<" Division:"<<endl;
        for(int j=0;j<LENGTH;j++){
            do{
                cout<<"Quarter "<<j+1<<": ";
                cin>>sale.QtrSales;
                if(sale.QtrSales<0){
                    cout<<"Sales must be greater than 0."<<endl;
                }
            }while(sale.QtrSales<0);
            sale.QtrNum[j]=sale.QtrSales;
        }
        file.write(reinterpret_cast<char *>(&sale),sizeof(sale));
    }
    file.close();
    
    //Exit the Program - Cleanup
    return 0;
}