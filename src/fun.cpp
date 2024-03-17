// Copyright 2022 UNN-IASR
#include "fun.h"
#include <iostream>
#include "math.h"
#include "ctype.h"

unsigned int faStr1(const char* input) {
    unsigned int wordCount = 0;
    bool inWord = false;
    bool hasNumbers = false;
    int i = 0;
    while (input[i] != '\0') {
        if (!inWord && input[i] != ' ') {
            inWord = true;
            hasNumbers = isdigit(input[i]);
        } else if (inWord && input[i] != ' ') {
            if (isdigit(input[i]))
                hasNumbers = true;
        }
        if (inWord && (input[i] == ' ' || input[i + 1] == '\0')) {
            if (!hasNumbers)
                wordCount++;
            hasNumbers = false;
            inWord = false;
        }

        i++;
    }
    return wordCount;
}

unsigned int faStr2(const char* input) {
    unsigned int wordCount = 0;
    bool inWord = false;
    bool isGood = true;
    int i = 0;
    while (input[i] != '\0') {
        if (!inWord && input[i] != ' ') {
            inWord = true;
            isGood = isupper(input[i]);
        } else if (inWord && input[i] != ' ') {
            if (!islower(input[i]))
                isGood = false;
        }
        if (inWord && (input[i] == ' ' || input[i + 1] == '\0')) {
            if (isGood)
                wordCount++;
            isGood = true;
            inWord = false;
        }
        i++;
    }
    return wordCount;
}

unsigned int faStr3(const char* input) {
    unsigned int numWords = 0;
    unsigned int totalLength = 0;
    bool inWord = false;
    int i = 0;
    while (input[i] != '\0') {
        if (!inWord && input[i] != ' ') {
            inWord = true;
            numWords++;
            totalLength++;
        } else if (inWord && input[i] != ' ') {
            totalLength++;
        }
        if (inWord && (input[i] == ' ' || input[i + 1] == '\0')) {
            inWord = false;
        }
        i++;
    }

    double averageLength = static_cast<double>(totalLength / numWords);

    return static_cast<int>(round(averageLength));
}

