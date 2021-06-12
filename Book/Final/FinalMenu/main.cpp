/* 
 * File:   main.cpp
 * Author: Attila Koksal
 * Created on June 3, 2021, 3:30 PM
 * Purpose:  Menu using Functions, extend for final       
 */

//System Libraries
#include <iostream>  //I/O Library
#include <cmath>
#include <fstream> // stream!   
#include <string>
#include <string.h>
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

template<class T>
class Prob3Table{
    protected:
        int rows;//Number of rows in the table
        int cols;//Number of cols in the table
        T *rowSum;//RowSum array
        T *colSum;//ColSum array
        T *table;//Table array
        T grandTotal;//Grand total
        void calcTable(void);//Calculate all the sums
    public:
        Prob3Table(char *fileName,int row,int col){
            rows = row;
            cols=col;
            table = new int[row*col];
            ifstream infile;
            infile.open(fileName,ios::in);
            string itemStr = "";
            int item = 0;
            int index= 0;
            while(infile>>itemStr){
                item = stoi(itemStr);
                table[index] = item;
                index++;
            }
             infile.close();
            
        }
        ~Prob3Table(){delete [] table;delete [] rowSum;delete [] colSum;};
        const T *getTable(void){return table;};
        const T *getRowSum(void){return rowSum;};
        const T *getColSum(void){return colSum;};
        T getGrandTotal(void){return grandTotal;};
};

template<class T>
class Prob3TableInherited:public Prob3Table<T>{
    protected:
        T *augTable;//Augmented Table with sums
    public:
        Prob3TableInherited(char *fileName,int row,int col):Prob3Table<int>(fileName,row,col){
             augTable = new int[(row+1)*(col+1)];
             int* colSum = new int[col+1];
             
             for(int j=0;j<col;j++){
             colSum[j]=0;    
                 
             
             } 
             for(int i =0;i<row;i++){
                 int rowSum = 0;
                 for(int j=0;j<col;j++){
                     
                     augTable[i*(col+1)+j]=this->table[i*col+j];
                     rowSum+=this->table[i*col+j];
                     colSum[j]=colSum[j]+this->table[i*col+j];
                 }
                 augTable[i*(col+1)+col]=rowSum;
             }
             int rowSum = 0;
             
             for(int j=0;j<col;j++){
                     
                augTable[row*(col+1)+j]=colSum[j];
                rowSum=rowSum+colSum[j];
               
              }
            augTable[row*(col+1)+col]=rowSum;
            
        }
        
        
        
        ~Prob3TableInherited(){delete [] augTable;};//Destructor
        const T *getAugTable(void){return augTable;}; 
};

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
    Prob2Sort<char> rc;
    bool ascending=true;
    ifstream infile;
    infile.open("Problem2.txt",ios::in);
    char *ch2=new char[10*16];
    char *ch2p=ch2;
    
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
}

// Problem 3
void prblm3(){
    cout<<"Problem 3"<<endl;
    int rows=5;
    int cols=6;
    Prob3TableInherited<int> tab("Problem3.txt",rows,cols);
    const int *naugT=tab.getTable();
    const int *augT=tab.getAugTable();
    
    cout<<"Entering problem number 3"<<endl;
    for(int i=0;i<rows;i++){
        for(int j=0;j<cols;j++){
            cout<<naugT[i*cols+j]<<" ";
        }
        cout<<endl;
    }
    cout<<endl;
	
    for(int i=0;i<=rows;i++){
        for(int j=0;j<=cols;j++){
            cout<<augT[i*(cols+1)+j]<<" ";
        }
        cout<<endl;
    }
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
    cout<<"1) a) 3.75 in Binary: 11.11,Octal: 3.6,Hex: 3C"<<endl;
    cout<<"1) b) 0.7 in Binary: 10110011,Octal: 54631463,Hex: B3"<<endl;
    cout<<"1) c) 89.9 in Binary: 1011001.1110011,Octal: 131.71463,Hex: 59.E6"<<endl;
    cout<<"2) a) 3.75 in NASA: 400E000000000000"<<endl;
    cout<<"2) b) 0.7 in NASA: 3FE6666666666666"<<endl;
    cout<<"2) c) 89.9 in NASA: 405679999999999A"<<endl;
    cout<<"3) a) 3.75 in scaled binary 1: 11.1"<<endl;
    cout<<"3) b) 0.7 in scaled binary 2: 101100"<<endl;
    cout<<"3) c) 89.9 in scaled binary 3: 1011001.11"<<endl;
    cout<<"4) a) 3.75 in scaled binary 1(multiplied by 1 byte): 88.8"<<endl;
    cout<<"4) b) 0.7 in scaled binary 2(multiplied by 1 byte): 808800"<<endl;
    cout<<"4) c) 89.9 in scaled binary 3(multiplied by 1 byte): 8088008.88"<<endl;
    cout<<"5) a) 3.75 in IEE 754: 1.875"<<endl;
    cout<<"5) b) 0.7 in IEE 754: 1.4"<<endl;
    cout<<"5) c) 89.9 in IEE 754: 1.4046875"<<endl;
}