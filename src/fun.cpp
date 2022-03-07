// Copyright 2022 UNN-IASR
#include "fun.h"

unsigned int faStr1(const char *str) {
    bool hasNum = false;
    bool inWord = false;
    int i = 0;
    int count = 0;

    while (str[i]) {
        if (str[i] != ' ') {
            inWord = true;
            if (!hasNum) {
                if (isdigit(str[i])) {
                    hasNum = true;
                }
            }
        } else if (str[i] == ' ') {
            if (inWord) {
                if (!hasNum) {
                    count++;
                } else {
                    hasNum = false;
                }
                inWord = false;
            }
        }
        i++;
    }
    return count;
}

unsigned int faStr2(const char *str) {
    bool rightWord = false;
    bool inWord = false;
    bool firstWord = true;
    int i = 0;
    int count = 0;

    while (str[i]) {
        if (str[i] != ' ') {
            inWord = true;
            if (firstWord) {
                if (str[i] <='Z' && str[i] >='A') {
                    rightWord = true;
                }
                firstWord = false;
            } else if (rightWord) {
                if (!(str[i] <= 'z' && str[i] >= 'a')) {
                    rightWord = false;
                }
            }
        } else if (str[i] == ' ') {
            if (inWord) {
                if (rightWord) {
                    count++;
                    rightWord = false;
                }
                inWord = false;
                firstWord = true;
            }
        }
        i++;
    }
    return count;
}

unsigned int faStr3(const char *str) {
    bool inWord = false;
    bool firstWord = true;
    int i = 0;
    int count = 0;
    int wordNumber = 0;
    int averageLength = 0;

    while (str[i]) {
        if (str[i] != ' ') {
            if (firstWord) {
                wordNumber++;
                firstWord = false;
            }
            inWord = true;
            count++;
        } else if (str[i] == ' ') {
                inWord = false;
                firstWord = true;
        }
        i++;
    }
    averageLength = round(count / wordNumber);
    return averageLength;
}
