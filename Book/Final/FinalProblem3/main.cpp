/* 
 * File:   main.cpp
 * Author: Attila Koksal
 * Created on June 5, 2021, 4:35 PM
 * Purpose:  CPP Template 
 *           Problem 3 of Final
 */

//System Libraries
#include <iostream>  //I/O Library
using namespace std;

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
        Prob3Table(char *,int,int);//Constructor then Destructor
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
        Prob3TableInherited(char *,int,int);//Constructor
        ~Prob3TableInherited(){delete [] augTable;};//Destructor
        const T *getAugTable(void){return augTable;}; 
};

//User Libraries

//Global Constants
//Math, Science, Universal, Conversions, High Dimensioned Arrays

//Function Prototypes

//Execution Begins Here
int main(int argc, char** argv) {
    //Initialize the Random Number Seed
    
    //Declare Variables
    int rows=5;
    int cols=6;
    Prob3TableInherited<int> tab("Problem3.txt",rows,cols);
    const int *naugT=tab.getTable();
    const int *augT=tab.getAugTable();
    
    //Initialize Variables
    
    //Map Inputs to Outputs -> Process
    
    //Display Inputs/Outputs
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
    
    //Exit the Program - Cleanup
    return 0;
}