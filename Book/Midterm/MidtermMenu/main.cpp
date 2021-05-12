/* 
 * File:   main.cpp
 * Author: Attila Koksal
 * Created on April 24, 2021, 11:30 AM
 * Purpose:  Menu using Functions, extend for midterm       
 */

//System Libraries
#include <iostream>  //I/O Library
#include <vector>
#include <cmath>
using namespace std;

struct Customer{
    string name;
    string address;
    int account;
    float balance;
    float ctotal[100];
    float dtotal[100];
};

struct Employee{
    string name;
    int hrw;
    float pr;
};

struct Prime{
    unsigned short prime;
    unsigned char power;
};

struct Primes{
    Prime *prime;
    unsigned char nPrimes;
};

vector<string>ones{"","one","two","three","four","five","six","seven","eight","nine"};
vector<string>teens{"ten","eleven","twelve","thirteen","fourteen","fifteen","sixteen","seventeen","eighteen","nineteen"};
vector<string>tens{"","","twenty","thirty","forty","fifty","sixty","seventy","eighty","ninety"};

//User Libraries

//Global Constants
//Math, Science, Universal, Conversions, High Dimensioned Arrays

//Function Prototypes
void menu();
void prblm1();
void prblm2();
void prblm3();
void prblm4();
void prblm5();
void prblm6();
void prblm7();
bool fiveDigit(int);
void encrypt(int);
void decrypt(int);
string nameForNumber(long);
Primes* factor(int);
void prntPrm(Primes*);
Primes* addToPrime(Primes*,int&,int,int&);

//Execution Begins Here
int main(int argc, char** argv) {
    //Declare Variables
    char choice;
    
    //Loop and Display Menu
    do{
        menu();
        cin>>choice;
        
        //Map Inputs to Outputs -> Process
        switch(choice){
            case '1':{prblm1();break;}
            case '2':{prblm2();break;}
            case '3':{prblm3();break;}
            case '4':{prblm4();break;}
            case '5':{prblm5();break;}
            case '6':{prblm6();break;}
            case '7':{prblm7();break;}
            default: cout<<"Exiting Menu"<<endl;
        }
    }while(choice<'8');
    
    //Exit the Program - Cleanup
    return 0;
}
void menu(){
    //Display Menu
    cout<<endl<<"Choose from the following Menu"<<endl;
    cout<<"Type 1 for Problem 1"<<endl;
    cout<<"Type 2 for Problem 2"<<endl;
    cout<<"Type 3 for Problem 3"<<endl;
    cout<<"Type 4 for Problem 4"<<endl;
    cout<<"Type 5 for Problem 5"<<endl;
    cout<<"Type 6 for Problem 6"<<endl;
    cout<<"Type 7 for Problem 7"<<endl;
}

// Problem 1
void prblm1(){
    cout<<"Problem 1"<<endl;
    
    string name,address;
    int checks,deposits,account;
    float balance,sum=0,diff=0,total=0,current;
    Customer* customer=new Customer;
    
    cout<<"Bank Account"<<endl;
    cout<<"Enter the customer's name: ";
    cin.ignore();
    getline(cin,name);
    customer->name=name;
    cout<<"Enter the address: ";
    getline(cin,address);
    customer->address=address;
    cout<<"Enter the five digit account number: ";
    cin>>account;
    
    while(!fiveDigit(account)){
        cout<<"Invalid account number. Please enter a 5 digit account number: ";
        cin>>account;
    }
    customer->account=account;
    cout<<"Enter the account balance: ";
    cin>>balance;
    sum=sum+balance;
    cout<<"How many checks did you write this month?: ";
    cin>>checks;
    for(int i=0;i<checks;i++){
        cout<<"Enter the current check amount: ";
        cin>>current;
        customer->ctotal[i]=current;
        diff+=current;
    }
    cout<<"Total amount from checks: "<<diff<<endl;
    cout<<"How many deposits would you like to enter for this month?: ";
    cin>>deposits;
    for(int i=0;i<deposits;i++){
        cout<<"Enter the current deposit amount: ";
        cin>>current;
        customer->dtotal[i]=current;
        sum+=current;
    }
    cout<<endl;
    cout<<"Deposits: "<<sum<<endl;
    total=sum-diff;
    cout<<"Account balance at the end of the month is: "<<total<<endl;
    if(total<0){
        cout<<"The account has been overdrawn. An additional $20 dollar fee has been accessed. The new balance is: "<<total-20<<endl;
    }
    cout<<customer->name<<" at "<<customer->address<<" with the account number of "<<customer->account<<" has a balance of $"<<total<<endl;
}    
// Problem 2
void prblm2(){
    cout<<"Problem 2"<<endl;
    string compName;
    string address;
    int numOfEmp = 0;

    cout<<"Enter company name: ";
    cin>>compName;
    cout<<"Enter company address: ";
    cin.ignore();
    getline(cin,address);
    
    cout<<"Enter number of employees"<<endl;
    cin>>numOfEmp;
    
    while(numOfEmp<=0){
        cout<<"incorrect Employee size, please try again"<<endl;
        cin>>numOfEmp;
    }    
    Employee* ary=  new Employee[numOfEmp];

    for(int i =0;i<numOfEmp;i++){
        Employee emp;
        cout<<"Enter employee name: ";
        cin>>emp.name;

        cout<<"Enter employee's hours worked: ";
        cin>>emp.hrw;
        if(emp.hrw<0){break;}

        cout<<"Enter employee's pay rate: ";
        cin>>emp.pr;
        if(emp.pr<0){break;}
        
        ary[i] =  emp;
    }

    for(int i=0;i<numOfEmp;i++){
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
}

// Problem 3
void prblm3(){
    cout<<"Problem 3"<<endl;
    cout<<"It's in another project called Midterm.";
}

// Problem 4
void prblm4(){
    cout<<"Problem 4"<<endl;
    int number;
    cout<<"Enter the number to be encrypted: ";
    cin>>number;
    encrypt(number);
    cout<<"Enter the number to be decrypted: ";
    cin>>number;
    decrypt(number);
}

// Problem 5
void prblm5(){
    cout<<"Problem 5"<<endl;
    cout<<"a) Using a byte variable, both unsigned and signed, the largest n where n!factorial that can be calculated is 5, because 6!=720, which is largest than the bounds of byte variable ranging from -128 to 127."<<endl;
    cout<<"b) The largest factorial using unsigned char is 5."<<endl;
    cout<<"b) The largest factorial using signed char is 5."<<endl;
    cout<<"b) The largest factorial using unsigned short is 8."<<endl;
    cout<<"b) The largest factorial using signed short is 7."<<endl;
    cout<<"b) The largest factorial using unsigned int is 12."<<endl;
    cout<<"b) The largest factorial using signed int is 12."<<endl;
    cout<<"b) The largest factorial using long int is 12."<<endl;
    cout<<"b) The largest factorial using signed long int is 12."<<endl;
    cout<<"b) The largest factorial using unsigned long int is 12."<<endl;
    cout<<"b) The largest factorial using float is 34."<<endl;
    cout<<"b) The largest factorial using double is 170."<<endl;
}

// Problem 6
void prblm6(){
    cout<<"Problem 6"<<endl;
    cout<<"a) The conversion of 2.875 into binary, octal, and hex"<<endl<<"Binary: "<<"10.111"<<endl<<"Octal: "<<"2.7"<<endl<<"Hex: "<<"2E"<<endl<<"8 digit hex number representation using 4 byte float specification: "<<"5C000002"<<endl;
    cout<<"The conversion of 0.1796875 into binary, octal, and hex"<<endl<<"Binary: "<<"0010111"<<endl<<"Octal: "<<"0.134"<<endl<<"Hex: "<<"0.2E"<<endl<<"8 digit hex number representation using 4 byte float specification: "<<"5C0000FE"<<endl;
    cout<<"b) The conversion of -2.875 into binary, octal, and hex"<<endl<<"Binary: "<<"-10.111"<<endl<<"Octal: "<<"-2.7"<<endl<<"Hex: "<<"-2E"<<endl<<"8 digit hex number representation using 4 byte float specification: "<<"A4000002"<<endl;
    cout<<"The conversion of -0.1796875 into binary, octal, and hex"<<endl<<"Binary: "<<"-0010111"<<endl<<"Octal: "<<"-0.134"<<endl<<"Hex: "<<"-0.2E"<<endl<<"8 digit hex number representation using 4 byte float specification: "<<"A40000FE"<<endl;
    cout<<"c) The decimal number of 59999901 is 1.4"<<endl;
    cout<<"The decimal number of 59999902 is 2.8"<<endl;
    cout<<"The decimal number of A66667FE is -0.175"<<endl;
}

// Problem 7
void prblm7(){
    cout<<"Problem 7"<<endl;
    int number;
    cout<<"Give me a number to factor: ";
    cin>>number;
    cout<<"Factors of "<<number<<": ";
    Primes* prm = factor(number);
    prntPrm(prm);
    delete prm;
}

bool fiveDigit(int number){
   //char *intStr = itoa(number);
   return true;// (strlen(intStr)==5);
    
    
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
Primes* factor(int num){
    Primes* primes= new Primes;
    int nPrimes=0;
    while (num%2==0){
       primes = addToPrime(primes,nPrimes,2,num);
    }
    for(int j=3;j<=sqrt(num);j=j+2){
       while(num%j==0){
        primes = addToPrime(primes,nPrimes,j,num);
        }
    }
    if(num!=0&&num!=1){
        primes = addToPrime(primes,nPrimes,num,num);
    }
    primes->nPrimes=int(nPrimes);
    return primes;
}
Primes* addToPrime(Primes* primes,int& nPrimes, int number,int& num){
    bool found=false;
    for(int i=0;i<nPrimes;i++){
        if (primes->prime[i].prime==number){
            primes->prime[i].power=(char)(int(primes->prime[i].power)+1);
            num=num/number;
            found=true;
            break;
        }
    }
    if(!found){
        Prime* newArr=new Prime[nPrimes+1];
        for(int i=0;i<nPrimes;i++){
            newArr[i] = primes->prime[i];   
        }
        Prime newPri;
        newPri.prime=number;
        newPri.power=(char)1; 
        newArr[nPrimes]=newPri;
        
        
        primes->prime=newArr;
        nPrimes=nPrimes+1;
        num=num/number;
        }
    return primes;
}

void prntPrm(Primes* prme){
    if (prme->nPrimes>0){
        cout<<prme->prime[0].prime<<"^"<<(int)prme->prime[0].power;
    }
    for (int i =1; i<prme->nPrimes;i++){
        cout<<"*"<<prme->prime[i].prime<<"^"<<(int)prme->prime[i].power;
    }
}