/* 
 * File:   main.cpp
 * Author: Attila Koksal
 * Created on January 4, 2021, 10:50 AM
 * Purpose:  CPP Template 
 *           To be copied for each Assignment Problem
 */

//System Libraries
#include <iostream>  //I/O Library
using namespace std;

struct Employee{
    string name;
    int hrw;
    float pr;
};

//User Libraries

//Global Constants
//Math, Science, Universal, Conversions, High Dimensioned Arrays

//Function Prototypes
void convert(int);

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
  cout<<"Amount:      here"<<endl;
  cout<<"Signature: ______________";
}
    //Exit the Program - Cleanup
    return 0;
}
void convert(int value){
    char *first[20]={"zero", "one", "two", "three","four","five","six","seven","eight","nine","ten",
    "eleven","twelve","thirteen","fourteen","fifteen","sixteen","seventeen","eighteen","nineteen"};
  
    char *second[10]={"", "ten", "twenty", "thirty","forty","fifty","sixty","seventy","eighty","ninety"};

    if(value<0)
    {
        cout<<" ";
        convert(-value);
    }
    else if(value>=1000){
        convert(value/1000);
        cout<<" THOUSAND";
        if(value%1000){
            if(value%1000<100){
                cout<<" AND";
            }
            cout<<" " ;
            convert(value%1000);
        }
    }
    else if(value>=100){
        convert(value/100);
        cout<<" HUNDRED";
        if(value%100){
            cout<<" AND ";
            convert(value%100);
        }
    }
    else if(value>=20){
        cout<<second[value/10];
        if(value%10){
            cout<<" ";
            convert(value%10);
        }
    }
    else{
        cout<<first[value];
    }
    return;
    
}