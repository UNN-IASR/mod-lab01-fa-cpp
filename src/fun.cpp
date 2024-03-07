// Copyright 2022 UNN-IASR
#include "fun.h"
#include <math.h>
#include <ctype.h>

unsigned int faStr1(const char *str) {
    int count = 0;
    bool inWord = false;
    bool containsNumbers = false;
    int i = 0;
    while (str[i] != '\0') {
        if (!inWord && str[i] != ' ') {
            inWord = true;
        }
        if (inWord && str[i] != ' ' && isdigit(str[i])) {
            containsNumbers = true;
        }
        if (inWord && (str[i] == ' ' || str[i + 1] == '\0')) {
            if (!containsNumbers) {
                count++;
            }
            containsNumbers = false;
            inWord = false;
        }
        i++;
    }
    return count;
}

unsigned int faStr2(const char *str) {
    int count = 0;
    bool inWord = false;
    bool onlyFirstCapital = false;
    int i = 0;
    while (str[i] != '\0') {
        if (inWord && str[i] != ' ' && !islower(str[i])) {
            onlyFirstCapital = false;
        }
        if (!inWord && str[i] != ' ') {
            inWord = true;
            onlyFirstCapital = isupper(str[i]);
        }
        if (inWord && (str[i] == ' ' || str[i + 1] == '\0')) {
            if (onlyFirstCapital) {
                count++;
            }
            onlyFirstCapital = false;
            inWord = false;
        }
        i++;
    }
    return count;
}

unsigned int faStr3(const char *str) {
    int count = 0;
    int sumLength = 0;
    bool inWord = false;
    int i = 0;
    while (str[i] != '\0') {
        if (inWord && str[i] != ' ') {
            sumLength++;
        }
        if (!inWord && str[i] != ' ') {
            inWord = true;
            count++;
            sumLength++;
        }
        if (inWord && (str[i] == ' ' || str[i + 1] == '\0')) {
            inWord = false;
        }
        i++;
    }
    return static_cast<int>(round(static_cast<double>(sumLength) / count));
}
