// Copyright 2022 UNN-IASR
#include "fun.h"
#include <cmath>

unsigned int faStr1(const char *str) {
    bool inWord = false;
    bool wordInvalidated = false;
    int i = 0;
    unsigned int count = 0;
    while (str[i] != '\0') {
        if (inWord) {
            if (str[i] >= '0' && str[i] <= '9') wordInvalidated = true;
            if (str[i] == ' ' || str[i] == '\n') {
                if (wordInvalidated) count--;
                inWord = false;
                wordInvalidated = false;
            }
        } else {
            if (str[i] != ' ' && str[i] != '\n') {
                wordInvalidated = !(str[i] < '0' || str[i] > '9');
                count++;
                inWord = true;
            }
        }
        i++;
    }
    if (wordInvalidated && inWord) {
        count--;
    }
    return count;
}

unsigned int faStr2(const char *str) {
    bool inWord = false;
    bool wordInvalidated = false;
    int i = 0;
    unsigned int count = 0;
    while (str[i] != '\0') {
        if (inWord) {
            if (str[i] == ' ' || str[i] == '\n') {
                if (wordInvalidated) count--;
                inWord = false;
                wordInvalidated = false;
            } else if (str[i] < 'a' || str[i] > 'z') {
                wordInvalidated = true;
            }
        } else {
            if (str[i] != ' ' && str[i] != '\n') {
                wordInvalidated = str[i] < 'A' || str[i] > 'Z';
                count++;
                inWord = true;
            }
        }
        i++;
    }
    if (wordInvalidated && inWord) {
        count--;
    }
    return count;
}

unsigned int faStr3(const char *str) {
    bool inWord = false;
    int i = 0;
    unsigned int count = 0;
    float sum = 0;
    while (str[i] != '\0') {
        if (inWord) {
            if (str[i] == ' ' || str[i] == '\n') {
                inWord = false;
            } else {
                sum++;
            }
        } else {
            if (str[i] != ' ' && str[i] != '\n') {
                count++;
                sum++;
                inWord = true;
            }
        }
        i++;
    }
    if (count == 0) return 0;
    float ratio = sum / count;
    return std::floor(ratio + 0.5f);
}
