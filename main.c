#include <stdio.h>
#include "NumClass.h"

int main() {
    int num1;
    int num2;

    printf("Enter the first number: ");
    scanf("%d", &num1);


    printf("Enter the second number: ");
    scanf("%d", &num2);

    int min = 0;
    int max = 0;

    if(num1>num2){
        min = num2;
        max = num1;
    } else{
        max = num2;
        min = num1;
    }

    printf("The Armstrong numbers are:");
    for(int i=min; i <= max;i++){
        if (isArmstrong(i)) {
            printf(" %d", i);
        } 
    }

    printf("\nThe Palindrome numbers are:");
    for(int i=min; i <= max;i++){
        if (isPalindrome(i)) {
            printf(" %d", i);
        } 
    }

        printf("\nThe Prime numbers are:");
    for(int i=min; i <= max;i++){
        if (isPrime(i)) {
            printf(" %d", i);
        } 
    }

        printf("\nThe Strong numbers are:");
    for(int i=min; i <= max;i++){
        if (isStrong(i)) {
            printf(" %d", i);
        } 
    }

    return 0;
}
