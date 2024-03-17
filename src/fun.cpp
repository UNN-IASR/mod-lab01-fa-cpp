// Copyright 2022 UNN-IASR
#include "fun.h"
#include <iostream>
#include <cmath>
#include <cctype>

unsigned int faStr1(const char* str) {
    bool InWord = false;
    bool IsNum = false;
    int counter = 0;
    int i = 0;
    while (str[i] != '\0') {
        if (str[i] != ' ' && InWord == false) {
            InWord = true;
            if (isdigit(str[i])) {
                IsNum = true;
            }
            counter++;
        } else if (str[i] != ' ' && InWord == true) {
            if (isdigit(str[i])) {
                IsNum = true;
            }
        } else if (str[i] == ' ' && InWord == true) {
            InWord = false;
            if (IsNum) {
                counter--;
            }
            IsNum = false;
        }
        i++;
    }
    return counter;
}

unsigned int faStr2(const char* str) {
    bool InWord = false;
    bool Fail = false;
    int counter = 0;
    int i = 0;
    while (str[i] != '\0') {
        if (str[i] != ' ' && InWord == false) {
            InWord = true;
            if (islower(str[i]) || isdigit(str[i])) {
                Fail = true;
            }
            counter++;
        } else if (str[i] != ' ' && InWord == true) {
            if (isupper(str[i]) || isdigit(str[i])) {
                Fail = true;
            }
        } else if (str[i] == ' ' && InWord == true) {
            InWord = false;
            if (Fail) {
                counter--;
            }
            Fail = false;
        }
        i++;
    }
    if (InWord == true) {
        if (Fail) {
            counter--;
        }
        Fail = false;
    }
    return counter;
}

unsigned int faStr3(const char* str) {
    bool InWord = false;
    int counter = 0;
    int i = 0;
    int len = 0;
    while (str[i] != '\0') {
        if (str[i] != ' ' && InWord == false) {
            InWord = true;
            len++;
        } else if (str[i] == ' ' && InWord == true) {
            counter++;
        } else if (str[i] != ' ' && InWord == true) {
            len++;
        }
        i++;
    }
    if (InWord == true) {
        counter++;
    }
    return round(static_cast<float>(len) / counter);
}
