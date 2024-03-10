// Copyright 2022 UNN-IASR
#include <ctype.h>
#include <math.h>
#include "fun.h"

unsigned int faStr1(const char* str) {
    int i = 0;
    bool inWord = false;
    bool Have_Numbers = false;
    int Count_Words = 0;
    while (str[i] != '\0') {
        if (isdigit(str[i]) && Have_Numbers == false) {
            Have_Numbers = true;
        }
        if (str[i] != ' ' && inWord == false) {
            inWord = true;
            Count_Words++;
        } else if (str[i] == ' ' && inWord == true) {
            if (Have_Numbers == true) {
                Have_Numbers = false;
                Count_Words--;
            }
            inWord = false;
        }
        i++;
    }
    if (inWord == true && Have_Numbers == true) {
        Count_Words--;
        Have_Numbers = false;
    }
    return Count_Words;
}

unsigned int faStr2(const char* str) {
    int Count_Words = 0;
    bool inW = false;
    int i = 0;
    bool NoL = false;
    while (str[i] != '\0') {
        if (str[i] != ' ' && inW == false && isupper(str[i])) {
            inW = true;
            Count_Words++;
        } else if (str[i] != ' ' && inW == true && !islower(str[i])) {
            if (NoL == false) {
                NoL = true;
            }
        } else if (str[i] == ' ' && inW == true) {
            if (NoL == true) {
                Count_Words--;
                NoL = false;
            }
            inW = false;
        }
        i++;
    }
    return Count_Words;
}

unsigned int faStr3(const char* str) {
    bool inWord = false;
    double Count_Length = 0;
    double Count_Words = 0;
    int i = 0;
    while (str[i] != '\0') {
        if (str[i] != ' ' && inWord == false) {
            inWord = true;
            Count_Words++;
            Count_Length++;
        } else if (str[i] ==' ' && inWord == true) {
            inWord = false;
        } else if (str[i] != ' ' && inWord == true) {
            Count_Length++;
            inWord = true;
        }
        i++;
    }
    int Average_Value = round(Count_Length / Count_Words);
    return Average_Value;
}
