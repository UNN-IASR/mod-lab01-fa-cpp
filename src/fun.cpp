// Copyright 2022 UNN-IASR
#include "fun.h"
#include <iostream>
#include <string>
#include <math.h>
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
    bool flag = false;
    int i = 0;
    int count = 0;
    int result = 0;
    while (str[i]) {
        if (!flag && str[i] != ' ' && str[i] >= 65 && str[i] <= 90) {
            flag = true;
            count = 1;
        }
        else if (flag && str[i] == ' ') {
            flag = false;
            result += count;
        }
        else if (str[i] < 97 || str[i] > 122) {
            count = 0;
        }
        i++;
    }
    return result;
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
