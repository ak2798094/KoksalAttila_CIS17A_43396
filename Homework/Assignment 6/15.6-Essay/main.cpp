/* 
 * File:   main.cpp
 * Author: Attila Koksal
 * Created on May 26, 2021, 2:35 PM
 * Purpose:  CPP Template 
 *           To be copied for each Assignment Problem
 */

//System Libraries
#include <iostream>  //I/O Library
using namespace std;

const int GRAMMAR=30;
const int SPELLING=20;
const int LENGTH=20;
const int CONTENT=30;

class GradedActivity{
protected:
   double score;
public:
   GradedActivity(){ 
       score=0.0; 
   }
   GradedActivity(double s){ 
       score=s; 
   }
   void setScore(double s){ 
       score=s; 
   }
   double getScore()const{ 
       return score; 
   }
   char getLetterGrade()const;
};

class Essay:public GradedActivity{
private:
    int grammar;
    int spelling;
    int length;
    int content;

public:
    Essay():GradedActivity(){
        grammar=0;
        spelling=0;
        length=0;
        content=0;
    }
    Essay(int g,int s,int l,int c):GradedActivity(g+s+l+c){
        grammar=g;
        spelling=s;
        length=l;
        content=c;
    }
    int getGrammar()const{
        return grammar;
    }
    int getSpelling()const{
        return spelling;
    }
    int getLength()const{
        return length;
    }
    int getContent()const{
        return content;
    }
    void setGrammar(int g){
        while(g<0||g>GRAMMAR){
            cout<<"Grammar points should be between";
            cout<<" 0 and "<<GRAMMAR<<"!";
            cout<<" Enter again: ";
            cin>>g;
        }
        grammar=g;
        setScore(grammar+spelling+length+content);
    }
    void setSpelling(int s){
        while(s<0||s>SPELLING){
            cout<<"Spelling points should be between";
            cout<<" 0 and "<<SPELLING<<"!";
            cout<<" Enter again: ";
            cin>>s;
        }
        spelling=s;
        setScore(grammar+spelling+length+content);
    }
    void setLength(int l){
        while(l<0||l>LENGTH){
            cout<<"Correct Length points should be between";
            cout<<" 0 and "<<LENGTH<<"!";
            cout<<" Enter again: ";
            cin>>l;
        }
        length=l;
        setScore(grammar+spelling+length+content);
    }
    void setContent(int c){
        while(c<0||c>CONTENT){
            cout<<"Content points should be between";
            cout<<" 0 and "<<CONTENT<<"!";
            cout<<" Enter again: ";
            cin>>c;
        }
        content=c;
        setScore(grammar+spelling+length+content);
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
    Essay essay;
    int points;
    
    //Initialize Variables
    
    //Map Inputs to Outputs -> Process
    
    //Display Inputs/Outputs

    //display current points
    cout<<"Enter grammar points: ";
    cin>>points;
    essay.setGrammar(points);
    cout<<"Enter spelling points: ";
    cin>>points;
    essay.setSpelling(points);
    cout<<"Enter correct length points: ";
    cin>>points;
    essay.setLength(points);
    cout<<"Enter content points: ";
    cin>>points;
    essay.setContent(points);
    cout<<"Score: "<<essay.getScore()<<endl;
    cout<<"Letter Grade: "<<essay.getLetterGrade()<<endl;
    
    //Exit the Program - Cleanup
    return 0;
}
char GradedActivity::getLetterGrade()const{
   char letterGrade;
   if(score>89){
      letterGrade='A';
   }else if(score>79){
      letterGrade='B';
   }else if(score>69){
      letterGrade='C';
   }else if(score>59){
      letterGrade='D';
   }else{
      letterGrade='F';
   }
   return letterGrade;
}