// Copyright 2022 UNN-IASR
#include "fun.h"
#include <math.h>
#include <iostream>
#include <cstring>

unsigned int faStr1(const char *str) {
    int wordCount = 0;
    bool isNumber = false;
    bool isLetter = false;
    for (int i = 0; i < strlen(str); i++) {
        if (str[i] != ' ' && !isLetter) {
            isLetter = true;
        } else if (str[i] >= '0' && str[i] <= '9') {
            isNumber = true;
        }
        if (str[i] == ' ' && isLetter && !isNumber) {
            isLetter = false;
            wordCount++;
        } else if (str[i] == ' ' && isLetter) {
            isLetter = false;
            isNumber = false;
        }
    }
    if (isLetter && !isNumber) {
        wordCount++;
    }
    return wordCount;
}

unsigned int faStr2(const char *str) {
    int wordCount = 0;
    bool isLetter = false;
    bool isNumber = false;
    bool isFirst = false;
    bool fakeWord = false;
    for (int i = 0; i < strlen(str); i++) {
        if (str[i] != ' ') {
            isLetter = true;
            if (str[i] >= 'A' && str[i] <= 'Z' && !isFirst) {
                isFirst = true;
            } else if (str[i] >= 'A' && str[i] <= 'Z' && isFirst) {
                fakeWord = true;
            } else if ((str[i] < 'a' || str[i] > 'z') && !fakeWord) {
                fakeWord = true;
            }
        } else if (str[i] == ' ') {
            if (isLetter && isFirst && !fakeWord) {
                wordCount++;
            }
            fakeWord = false;
            isFirst = false;
            isLetter = false;
        }
    }
    return wordCount;
}

unsigned int faStr3(const char *str) {
    bool isLetter = false;
    int wordCount = 0;
    int sumLetter = 0;
    int avgSumWord = 0;
    for (int i = 0; i < strlen(str); i++) {
        if (str[i] != ' ') {
            sumLetter++;
            if (!isLetter) {
                isLetter = true;
                wordCount++;
            }
        } else if (str[i] == ' ') {
            if (isLetter) {
                isLetter = false;
            }
        }
    }
    avgSumWord = round(sumLetter / wordCount);
    return avgSumWord;
}
