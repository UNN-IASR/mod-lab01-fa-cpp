// Copyright 2022 UNN-IASR
#include "fun.h"

unsigned int faStr1(const char *str) {
    int i = 0;
    int wordsWithDigit = 0;
    bool inDigitWord = false;
    while(str[i]) {
        char current = str[i];
        if (isdigit(current) && !inDigitWord) {
            inDigitWord = true;
            wordsWithDigit++;
        }
        if (current == ' ') {
            inDigitWord = false;
        }
        i++;
    }
    return wordsWithDigit;
}

unsigned int faStr2(const char *str) {
    int i = 0;
    int result = 0;
    bool inWord = false;
    bool inValidWord = false;
    while(str[i]) {
        char current = str[i];
        if (current == ' ') {
            if (inValidWord) {
                result++;
            }
            inWord = false;
            inValidWord = false;
        }
        else if (!inWord) {
            inWord = true;
            if (isupper(current)) {
                inValidWord = true;
            }
        }
        else if (inWord && (isupper(current) || !isalpha(current))) {
            inValidWord = false;
        }
        i++;
    }
    if (inValidWord) {
        result++;
    }
    return result;
}

unsigned int faStr3(const char *str) {
    int i = 0;
    bool inWord = false;
    int wordsCount = 0;
    int totalChars = 0;
    while(str[i]) {
        char current = str[i];
        if (current == ' ') {
            inWord = false;
        } else {
            if (!inWord) {
                inWord = true;
                wordsCount++;
            }
            totalChars++;
        }
        i++;
    }
    return totalChars/wordsCount;
}
