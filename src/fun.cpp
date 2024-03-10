// Copyright 2022 UNN-IASR
#include <math.h>

#include <cctype>

#include "fun.h"

unsigned int faStr1(const char* str) {
    bool inWord = false;
    bool isDigit = false;
    unsigned int count = 0;
    unsigned int i = 0;

    while (str[i]) {
        if (str[i] != ' ' && !inWord) {
            isDigit = false;
            inWord = true;
            count++;
        }
        if (str[i] != ' ' && inWord) {
            if (isdigit(str[i]) && !isDigit) {
                isDigit = true;
                count--;
            }
        }
        if (str[i] == ' ' && inWord) inWord = false;
        i++;
    }
    return count;
}

unsigned int faStr2(const char* str) {
    bool inWord = false;
    bool isDigit = false;
    bool isStartUpper = false;
    bool isStartWord = false;
    unsigned int count = 0;
    unsigned int i = 0;

    while (str[i]) {
        if (str[i] != ' ' && !inWord) {
            isDigit = false;
            inWord = true;
            isStartUpper = isupper(str[i]);
            isStartWord = true;
            count++;
        }
        if (str[i] != ' ' && inWord) {
            // if there is no capital letter in the word
            // - equate it to a number
            // if there is a capital letter in the other letters
            // - equate it to a
            // number
            if (!isStartUpper ||
                ((isdigit(str[i]) && !isDigit) ||
                    (!isStartWord && isupper(str[i]) && !isDigit) ||
                    (!isalpha(str[i]) && !isDigit))) {
                isDigit = true;
                isStartUpper = true;
                count--;
            }
            isStartWord = false;
        }
        if (str[i] == ' ' && inWord) inWord = false;
        i++;
    }
    return count;
}

unsigned int faStr3(const char* str) {
    bool inWord = false;
    unsigned int wordLength = 0;
    unsigned int count = 0;
    int i = 0;

    while (str[i]) {
        if (str[i] != ' ' && inWord == false) {
            inWord = true;
            count++;
        }
        if (str[i] != ' ' && inWord) wordLength++;
        else if (str[i] == ' ' && inWord == true) inWord = false;
        i++;
    }
    return static_cast<int>(round(wordLength / count));
}
