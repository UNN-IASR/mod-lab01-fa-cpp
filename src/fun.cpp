// Copyright 2022 UNN-IASR
#include "fun.h"
#include <cmath>

unsigned int faStr1(const char *str) {
    unsigned int counter = 0;
    bool wordFlag = false;
    bool noNumFlag = true;
    for (int i = 0; i<sizeof(str); i++) {
        if (str[i] == ' ') {
            if (wordFlag && noNumFlag) counter++;
            wordFlag = false;
            noNumFlag == true;
        }
        else {
            wordFlag = true;
            if ((int)str[i] >= 48 && (int)str[i] <= 57)noNumFlag = false;
        }
    }
    return counter;
}

unsigned int faStr2(const char *str) {
    unsigned int counter = 0;
    bool wordFlag = false;
    bool upperCaseFlag = false;
    bool latinWord = true;
    for (int i = 0; i<sizeof(str); i++) {
        if (str[i] == ' ') {
            if (wordFlag && noNumFlag && bool latinWord = true;) counter++;
            wordFlag = false;
            upperCaseFlag = false;
            latinWord = true;
        }
        else {
            if(wordFlag==false && (int)str[i] >= 65 && (int)str[i] <= 90) upperCaseFlag = true;
            if ((int)str[i] <= 65 || ((int)str[i] >= 91 && (int)str[i] <= 96) || (int)str[i] >= 123) latinWord = false;
            wordFlag = true;
        }
    }
    return counter;
}

unsigned int faStr3(const char *str) {
    unsigned int counter = 0;
    bool wordFlag = false;
    float totalLength = 0;
    int wordLength = 0;
    
    for (int i = 0; i<sizeof(str); i++) {
        if (str[i] == ' ') {
            if (wordFlag) counter++;
            wordFlag = false;
            totalLenght += wordLength;
            wordLength = 0;
        }
        else {
            wordLength += 1;
            wordFlag = true;
        }
    }
    return round(totalLength/counter);
}
