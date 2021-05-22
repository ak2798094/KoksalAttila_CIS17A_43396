/* 
 * File:   main.cpp
 * Author: Attila Koksal
 * Created on May 21, 2021, 5:30 PM
 * Purpose:  CPP Template 
 *           To be copied for each Assignment Problem
 */

//System Libraries
#include <iostream>  //I/O Library
using namespace std;

class DivSales{
private:
    float salesQ[QUART];
    static float totalSalesY;
public:
    DivSales(){
        for(int count=0;count<QUART;count++){
            salesQ[count]=0;
        }
    }
    void salesAllQ(float allQuarters[]);
    float displayQ(int quarter){
        return salesQ[quarter];
    }
    float getTotal(){
        return totalSalesY;
    }
};

//User Libraries

//Global Constants
const int QUART=4;
const int NUM_DIV=4;
const int NUM_QUART=4;

//Math, Science, Universal, Conversions, High Dimensioned Arrays

//Function Prototypes

//Execution Begins Here
int main(int argc, char** argv) {
    //Initialize the Random Number Seed
    
    //Declare Variables
    DivSales allDivs[NUM_DIV];
    float qSales[NUM_QUART];
    
    //Initialize Variables
    
    //Map Inputs to Outputs -> Process
    
    //Display Inputs/Outputs
    for(int division=0;division<NUM_DIV;division++){
        cout<<"Division "<<division+1<<endl;
        for(int reset=0;reset<NUM_QUART;reset++){
            qSales[reset]=0;
        }
        for(int quart=0;quart<4;quart++){
            do{
                cout<<"Enter the sales for Division "<<division+1<<" and Quarter "<<quart+1<<": $";
                cin>>qSales[quart];
            }while(qSales<0);
        }
        allDivs[division].salesAllQ(qSales);
    }
    cout<<"Displaying Info below"<<endl;
    
    for(int division=0;division<NUM_DIV;division++){
        cout<<"Division "<<division+1<<endl;
        for(int quart=0;quart<NUM_QUART;quart++){
            float display=allDivs[division].displayQ(quart);
            cout<<"Division "<<division+1<<" quarter "<<quart+1<<": $";
            cout<<display<<endl;
        }
    }
    
    cout<<"Total Corporate Sales: $"<<allDivs[0].getTotal()<<endl;
    
    //Exit the Program - Cleanup
    return 0;
}
void DivSales::salesAllQ(float allQuarters[]){
    for(int count=0;count<QUART;count++){
        salesQ[count]=allQuarters[count];
        totalSalesY+=allQuarters[count];
    }
}
float DivSales::totalSalesY=0;