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
        T * sortArray(const T* oldArr,int rowNumber,bool ascending){//Sorts a single column array
           T *ch2=new T[rowNumber];
           int columnNumber = 1;
            T *arr=ch2;
            int selectColumn = 0;
            int size=rowNumber*(columnNumber+1);
            strncpy(arr,oldArr,size);
            bool changed=true;
            
            while(changed){
                changed=false;
               
            
                for(int i=0;i<size-(columnNumber+1);i=i+columnNumber+1){
                    if((arr[i+selectColumn]>arr[(i+selectColumn)+columnNumber+1]&&ascending)||(arr[i+selectColumn]<arr[(i+selectColumn)+columnNumber+1]&&!ascending)){
                        char temp[columnNumber+1];
                        int j = i;
                       
                        while(arr[j]>='a'&&arr[j]<='z'||(arr[j]>='A'&&arr[j]<='Z')){
                            temp[j-i]=arr[j];
                          
                            j++;
                        }
                        
                  
                        j=i;
                        while(arr[j]>='a'&&arr[j]<='z'||(arr[j]>='A'&&arr[j]<='Z')){
                            arr[j]=arr[j+columnNumber+1];
                            j++;
                        }
                   
                        j=i+columnNumber+1;
                        
                        while(arr[j]!='\0'&&arr[j]!='\n'){
                            arr[j]=temp[j-(i+columnNumber+1)];
                            j++;
                            
                        }
                    
                        changed=true;
                      
                        
                    }
                }
           
            }
            
            
            return arr;
        }
        T * sortArray(const T* oldArr,int rowNumber,int columnNumber,int selectColumn,bool ascending){//Sorts a 2 dimensional array represented as a 1 dim array
            T *ch2=new T[columnNumber*rowNumber];
            T *arr=ch2;
            selectColumn--;
            int size=rowNumber*(columnNumber+1);
            strncpy(arr,oldArr,size);
            bool changed=true;
            
            while(changed){
                changed=false;
               
            
                for(int i=0;i<size-(columnNumber+1);i=i+columnNumber+1){
                    if((arr[i+selectColumn]>arr[(i+selectColumn)+columnNumber+1]&&ascending)||(arr[i+selectColumn]<arr[(i+selectColumn)+columnNumber+1]&&!ascending)){
                        char temp[columnNumber+1];
                        int j = i;
                       
                        while(arr[j]>='a'&&arr[j]<='z'||(arr[j]>='A'&&arr[j]<='Z')){
                            temp[j-i]=arr[j];
                          
                            j++;
                        }
                        
                  
                        j=i;
                        while(arr[j]>='a'&&arr[j]<='z'||(arr[j]>='A'&&arr[j]<='Z')){
                            arr[j]=arr[j+columnNumber+1];
                            j++;
                        }
                   
                        j=i+columnNumber+1;
                        
                        while(arr[j]!='\0'&&arr[j]!='\n'){
                            arr[j]=temp[j-(i+columnNumber+1)];
                            j++;
                            
                        }
                    
                        changed=true;
                      
                        
                    }
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
        for(int j=0;j<17;j++){
            cout<<zc[i*17+j];
        }
    }
    //Exit the Program - Cleanup
   
    
    
    cout<<endl;
    return 0;
}