// Copyright 2022 UNN-IASR
#include "fun.h"

unsigned int faStr1(const char *str) {
    bool inWord = false;
    bool withoutNums = true;
    unsigned int wordsCount = 0;
    unsigned int symbolIndex = 0;
    while (str[symbolIndex] != '\0') {
        char c = str[symbolIndex];
        if (!inWord && c != ' ') {
            inWord = true;
        }
        if (c >= '0' && c <= '9') {
            withoutNums = false;
        }
        if (inWord && c == ' ') {
            wordsCount += withoutNums ? 1 : 0;
            withoutNums = true;
            inWord = false;
        }
        symbolIndex++;
    }
    return wordsCount;
}

unsigned int faStr2(const char *str) {
    return 0;
}

unsigned int faStr3(const char *str) {
    return 0;
}
