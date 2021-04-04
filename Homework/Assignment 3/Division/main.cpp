/* 
 * File:   
 * Author: Attila koksal
 * Created on April 1, 2021
 * Purpose:  
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

string qrNames[4] = {"first","second","third","fourth"};
//Function Prototypes


void processDivision(Division d){
  for (int qr = 0; qr < 4; qr++) {
    cout<<d.name<<endl;
    cout << "Enter " << qrNames[qr] << "-quarter " << qr + 1 << " sales:";
    cin >> d.sales[qr];
  }
  // find total sales
  float totalSale = 0;
  for (int qr = 0; qr < 4; qr++) {
    totalSale += d.sales[qr];
  }
  d.totalSale = totalSale;
  d.avgSales = totalSale / 4;
  printf("Total Annual sales:$%.2f\n",d.totalSale);
  printf("Average Quarterly Sales:$%.2f",d.avgSales);
}

void processDivision(string name){
  Division d;
  d.name = name;
  processDivision(d);
}

//Execution Begins Here

int main(int argc, char** argv) {
  //Set Random Number seed

  string divNames[4] =  {"North", "West", "East", "South"};

  for(int dind = 0;dind<4;dind++){
    processDivision(divNames[dind]);
    // Initialize north sales
    if(dind!=3){
      cout<<std::endl;
    }
  }

  //Exit stage right!
  return 0;
}