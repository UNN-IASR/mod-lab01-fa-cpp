// Copyright 2022 UNN-IASR
#include "fun.h"
#include <cmath>

unsigned int faStr1(const char *str) {
    int numWordsWithoutNum = 0;
    bool inWord = false, containsNum = false;

    while (*str != '\0') {
        if (*str == ' ') {
            if (inWord && !containsNum) numWordsWithoutNum++;
            inWord = containsNum = false;
        } else {
            if (*str > 47 && *str < 58) containsNum = true;
            inWord = true;
        }
        str++;
    }
    if (inWord && !containsNum) numWordsWithoutNum++;

    return numWordsWithoutNum;
}

unsigned int faStr2(const char *str) {
    int numCorrectWords = 0;
    bool inWord = false, isCorrect = true;

    while (*str != '\0') {
        if (*str == ' ') {
            if (inWord && isCorrect) numCorrectWords++;
            inWord = false;
            isCorrect = true;
        } else {
            if (*str > 64 && *str < 91 && inWord
                || *str > 96 && *str < 123 && !inWord
                || !(*str > 96 && *str < 123 || *str > 64 && *str < 91))
                isCorrect = false;
            inWord = true;
        }
        str++;
    }
    if (inWord && isCorrect) numCorrectWords++;
    return numCorrectWords;
}

unsigned int faStr3(const char *str) {
    float numSymbols = 0;
    int numWords = 0;
    bool inWord = false;

    while (*str != '\0') {
        if (*str == ' ') {
            if (inWord) numWords++;
            inWord = false;
        } else {
            inWord = true;
            numSymbols++;
        }
        str++;
    }
    if (inWord) numWords++;

    return std::round(numSymbols/numWords);
}
