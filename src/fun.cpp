// Copyright 2022 UNN-IASR
#include "fun.h"
#include <cmath>

unsigned int faStr1(const char* str) {
    int counter = 0;
    bool wordFlag = false;
    bool noNumFlag = true;
    for (int i = 0; str[i] != '\0'; i++) {
        if (str[i] == ' ') {
            if (wordFlag && noNumFlag) counter++;
            wordFlag = false;
            noNumFlag = true;
        }
        else {
            wordFlag = true;
            if (str[i] >= '0' && str[i] <= '9')noNumFlag = false;
        }
    }
    return counter;
}

unsigned int faStr2(const char* str) {
    int counter = 0;
    bool wordFlag = false;
    bool upperCaseFlag = false;
    bool latinWord = true;
    for (int i = 0; str[i] != '\0'; i++) {
        if (str[i] == ' ') {
            if (wordFlag && upperCaseFlag && latinWord) counter++;
            wordFlag = false;
            upperCaseFlag = false;
            latinWord = true;
        }
        else {
            if (wordFlag == false && str[i] >= 'A' && str[i] <= 'Z') upperCaseFlag = true;
            if ((int)str[i] < 'A' || ((int)str[i] > 'Z' && (int)str[i] <= 'a') || (int)str[i] > 'z') latinWord = false;
            wordFlag = true;
        }
    }
    return counter;
}

unsigned int faStr3(const char* str) {
    int counter = 0;
    bool wordFlag = false;
    float totalLength = 0;
    int wordLength = 0;

    for (int i = 0; str[i] != '\0'; i++) {
        if (str[i] == ' ') {
            if (wordFlag) counter++;
            wordFlag = false;
            totalLength += wordLength;
            wordLength = 0;
        }
        else {
            wordLength += 1;
            wordFlag = true;
        }
    }
    totalLength += wordLength;
    counter++;
    return round(totalLength / counter);
}
