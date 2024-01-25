#include <stdio.h>
#include "NumClass.h"

int isArmstrong(int num){
    int numOfdigit=getNumOfdigit(num);

    int sum=0;
    int newNumber=num;

    while(newNumber!=0){
        sum+= power(newNumber % 10, numOfdigit);
        newNumber /= 10;
    }

    if(sum == num){
        return 1;
    }

    return 0;
}

int power(int num, int exponent){

    if(exponent == 0){
        return 1;
    }
    int sum=1;

    for(int i=0;i<exponent;i++){
        sum *= num;
    }

    return sum;
}

int getNumOfdigit(int num){
    int count=0;
    int newNumber=num;
    while(newNumber!=0){
        count++;
        newNumber /= 10; 
    }

    return count;
}

int isPalindrome(int num){
    int start = 0;
    int end = getNumOfdigit(num) - 1;

    while(start < end){
        int digitStart = num / power(10, end) % 10;
        int digitEnd = num / power(10, start) % 10;

        if(digitStart != digitEnd){
            return 0;
        }

        start++;
        end--;
    }

    return 1;
}
