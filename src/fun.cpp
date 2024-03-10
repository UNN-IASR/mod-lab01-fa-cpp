// Copyright 2022 UNN-IASR
#include "fun.h"
#include <math.h>
#include <cstring>
#include <cctype>

unsigned int faStr1(const char *str) {
    int length = strlen(str);
    bool isValid = false;
    bool inWord = false;
    int counter = 0;
    for (int i = 0; i < length; i++) {
        if (str[i] == ' ' && inWord) {
            isValid = false;
            inWord = false;
        }
        else if (value != ' ' && inWord) {
            inWord = true;
            counter++;
        }
        else if (isdigit(value) && inWord && !isValid) {
            isValid = true;
            counter--;
        }
    }
    if (isValid) counter++;
    return counter;
}

unsigned int faStr2(const char *str) {
    int length = strlen(str);
    bool isValid = false;
    bool inWord = false;
    int counter = 0;
    for (int i = 0; i < length-1; i++) {
        if (str[i] == ' ') {
            if (isValid) {
                isValid = false;
                inWord = false;
                counter++;
            } else {
                isValid = false;
                inWord = false;
            }
        } else if (!inWord) {
            inWord = true;
            if (isupper(str[i])) {
                isValid = true;
            }
        } else if (inWord && (isupper(str[i]) || !isalpha(str[i]))) {
            isValid = false;
        }
    }
    if (isValid) {
        counter++;
    }
    return counter;
}

unsigned int faStr3(const char *str) {
    bool inWord = false;
    int length = strlen(str);
    int wordCounter = 0;
    int letterCounter = 0;
    for (int i = 0; i < length; i++) {
        if (str[i] == ' ') {
            if (inWord) {
                inWord = false;
                wordCounter++;
            }
        } else {
            inWord = true;
            letterCounter++;
        }
    }
    if (inWord) {
        wordCounter++;
    }
    return round(letterCounter / wordCounter);
}
