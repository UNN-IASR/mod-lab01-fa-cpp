// Copyright 2022 UNN-IASR
#include "fun.h"
#include <iostream>
#include <string>
#include<list>
unsigned int faStr1(const char *str) {
    int i = 0;
    bool space = false;
    bool stopCount = false;
    int count = 0;
    while (str[i]) {
        if (str[i] != ' ') {
            space = true;
        }
        if (str[i] >= '0' && str[i] <= '9') {
            stopCount = true;
        }
        if (str[i] == ' ' && space == true) {
            if (stopCount == false) {
                count++;
            }
            space = false;
            stopCount = false;
        }
        i++;
    }
    return count;
}

unsigned int faStr2(const char *str) {
    int iter = 0;
    unsigned int rezult = 0;
    bool Verification = true;
    bool VerifWorld = false;
    while (str[iter]) {
        if (!VerifWorld && str[iter] != ' ') 
        {
            VerifWorld = true;
            Verification = isupper(str[iter]);
        }
        else if (VerifWorld && str[iter] != ' ') {
            if (!islower(str[iter])) Verification = false;
        }
        if (VerifWorld && (str[iter] == ' ' || str[iter + 1] == '\0')) {
            if (Verification) rezult++ ;
            Verification = true;
            VerifWorld = false;
        }
        iter++;
    }
    return rezult;
}

unsigned int faStr3(const char *str) {
    bool Word = false;
    float Sum = 0;
    int Words = 0;
    while (*str != '\0') {
        if (*str == ' ') {
            if (Word) {
                Words++;
            }
            Word = false;
        }
        else {
            Word = true;
            Sum++;
        }
        str++;
    }
    if (Word) {
        Words++;
    }
    return std::round(Sum / Words);
}
