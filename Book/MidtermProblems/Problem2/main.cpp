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

//Execution Begins Here
int main(int argc, char** argv) {
    
    Employee* ary;
    int currSize=0;

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
  cout<<ary[i].name<<endl;

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
  cout<<"Employee gross pay: "<<grosspay<<endl;;
}

    
    //Exit the Program - Cleanup
    return 0;
}