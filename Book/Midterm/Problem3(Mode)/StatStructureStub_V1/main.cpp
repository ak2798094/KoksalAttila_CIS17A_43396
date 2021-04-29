/* 
 * File:   main.cpp
 * Author: Attila Koksal
 * Purpose:  Driver program to test out the statistics problem.
 */

//Libraries
#include <iostream>//I/O
using namespace std;

//User Libraries
#include "Array.h"
#include "Stats.h"

//No Global Constants

//Function Prototypes I supply
Array *fillAry(int,int);        //Fill an array and put into a structure
void prntAry(const Array *,int);//Print the array 
int *copy(const int *,int);     //Copy the array
void mrkSort(int *,int);        //Sort an array
void prtStat(const Stats *);    //Print the structure
void rcvrMem(Array *);          //Recover memory from the Array Structure
void rcvrMem(Stats *);          //Recover memory from Statistics Structure

//Functions you are to supply
Stats *stat(const Array *);     //Find & store mean, median, & modes in structure

//Execution begins here
int main(int argc, char*argv[]) {
    //Declare variables
    int arySize;//Array Size
    int modNum; //Number to control the modes (digits 0 to 9 allowed)
    Array *array;
    
    //Input the size and mod number
    cout<<"This program develops an array to be analyzed"<<endl;
    cout<<"Array size from mod number to 100"<<endl;
    cout<<"Mod number from 2 to 10"<<endl;
    cout<<"Input the Array Size and the mod number to be used."<<endl;
    cin>>arySize>>modNum;
    cout<<endl<<endl;
    
    //Fill the array
    array=fillAry(arySize,modNum);
    
    //Print the initial array
    cout<<"Original Array before sorting"<<endl;
    prntAry(array,10);
    
    //Sort the array
    mrkSort(array->data,array->size);
    cout<<"Sorted Array to be utilize for the stat function"<<endl;
    prntAry(array,10);
    
    //Calculate some of the statistics
    Stats *stats=stat(array);
    
    //Print the statistics
    prtStat(stats);
    
    //Recover allocated memory
    rcvrMem(array);
    rcvrMem(stats);
    
    //Exit stage right
    return 0;
}

int *copy(const int *a,int n){
    //Declare and allocate an array
    //that is a c
    int *b=new int[n];
    //Fill
    for(int i=0;i<n;i++){
        b[i]=a[i];
    }
    //Return the copy
    return b;
}

void prtStat(const Stats *ary){
    cout<<endl;
    cout<<"The average of the array = "<<ary->avg<<endl;
    cout<<"The median of the array  = "<<ary->median<<endl;
    cout<<"The number of modes      = "<<
            ary->mode->size<<endl;
    cout<<"The max Frequency        = "<<
            ary->modFreq<<endl;
    if(ary->mode->size==0){
        cout<<"The mode set             = {null}"<<endl;
        return;
    }
    cout<<"The mode set             = {";
    for(int i=0;i<ary->mode->size-1;i++){
        cout<<ary->mode->data[i]<<",";
    }
    cout<<ary->mode->data[ary->mode->size-1]<<"}"<<endl;
}

void mrkSort(int *array,int n){
    for(int i=0;i<n-1;i++){
        for(int j=i+1;j<n;j++){
            if(array[j]<array[i]){
                int temp=array[i];
                array[i]=array[j];
                array[j]=temp;
            }
        }
    }
}

void rcvrMem(Stats *stats){
    rcvrMem(stats->mode);
    delete stats;
}

void rcvrMem(Array *array){
    delete []array->data;
    delete array;
}

void prntAry(const Array *array,int perLine){
    //Output the array
    for(int i=0;i<array->size;i++){
        cout<<array->data[i]<<" ";
        if(i%perLine==(perLine-1))cout<<endl;
    }
    cout<<endl;
}

Array *fillAry(int n, int modNum){
    //Allocate memory
    Array *array=new Array;
    array->size=n;
    array->data=new int[array->size];
    
    //Fill the array with mod numbers
    for(int i=0;i<n;i++){
        array->data[i]=i%modNum;
    }
    
    //Exit function
    return array;
}

Stats *stat(const Array *array){
    //Non-working stub to be completed by the student
    cout<<endl<<"Stat function to be completed by the student"<<endl;
    Stats *stats=new Stats;
    stats->mode=new Array;
    
    //-------------Mode----------------------
    //Copy the array
    int arySize=array->size;
    int *ary=copy(array->data, arySize);
    
    //Sort the copy
    mrkSort(ary, arySize);
    //Find the max Frequency
    int freq=1;
    int maxFreq=0;
    for (int i=1;i<arySize;i++) {
        if (ary[i]!=ary[i-1]) { // check if we are seeing it for the first time
            // freq now stores the frequency of the previous number
            if (maxFreq<freq) {
                maxFreq=freq;
            }
            freq=1;
        } else {
            freq+=1;
        }
    }
    if (arySize>0 && maxFreq<freq) {
        maxFreq=freq;
    }
    // done with maxFreq

    //Find the number of modes
    int numMode=0;
    if (maxFreq>1) {
        freq=1;
        for (int i=1;i<arySize;i++) {
            if (ary[i]!=ary[i-1]) { // check if we are seeing it for the first time
                // freq now stores the frequency of the previous number
                if (freq==maxFreq) { // if prev number is a mode
                    numMode+=1;
                    // save the previous number as a mode, but can't
                }
                freq=1;
            } else {
                freq+=1;
            }
        }
        // update with last element's frequency
        if (freq==maxFreq) {
            numMode+=1;
        }
    }
    //Allocate the mode array
    //Again this is just a stub.
    int *modeAry = new int[numMode+2];
    modeAry[0]=numMode; //Stub returns no modes
    modeAry[1]=maxFreq; //Stub returns Frequency 1

    //Fill the mode array
    int newIndex=2;
    if (maxFreq>1) { // if we have at least 1 mode
        freq=1;
        for (int i=1;i<arySize;i++){
            if (ary[i]!=ary[i-1]){ // check if we are seeing it for the first time
                // freq now stores the frequency of the previous number
                if (freq==maxFreq){ // if prev number is a mode
                    // save the previous number as a mode,  now we can
                    modeAry[newIndex]=ary[i-1];               
                    newIndex++;
                }
                freq=1;
            } else {
                freq+=1;
            }
        }
        // done with last number, store it if it is mode
        if (freq==maxFreq) { // there's a conflict with the previous if statement that's why we use it
            modeAry[newIndex]=ary[arySize-1];
        }
    }
    
    //--------------------------------
    
    //input the numMode result to the stats struct
    stats->mode->size=numMode;
    stats->modFreq=maxFreq;
    int nModes=numMode;
    if(nModes!=0)stats->mode->data=new int[nModes];
    for(int i=2;i<numMode+2;i++){ //copy elements of modearray to stats
    stats->mode->data[i-2]=modeAry[i];
    }
    //median
  
    if (arySize%2==0){//even
	stats->median=(ary[(arySize-1)/2]+ary[((arySize-1)/2)+1])/2.0;
    }else{//odd
    	stats->median=(ary[arySize/2]);
    }
    int sum=0;

    for(int i=0;i<arySize;i++){
    sum+=ary[i];
    }
    stats->avg=sum/(double) arySize;
    
    return stats;
}