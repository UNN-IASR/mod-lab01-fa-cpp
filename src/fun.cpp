// Copyright 2022 UNN-IASR
#include "fun.h"
#include <cctype>
#include <cmath>

unsigned int faStr1(const char *str) {
    bool inWord = false;
    bool isNum = false;
    int wordCount = 0;
    int i = 0;
    while (str[i]) {
        if (str[i] != ' ') {
            inWord = true;
            if (isdigit(str[i])) {
                isNum = true;
            }
        } else if (str[i] == ' ') {
            if (inWord) {
                if (!isNum) {
                    wordCount++;
                } else if (isNum) {
                    isNum = false;
                }
                inWord = false;
            }
        }
        i++;
    }
    return wordCount;
}

unsigned int faStr2(const char *str) {
    bool inWord = false;
    bool isBLat = false;
    bool isFirst = false;
    bool isSLat = false;
    int wordCount = 0;
    int i = 0;
    while (str[i]) {
        if (str[i] != ' ') {
            inWord = true;
            if (!isFirst) {
                isFirst = true;
                if (str[i] >= 'A' && str[i] <= 'Z') {
                    isBLat = true;
                    isSLat = true;
                }
            } else if (isFirst) {
                if (isBLat) {
                    if (!(str[i] >= 'a' && str[i] <= 'z')) {
                        isSLat = false;
                    }
                }
            }
        } else if (str[i] == ' ') {
            if (inWord) {
                if (isSLat) {
                    wordCount++;
                }
                isFirst = false;
                isBLat = false;
                inWord = false;
            }
        }
        i++;
    }
    return wordCount;
}

unsigned int faStr3(const char *str) {
    bool inWord = false;
    int wordCount = 0;
    int symCount = 0;
    int averCount = 0;
    int i = 0;
    while (str[i]) {
        if (str[i] != ' ') {
            symCount++;
            if (!inWord) {
                inWord = true;
                wordCount++;
            }
        } else if (str[i] == ' ') {
            if (inWord) {
                inWord = false;
            }
        }
        i++;
    }
    averCount = round(symCount / wordCount);
    return averCount;
}
