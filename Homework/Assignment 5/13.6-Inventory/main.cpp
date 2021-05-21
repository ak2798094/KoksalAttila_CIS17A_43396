/* 
 * File:   main.cpp
 * Author: Attila Koksal
 * Created on May 20, 2021, 8:30 PM
 * Purpose:  CPP Template 
 *           To be copied for each Assignment Problem
 */

//System Libraries
#include <iostream>  //I/O Library
using namespace std;

class Inventory{
private:
    int itemNumber;
    int quantity;
    float cost;
    float totalCost;
public:
    Inventory(){
        itemNumber=0;
        quantity=0;
        cost=0;
        totalCost=0;
    }
    Inventory(int newItemNumber,int newQuantity,float newCost){
        itemNumber=newItemNumber;
        quantity=newQuantity;
        cost=newCost;
        setTotalCost(quantity,cost);
    }
    void setItemNumber(int){
        itemNumber=itemNumber;
    }
    void setQuantity(int){
        quantity=quantity;
    }
    void setCost(int){
        cost=cost;
    }
    void setTotalCost(int,float){
        totalCost=quantity*cost;
    }
    int getItemNumber(){
        return itemNumber;
    }
    int getQuantity(){
        return quantity;
    }
    float getCost(){
        return cost;
    }
    float getTotalCost(){
        return totalCost;
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
    int itemNumber,quantity;
    float cost,totalCost;
    //Initialize Variables
    
    //Map Inputs to Outputs -> Process
    
    //Display Inputs/Outputs
    cout<<"Enter the Item Number: ";
    cin>>itemNumber;
    while(itemNumber<0){
        cout<<"Please enter a positive value for the Item Number: ";
        cin>>itemNumber;
    }
    cout<<"Enter the Quantity of the item: ";
    cin>>quantity;
    while(quantity<0){
        cout<<"Please enter a positive value for the Quantity of the item: ";
        cin>>quantity;
    }
    cout<<"Enter the Cost of the item: ";
    cin>>cost;
    while(cost<0){
        cout<<"Please enter a positive value for the Cost of the item: ";
        cin>>cost;
    }
    
    Inventory info(itemNumber,quantity,cost);
    
    totalCost=info.getTotalCost();
    itemNumber=info.getItemNumber();
    cost=info.getCost();
    quantity=info.getQuantity();
    cout<<"The Item Number is "<<itemNumber<<"."<<endl;
    cout<<"The Quantity is "<<quantity<<"."<<endl;
    cout<<"The Cost is $"<<cost<<"."<<endl;
    cout<<"The Total Cost is $"<<totalCost<<"."<<endl;
    
    //Exit the Program - Cleanup
    return 0;
}