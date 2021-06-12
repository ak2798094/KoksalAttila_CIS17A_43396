/* 
 * File:   main.cpp
 * Author: Attila Koksal
 * Created on June 4, 2021, 2:30 PM
 * Purpose:  CPP Template 
 *           Problem 2 of Final
 */

//System Libraries
#include <iostream>  //I/O Library
#include <fstream>
#include <string.h>
using namespace std;

template<class T>
class Prob2Sort{
    private:
        int *index;//Index that is utilized in the sort
    public:
        Prob2Sort(){index=NULL;};//Constructor
        ~Prob2Sort(){delete []index;};//Destructor
        T * sortArray(const T* oldArr,int columnNumber,bool ascending){//Sorts a single column array
            T arr[columnNumber];
            for(int i=0;i<columnNumber;i++){
                arr[i]=oldArr[i];
            }
            bool changed=true;
            int i=0;
            while(changed){
                changed=false;
                for(int j=0;j<columnNumber-i-1;j++){
                    if((arr[j]>arr[j+1]&&ascending)||(arr[j]<arr[j+1]&&!ascending)){
                        char temp=arr[j];
                        arr[j]=arr[j+1];
                        arr[j+1]=temp;
                        changed=true;
                    }
                }
                i++;
            }
            return arr;
        }
        T * sortArray(const T* oldArr,int rowNumber,int columnNumber,int selectColumn,bool ascending){//Sorts a 2 dimensional array represented as a 1 dim array
            T *ch2=new T[columnNumber*rowNumber];
            T *arr=ch2;
            for(int i=0;i<columnNumber*rowNumber;i++){
                arr[i]=oldArr[i];
                cout<<oldArr[i]<<"shit";
            }
            strncpy(arr,oldArr,rowNumber*columnNumber);
            bool changed=true;
            int size=rowNumber*columnNumber;
            while(changed){
                changed=false;
                for(int i=0;i<size-columnNumber;i=i+columnNumber){
                    if((arr[i+selectColumn]>arr[(i+selectColumn)+columnNumber]&&ascending)||(arr[i+selectColumn]<arr[(i+selectColumn)+columnNumber]&&!ascending)){
                        char temp[columnNumber];
                        for(int j=i;j<=i+columnNumber-1;j++){
                            temp[j-i]=arr[j];
                        }
                        for(int j=i;j<=i+columnNumber-1;j++){
                            arr[j]=arr[j+columnNumber];
                        }
                        for(int j=i+columnNumber;j<=i+columnNumber-1+columnNumber;j++){
                            arr[j]=temp[j-(i+columnNumber)];
                        }
                        changed=true;
                    }
                    cout<<arr[i]<<"fuck";
                }
            }
            return arr;
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
    Prob2Sort<char> rc;
    bool ascending=true;
    ifstream infile;
    infile.open("Problem2.txt",ios::in);
    char *ch2=new char[10*16];
    char *ch2p=ch2;
    
    //Initialize Variables
    
    //Map Inputs to Outputs -> Process
    
    //Display Inputs/Outputs
    cout<<"The start of Problem 2, the sorting problem"<<endl;
    while(infile.get(*ch2)){cout<<*ch2;ch2++;}
    infile.close();
    cout<<endl;
    cout<<"Sorting on which column"<<endl;
    int column;
    cin>>column;
    char *zc=rc.sortArray(ch2p,10,16,column,ascending);
    for(int i=0;i<10;i++){
        for(int j=0;j<16;j++){
            cout<<zc[i*16+j];
        }
    }
    
    //Exit the Program - Cleanup
    delete []zc;
    cout<<endl;
    return 0;
}