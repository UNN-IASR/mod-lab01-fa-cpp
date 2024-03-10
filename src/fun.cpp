// Copyright 2022 UNN-IASR
#include "fun.h"
#include <string>
#include <cmath>

unsigned int faStr1(const char *str) {
    bool inWord = false;
    bool cifra = false;
    int count = 0;
    int i = 0;
    while (str[i] != '\0') {
        if (str[i] != ' ') {
            inWord = true;
        }
        if (str[i] >= '0' && str[i] <= '9') {
            cifra = true;
        }
        if (str[i] == ' ' && inWord == true) {
            if (cifra == false) {
                count++;
            }
            inWord = false;
            cifra = false;
        }
        i++;
    }
    return count;
}

unsigned int faStr2(const char *str) {
    bool first = true;
    bool correct = false;
    bool second = false;
    int count = 0;
    int i = 0;
    while (str[i] != '\0') {
        if (str[i] >= 'A' && str[i] <= 'Z' && first == true) {
            correct = true;
            first = false;
        } else if (str[i] >= 'a' && str[i] <= 'z') {
            first = false;
            second = true;
        } else if (str[i] != ' ') {
            correct = false;
        } else if (str[i] == ' ') {
            if (correct == true && second == true) {
                count++;
            }
            first = true;
            correct = false;
            second = false;
        }
        i++;
    }
    return count;
}

unsigned int faStr3(const char *str) {
    bool inWord = false;
    int count = 0;
    int len = 0;
    int i = 0;
    while (str[i] != '\0') {
        if (str[i] != ' ' && inWord == false) {
            inWord = true;
            count++;
        }
        if (str[i] != ' ') {
            len++;
        }
        if (str[i] == ' ' && inWord == true) {
            inWord = false;
        }
        i++;
    }
    if (count == 0) {
        return 0;
    } else {
        return std::round(len / count);
    }
}
