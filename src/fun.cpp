// Copyright 2022 UNN-IASR
#include "fun.h"
#include <ctype.h>
#include <math.h>

unsigned int faStr1(const char* str) {
    bool inWord = false;
    bool thisNumber = false;
    int count = 0;
    int i = 0;
    while (str[i] != '\0') {
        if (str[i] != ' ' && inWord == false) {
            inWord = true;
            thisNumber = isdigit(str[i]);
        }
        else if (str[i] != ' ' && inWord == true) {
            if (thisNumber == false)
                thisNumber = isdigit(str[i]);
        }
        else if (str[i] == ' ' && inWord == true) {
            if (thisNumber == false)
                count++;
            inWord = false;
        }
        i++;
    }
    return count;
}

unsigned int faStr2(const char* str) {
    bool inWord = false;
    bool isright = true;
    int count = 0;
    int i = 0;
    while (str[i] != '\0') {
        if (str[i] != ' ' && inWord == false) {
            inWord = true;
            isright = isupper(str[i]);
        }
        else if (str[i] != ' ' && inWord == true) {
            if (isright == true) isright = islower(str[i]);
        }
        else if (str[i] == ' ' && inWord == true) {
            if (isright == true)
                count++;
            inWord = false;
        }
        i++;
    }
    return count;
}

unsigned int faStr3(const char* str) {
    bool inWord = false;
    int countWord = 0;
    int countLength = 0;
    int i = 0;
    while (str[i] != '\0') {
        if (str[i] != ' ' && inWord == false) {
            inWord = true;
            countLength++;
            countWord++;
        }
        else if (str[i] != ' ' && inWord == true) {
            countLength++;
        }
        else if (str[i] == ' ' && inWord == true) {
            inWord = false;
        }
        i++;
    }
    double length = static_cast<double>(countLength);
    return static_cast<int>(round(length / countWord));
}
