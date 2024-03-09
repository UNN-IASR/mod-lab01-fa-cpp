// Copyright 2022 UNN-IASR
#include "fun.h"

unsigned int faStr1(const char* str) {
    bool inWord = false;
    bool hasNumber = false;
    int count = 0;
    int i = 0;

    while (str[i]) {
        if ((str[i] != ' ') && (inWord == false)) {
            inWord = true;
            hasNumber = (str[i] <= '9') && (str[i] >= '0');
            if (!hasNumber) count++;
        }
        else if ((str[i] == ' ') && (inWord == true)) {
            inWord = false;
        }
        else if ((!hasNumber) && (inWord == true) && (str[i] <= '9') && (str[i] >= '0')) {
            count--;
            hasNumber = true;
        }
        i++;
    }

    return count;
}

unsigned int faStr2(const char* str) {
    bool inWord = false;
    bool allAreSmall = false;
    int count = 0;
    int i = 0;

    while (str[i]) {
        if ((str[i] != ' ') && (inWord == false)) {
            inWord = true;
            if ((str[i] <= 'Z') && (str[i] >= 'A')) {
                count++;
                allAreSmall = true;
            }
        }
        else if ((str[i] == ' ') && (inWord == true)) {
            inWord = false;
            allAreSmall = false;
        }
        else if ((allAreSmall) && (inWord == true) && ((str[i] < 'a') || (str[i] > 'z'))) {
            count--;
            allAreSmall = false;
        }
        i++;
    }

    return count;
}

unsigned int faStr3(const char* str) {
    bool inWord = false;
    int count = 0;
    double sum = 0;
    int i = 0;

    while (str[i]) {
        if ((str[i] != ' ') && (inWord == false)) {
            inWord = true;
            count++;
        }
        else if ((str[i] == ' ') && (inWord == true)) {
            inWord = false;
        }
        if (str[i] != ' ') sum++;
        i++;
    }

    return (int)(sum / count + 0.5);
}
