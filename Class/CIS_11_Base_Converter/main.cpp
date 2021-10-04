/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.cpp
 * Author: attil
 *
 * Created on October 4, 2021, 1:25 PM
 */

#include <cstdlib>
#include <iostream>

using namespace std;

/*
 * 
 */
int main(int argc, char** argv) {
    
    char digits[36] = {'0','1','2','3','4','5','6','7','8','9','A','B','C','D','E','F','G','H','I','J','K','L','M','N','O','P','Q','R','S','T','U','V','W','X','Y','Z'};
    char remainders[32];
    // initialize remainders array
    for(int i = 0; i < 32; i++){
        remainders[i] = 0;
    }
    int number, base;
    printf("Enter your base 10 number: ");
    scanf("%d", &number);
    prompt_base:
    printf("Enter base to convert to (>=2 and <=36): ");
    scanf("%d", &base);
    
    if(base < 2 || base > 36){
        printf("Base must be between 2 and 36\n");
        goto prompt_base;
    }
    
    int user_input = number;
    int index = 31; // start at top of remainder array
    
    for(int i = 0; i < 32; i++){
        remainders[index] = number % base;
        number = number / base;
        index--;
        if(number < base){
            break;
        }
    }
    
    // output
    printf("%d base 10 in base %d is: ", user_input, base);
    for(int i = 0; i < 32; i++){
        printf("%c", digits[remainders[i]]);
    }
    printf("\n");
    
    
    return 0;
}

