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
    }
    return Count_Words;
}

unsigned int faStr2(const char* str) {
    int Count_Words = 0;
    bool inWord = false;
    int i = 0;
    bool NoLower = false;
    while (str[i] != '\0') {
        if (str[i] != ' ' && inWord == false && isupper(str[i])) {
            inWord = true;
            Count_Words++;
        } else if (str[i] != ' ' && inWord == true && !islower(str[i]) && NoLower == false) {
            NoLower = true;
        } else if (str[i] == ' ' && inWord == true) {
            if(NoLower == true){
                Count_Words--;
                NoLower = false;
            }
            inWord = false;
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
    while (str[i] != '\0'){
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
