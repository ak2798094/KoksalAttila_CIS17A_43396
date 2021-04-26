/* 
 * File:   main.cpp
 * Author: Attila Koksal
 * Created on April 24, 2021, 8:05 PM
 * Purpose:  Problem 4
 */

//System Libraries
#include <iostream>  //I/O Library
using namespace std;

//User Libraries

//Global Constants
//Math, Science, Universal, Conversions, High Dimensioned Arrays

//Function Prototypes
void encrypt(int);
void decrypt(int);

//Execution Begins Here
int main(int argc, char** argv) {
    //Initialize the Random Number Seed
    
    //Declare Variables
    int number;
    
    //Initialize Variables
    
    //Map Inputs to Outputs -> Process
    
    //Display Inputs/Outputs
    cout<<"Enter the number to be encrypted: ";
    cin>>number;
    encrypt(number);
    cout<<"Enter the number to be decrypted: ";
    cin>>number;
    decrypt(number);
    
    //Exit the Program - Cleanup
    return 0;
}
void encrypt(int num){
    int first,second,third,fourth; // storing respective digit of number
    fourth=num%10;
    num=num/10;
    third=num%10;
    num=num/10;
    second=num%10;
    num=num/10;
    first=num;
    if(first==8||first==9||second==8||second==9||third==8||third==9||fourth==8||fourth==9){ // if any digit is 8 or 9, print an error message and return
        cout<<"8 or 9 cannot be in the number."<<endl<<endl;
        return;
    }
    // encryption begins
    first=(first+5)%8;
    second=(second+5)%8;
    third=(third+5)%8;
    fourth=(fourth+5)%8;
    // swapping first with third and second with fourth
    int number=1000*third+100*fourth+10*first+second;
    cout<<"Encrypted number is "<<number<<"!"<<endl;
}
void decrypt(int num){
    int first,second,third,fourth; // storing respective digit of number
    fourth=num%10;
    num=num/10;
    third=num%10;
    num=num/10;
    second=num%10;
    num=num/10;
    first=num;
    if(first==8||first==9||second==8||second==9||third==8||third==9||fourth==8||fourth==9){ // if any digit is 8 or 9, print an error message and return
        cout<<"8 or 9 cannot be in the number."<<endl<<endl;
        return;
    }
    // decryption begins (-5+8)=3 since decrementing 5 but digit can be negative so add 8 so digit remains positive
    first=(first+3)%8;
    second=(second+3)%8;
    third=(third+3)%8;
    fourth=(fourth+3)%8;
    // swapping first with third and second with fourth
    int number=1000*third+100*fourth+10*first+second;
    cout<<"Decrypted number is "<<number<<"!"<<endl;
}