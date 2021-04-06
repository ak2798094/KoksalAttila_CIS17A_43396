/* 
 * File:   main.cpp
 * Author: Attila Koksal
 * Created on April 1, 2021, 10:10 AM
 * Purpose:  CPP Template 
 *           To be copied for each Assignment Problem
 */

//System Libraries
#include <iostream>
using namespace std;

struct Division {
    string name;
    float sales[4];
    float totalSale;
    float avgSales;
};

//User Libraries

//Global Constants - No Global Variables
//Only Universal Constants, Math, Physics, Conversions, Higher Dimensions

//Function Prototypes

//Execution Begins Here

int main(int argc, char** argv) {
    //Set Random Number seed

    //Declare Variable Data Types and Constants
    string qrNames[4]={"first","second","third","fourth"};
    Division east;
    Division west;
    Division north;
    Division south;

    //Initialize Variables
    east.name="East";
    west.name="West";
    north.name="North";
    south.name="South";

    //Process or map Inputs to Outputs
    // Initialize north sales
    cout<<north.name<<endl;
    for(int qr=0;qr<4;qr++){
        cout<<"Enter "<<qrNames[qr]<<"-quarter sales:"<<endl;
        cin>>north.sales[qr];
    }
    // find total sales
    float totalSale=0;
    for(int qr=0;qr<4;qr++){
        totalSale+=north.sales[qr];
    }
    north.totalSale=totalSale;
    north.avgSales=totalSale/4;
    printf("Total Annual sales:$%.2f\n",north.totalSale);
    printf("Average Quarterly Sales:$%.2f\n",north.avgSales);
  
    // Initialize west sales
    cout<<west.name<<endl;
    for(int qr=0;qr<4;qr++){
        cout<<"Enter "<<qrNames[qr]<<"-quarter sales:"<<endl;
        cin>>west.sales[qr];
    }
    // find total sales
    totalSale=0;
    for(int qr=0;qr<4;qr++){
        totalSale+=west.sales[qr];
    }
    west.totalSale=totalSale;
    west.avgSales=totalSale/4;
    printf("Total Annual sales:$%.2f\n",west.totalSale);
    printf("Average Quarterly Sales:$%.2f\n",west.avgSales);
  
    // Initialize East sales
    cout<<east.name<<endl;
    for(int qr=0;qr<4;qr++){
        cout<<"Enter "<<qrNames[qr]<<"-quarter sales:"<<endl;
        cin>>east.sales[qr];
    }
    // find total sales
    totalSale=0;
    for(int qr=0;qr<4;qr++){
        totalSale+=east.sales[qr];
    }
    east.totalSale=totalSale;
    east.avgSales=totalSale/4;
    printf("Total Annual sales:$%.2f\n",east.totalSale);
    printf("Average Quarterly Sales:$%.2f\n",east.avgSales);

    // Initialize south sales
    cout<<south.name<<endl;
    for(int qr=0;qr<4;qr++){
        cout<<"Enter "<<qrNames[qr]<<"-quarter sales:"<<endl;
        cin>>south.sales[qr];
    }
    // find total sales
    totalSale=0;
    for(int qr=0;qr<4;qr++){
        totalSale+=south.sales[qr];
    }
    south.totalSale=totalSale;
    south.avgSales=totalSale/4;
    printf("Total Annual sales:$%.2f\n",south.totalSale);
    printf("Average Quarterly Sales:$%.2f",south.avgSales);
    //Exit stage right!
    return 0;
}