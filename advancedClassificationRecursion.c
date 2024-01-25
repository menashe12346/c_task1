#include <stdio.h>
#include "NumClass.h"

int isArmstrongRec(int num, int originalNum, int numOfdigit) {
    if (num == 0) {
        return (originalNum == 0);
    }
    return power(num % 10, numOfdigit) + isArmstrongRec(num / 10, originalNum, numOfdigit);
}

int isArmstrong(int num) {
    int numOfdigit = getNumOfdigit(num);
    return (isArmstrongRec(num, num, numOfdigit) == num);
}

int power(int num, int exponent) {
    if (exponent == 0) {
        return 1;
    }
    return num * power(num, exponent - 1);
}

int getNumOfdigitRec(int num, int count) {
    if (num == 0) {
        return count;
    }
    return getNumOfdigitRec(num / 10, count + 1);
}

int getNumOfdigit(int num) {
    return getNumOfdigitRec(num, 0);
}

int isPalindromeRec(int num, int start, int end) {
    if (start >= end) {
        return 1;
    }

    int digitStart = num / power(10, end) % 10;
    int digitEnd = num / power(10, start) % 10;

    return (digitStart == digitEnd) && isPalindromeRec(num, start + 1, end - 1);
}

int isPalindrome(int num) {
    int start = 0;
    int end = getNumOfdigit(num) - 1;
    return isPalindromeRec(num, start, end);
}
