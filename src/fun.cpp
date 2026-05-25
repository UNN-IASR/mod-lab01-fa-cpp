// Copyright 2022 UNN-IASR
#include "fun.h"
#include <math.h>

unsigned int faStr1(const char* str) {
    unsigned int wordCount = 0;
    bool inWord = false;
    bool isValidWord = true;
    while (*str) {
        if (*str != ' ' && !inWord) {
            if (*str < 48 || *str > 57) wordCount++;
            else isValidWord = false;
            inWord = true;
        } else if (*str == ' ' && inWord) {
            inWord = false;
            if (!isValidWord) isValidWord = true;
        } else if (*str >= 48 && *str <= 57 && inWord && isValidWord) {
            wordCount--;
            isValidWord = false;
        }
        str++;
    }
    return wordCount;
}

unsigned int faStr2(const char* str) {
    unsigned int wordCount = 0;
    bool inWord = false;
    bool isValidWord = true;
    while (*str) {
        if (*str != ' ' && !inWord) {
            if (*str >= 65 && *str <= 90) wordCount++;
            else isValidWord = false;
            inWord = true;
        } else if (*str == ' ' && inWord) {
            inWord = false;
            if (!isValidWord) isValidWord = true;
        } else if ((*str < 97 || *str > 122) && inWord && isValidWord) {
            wordCount--;
            isValidWord = false;
        }
        str++;
    }
    return wordCount;
}

unsigned int faStr3(const char* str) {
    unsigned int wordCount = 0;
    unsigned int totalWordLength = 0;
    bool inWord = false;
    while (*str) {
        if (*str != ' ') {
            totalWordLength++;
            if (!inWord) {
                wordCount++;
                inWord = true;
            }
        } else if (*str == ' ' && inWord) {
            inWord = false;
        }
        str++;
    }
    return round(static_cast<float>(totalWordLength) / wordCount);
}
