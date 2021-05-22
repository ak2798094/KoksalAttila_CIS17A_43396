/* 
 * File:   main.cpp
 * Author: Attila Koksal
 * Created on May 20, 2021, 4:25 PM
 * Purpose:  CPP Template 
 *           To be copied for each Assignment Problem
 */

//System Libraries
#include <iostream>  //I/O Library
using namespace std;

class RetailItem{
private:
    string description;
    int unitsOnHand;
    float price;
public:
    RetailItem(string describe,int units,float prce){
        description=describe;
        unitsOnHand=units;
        price=prce;
    }
    void setDescription(string s){
        description=s;
    }
    void setunitsOnHand(int n){
        unitsOnHand=n;
    }
    void setPrice(float f){
        price=f;
    }
    string getDescription(){
        return description;
    }
    int getunitsOnHand(){
        return unitsOnHand;
    }
    float getPrice(){
        return price;
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
    RetailItem item1=new RetailItem("Jacket",12,59.95);
    RetailItem item2=new RetailItem("Designer Jeans",40,34.95);
    RetailItem item3=new RetailItem("Shirt",20,24.95);
    
    //Initialize Variables
    
    //Map Inputs to Outputs -> Process
    
    //Display Inputs/Outputs
    
    //Exit the Program - Cleanup
    return 0;
}