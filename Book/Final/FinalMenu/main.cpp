/* 
 * File:   main.cpp
 * Author: Attila Koksal
 * Created on June 3, 2021, 3:30 PM
 * Purpose:  Menu using Functions, extend for final       
 */

//System Libraries
#include <iostream>  //I/O Library
#include <cmath>
using namespace std;

class Prob1Random{
    private:
        char*set;//The set of numbers to draw random numbers from
        char nset;//The number of variables in the sequence
        int *freq;//Frequency of all the random numbers returned
        int numRand;//The total number of times the random number function is called
    public:
        Prob1Random(const char numSize,const char *arraySet){//Constructor
            nset=numSize;
            numRand=0;
            set=new char[numSize];
            for(int i=0;i<nset;i++){
                set[i]=arraySet[i];
            }
            freq=new int[numSize];
            for(int i=0;i<nset;i++){
                freq[i]=0;
            }
        }
        ~Prob1Random(void){//Destructor
            delete []set;
            delete []freq;
        }
        char randFromSet(void){//Returns a random number from the set
            int random=set[rand()%nset]; 
            numRand++;
            for(int i=0;i<nset;i++){
                if(set[i]==random){
                    freq[i]++;
                }
            }
            return random;
        }
        int *getFreq(void)const{//Returns the frequency histogram
            return freq;
        }
        char *getSet(void)const{//Returns the set used
            return set;
        }
        int getNumRand(void)const{//Gets the number of times randFromSet has been called
            return numRand;
        }
};

class SavingsAccount{
    public:
        SavingsAccount(float balance){//Constructor
            Balance=balance;
            FreqWithDraw=0;
            FreqDeposit=0;
        }
        void Transaction(float transAmount){//Procedure
            if(transAmount>0){
                Balance=Deposit(transAmount);
            }
            else if(transAmount<0){
                Balance=Withdraw(-transAmount);
            }
        }
        float Total(float savings=0,int time=0){//Savings Procedure
            float newBalance=Balance;
            for(int i=0;i<time;i++){
                newBalance=newBalance*(savings+1.0);
            }
            return newBalance;
        }
        float TotalRecursive(float savings=0,int timeLeft=0){
            Balance=Balance*(savings+1.0);
            timeLeft--;
            if(timeLeft>0){
                TotalRecursive(savings,timeLeft);
            }
            return Balance;
        }
        void toString(){//Output Properties
            cout<<"Balance="<<Balance<<endl;
            cout<<"WithDraws="<<FreqWithDraw<<endl;
            cout<<"Deposit="<<FreqDeposit<<endl;
        }
    private:
        float Withdraw(float transA){//Utility Procedure
            FreqWithDraw++;
            float newBalance=Balance-transA;
            if(newBalance<0){
                cout<<"WithDraw not Allowed"<<endl;
                newBalance=Balance;
            }
            return newBalance;
        }
        float Deposit(float transA){//Utility Procedure
            FreqDeposit++;
            return Balance+transA;
        }
        float Balance;//Property
        int FreqWithDraw;//Property
        int FreqDeposit;//Property
};

class Employee{
    public:
        Employee(char myName[],char jobTitle[],float hourlyRate){//Constructor
            for(int i=0;i<(sizeof(&myName)/(sizeof(char)));i++){
                MyName[i]=myName[i];
            }
            for(int i=0;i<(sizeof(&jobTitle)/(sizeof(char)));i++){
                JobTitle[i]=jobTitle[i];
            }
            if(hourlyRate<=0.0||hourlyRate>=200.0){
                cout<<"Unacceptable Hourly Rate"<<endl;
                HourlyRate=0;
            }
            else{
                HourlyRate=hourlyRate;
            }            
            HoursWorked=0;
            GrossPay=0;
            NetPay=0;
        }
        float CalculatePay(float hourlyR,int hoursWorked){//Procedure
            return getNetPay(getGrossPay(setHourlyRate(hourlyR),setHoursWorked(hoursWorked)));
        }
        float getGrossPay(float hourlyRate,int hoursWorked){//Procedure
            float grosspay=0;
            if(hoursWorked<=40){
                grosspay=hourlyRate*hoursWorked;
            }
            else if(hoursWorked>40&&hoursWorked<=50){
                float straightPay=hourlyRate*40;
                grosspay=straightPay+((hourlyRate*(hoursWorked-40))*1.5);
            }
            else if(hoursWorked>50){
                grosspay=(hourlyRate*40)+((hourlyRate*10)*1.5)+((hourlyRate*(hoursWorked-50))*2.0);
            }
            cout<<grosspay<<"---------------------------"<<endl;
            GrossPay=grosspay;
            return grosspay;
        }
        float getNetPay(float gross){//Procedure
            float difference=gross-Tax(gross);
            NetPay=difference;
            return difference;
        }
        void toString(){//Procedure
            cout<<"Name = "<<MyName<<" Job Title = "<<JobTitle<<endl;
            cout<<"Hourly Rate = "<<HourlyRate<<" Hours Worked = "<<HoursWorked<<" Gross Pay = "<<GrossPay<<" Net Pay = "<<NetPay<<endl;
        }
        int setHoursWorked(int hoursWorked){//Procedure
            if(hoursWorked<=0||hoursWorked>=84){
                cout<<"Unacceptable Hours Worked"<<endl;
                HoursWorked=0;
            }
            else{
                HoursWorked=hoursWorked;
            }
            return HoursWorked;
        }
        float setHourlyRate(float hourlyRate){//Procedure
            if(hourlyRate<=0.0||hourlyRate>=200.0){
                cout<<"Unacceptable Hourly Rate"<<endl;
                HourlyRate=0;
            }
            else{
                HourlyRate=hourlyRate;
            }
            return HourlyRate;
        }
    private:
        double Tax(float grossPay){//Utility Procedure
            double tax=0;
            if(grossPay<=500){
                tax=grossPay*0.1;
            }
            else if(grossPay>500&&grossPay<=1000){
                tax=(500*0.1)+((grossPay-500)*0.2);
            }
            else if(grossPay>1000){
                tax=(500*0.1)+(500*0.2)+((grossPay-1000)*0.3);
            }
            return tax;
        }
        char MyName[20];//Property
        char JobTitle[20];//Property
        float HourlyRate;//Property
        int HoursWorked;//Property
        float GrossPay;//Property
        float NetPay;//Property
};

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
            default: cout<<"Exiting Menu"<<endl;
        }
    }while(choice<'7');
    
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
}

// Problem 1
void prblm1(){
    cout<<"Problem 1"<<endl;
    char n=5;
    char rndseq[]={18,33,56,79,124};
    int ntimes=100000;
    Prob1Random a(n,rndseq);
  
    for(int i=1;i<=ntimes;i++){
        a.randFromSet();
    }
    int *x=a.getFreq();
    char *y=a.getSet();
    for(int i=0;i<n;i++){
        cout<<int(y[i])<<" occurred "<<x[i]<<" times"<<endl;
    }
    cout<<"The total number of random numbers is "<<a.getNumRand()<<endl;
}

// Problem 2
void prblm2(){
    cout<<"Problem 2"<<endl;
    
}

// Problem 3
void prblm3(){
    cout<<"Problem 3"<<endl;
    
}

// Problem 4
void prblm4(){
    cout<<"Problem 4"<<endl;
    SavingsAccount mine(-300);

    for(int i=1;i<=10;i++){
        mine.Transaction((float)(rand()%500)*(rand()%3-1));
    }
    mine.toString();
    cout<<"Balance after 7 years given 10% interest = "<<mine.Total((float)(0.10),7)<<endl;
    cout<<"Balance after 7 years given 10% interest = "<<mine.TotalRecursive((float)(0.10),7)<<" Recursive Calculation "<<endl;
}

// Problem 5
void prblm5(){
    cout<<"Problem 5"<<endl;
    Employee Mark("Mark","Boss",215.50);
    Employee Mary("Mary","VP",50.0);

    Mark.setHoursWorked(-3);
    Mark.toString();
    Mark.CalculatePay(Mark.setHourlyRate(20.0),Mark.setHoursWorked(25));
    Mark.toString();
    Mark.CalculatePay(Mark.setHourlyRate(40.0),Mark.setHoursWorked(25));
    Mark.toString();
    Mark.CalculatePay(Mark.setHourlyRate(60.0),Mark.setHoursWorked(25));
    Mark.toString();

    Mary.toString();
    Mary.CalculatePay(Mary.setHourlyRate(50.0),Mary.setHoursWorked(40));
    Mary.toString();
    Mary.CalculatePay(Mary.setHourlyRate(50.0),Mary.setHoursWorked(50));
    Mary.toString();
    Mary.CalculatePay(Mary.setHourlyRate(50.0),Mary.setHoursWorked(60));
    Mary.toString();
}

// Problem 6
void prblm6(){
    cout<<"Problem 6"<<endl;
    
}