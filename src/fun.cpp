// Copyright 2022 UNN-IASR
#include "fun.h"
#include <cmath>

unsigned int faStr1(const char *str) {
    int count = 0;
    bool inWord = false;
    bool check = false;

    while (*str != '\0') {
        if (*str == ' ') {
            if (inWord && !check) {
                count++;
            }
            inWord = false;
            check = false;
        } else { if (*str > 47 && *str < 58) {
                check = true;
            }
            inWord = true;
        }

        str++;
    }

    if (inWord && !check) {
        count++;
    }
    return count;
}

unsigned int faStr2(const char *str) {
    int count = 0;
    bool inWord = false;
    bool check = true;
    while (*str != '\0') {
        if (*str == ' ') {
            if (inWord && check) {
                count++;
            }
            inWord = false;
            check = true;
        } else {
            if (*str > 64 && *str < 91 && inWord
                || *str > 96 && *str < 123 && !inWord
                || !(*str > 96 && *str < 123 || *str > 64 && *str < 91))
                check = false;
            inWord = true;
        }
        str++;
    }
    if (inWord && check) {
        count++;
    }
    return count;
}

unsigned int faStr3(const char *str) {
    float s = 0;
    int count = 0;
    bool inWord = false;
    while (*str != '\0') {
        if (*str == ' ') {
            if (inWord) {
                count++;
            }
            inWord = false;
        } else {
            inWord = true;
            s++;
        }
        str++;
    }
    if (inWord) {
        count++;
    }
    return std::round(s/count);
}
