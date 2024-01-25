#include <stdio.h>
#include "NumClass.h"

int isPrime(int num) {
    if (num <= 1) {
        return 0;  
    }

    for (int i = 2; i * i <= num; i++) {
        if (num % i == 0) {
            return 0; 
        }
    }

    return 1;
}


int isStrong(int num) {
    int sum = 0;
    int newNumber = num;

    while (newNumber != 0) {
        sum += factorial(newNumber % 10);
        newNumber = newNumber / 10;
    }

    return (sum == num);
}


int factorial(int n) {
    if (n == 0 || n == 1) {
        return 1;
    } else {
        return n * factorial(n - 1);
    }
}