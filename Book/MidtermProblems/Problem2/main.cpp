/* 
 * File:   main.cpp
 * Author: Attila Koksal
 * Created on January 4, 2021, 10:50 AM
 * Purpose:  CPP Template 
 *           To be copied for each Assignment Problem
 */

//System Libraries
#include <iostream>  //I/O Library
#include <vector>
using namespace std;

struct Employee{
    string name;
    int hrw;
    float pr;
};

vector<string>ones{"","one","two","three","four","five","six","seven","eight","nine"};
vector<string>teens{"ten","eleven","twelve","thirteen","fourteen","fifteen","sixteen","seventeen","eighteen","nineteen"};
vector<string>tens{"","","twenty","thirty","forty","fifty","sixty","seventy","eighty","ninety"};

//User Libraries

//Global Constants
//Math, Science, Universal, Conversions, High Dimensioned Arrays

//Function Prototypes
string nameForNumber(long);

//Execution Begins Here
int main(int argc, char** argv) {
    
    Employee* ary;
    int currSize=0;
    string compName;
    string address;
    
    cout<<"Enter company name: ";
    cin>>compName;
    cout<<"Enter company address: ";
    cin.ignore();
    getline(cin,address);
    
    while(true){
        Employee emp;

        cout<<"Enter employee name: ";
        cin>>emp.name;

        cout<<"Enter employee's hours worked: ";
        cin>>emp.hrw;
        if(emp.hrw<0){
            break;
        }

        cout<<"Enter employee's pay rate: ";
        cin>>emp.pr;
        if(emp.pr<0){
            break;
        }

        //create a new array with +1 size
	Employee* aryNew = new Employee[currSize+1];
  
        //copy old info
  
        for(int i=0;i<currSize;i++){
            aryNew[i]=ary[i];
        }
  
	aryNew[currSize] = emp;
        currSize+=1;
        delete [] ary;
        ary = aryNew;
}

for(int i=0;i<currSize;i++){
  //--------------gross pay-----------------------
  float grosspay=0;
  if(ary[i].hrw<=40){//less than 40 hrs
  grosspay=ary[i].pr*ary[i].hrw;
  }

  if(ary[i].hrw>40 && ary[i].hrw<=50){//40-50 hrs
  grosspay=(ary[i].pr*40) + ((ary[i].pr*2)+(ary[i].hrw-40));
  }

  if(ary[i].hrw>50){//50+ hrs
  grosspay=(ary[i].pr*40) + ((ary[i].pr*2)*10) + ((ary[i].pr*3)+(ary[i].hrw-50));
  }
  //---------------------------------------------
  
  cout<<endl;
  cout<<compName<<endl;
  cout<<address<<endl;
  cout<<"Name: "<<ary[i].name;
  cout<<"   Amount: "<<grosspay<<endl;
  cout<<"Amount:        "<<nameForNumber(grosspay)<<endl;
  cout<<"Signature: ______________";
}
    //Exit the Program - Cleanup
    return 0;
}
string nameForNumber(long number){
    if(number<10){
        return ones[number];
    }else if(number<20){
        return teens[number-10];
    }else if(number<100){
        return tens[number/10]+((number%10!=0)?" "+nameForNumber(number%10):"");
    }else if(number<1000){
        return nameForNumber(number/100)+" hundred"+((number%100!=0)?" and "+nameForNumber(number%100):"");
    }else if(number<1000000){
        return nameForNumber(number/1000)+" thousand"+((number%1000!=0)?" and "+nameForNumber(number%1000):"");
    }else if(number<1000000000){
        return nameForNumber(number/1000000)+" million"+((number%1000000!=0)?" and "+nameForNumber(number%1000000):"");
    }else if(number<1000000000000){
        return nameForNumber(number/1000000000)+" billion"+((number%1000000000!=0)?" and "+nameForNumber(number%1000000000):"");
    }
    return "error";
    }