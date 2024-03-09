// Copyright 2022 UNN-IASR
#include "fun.h"

unsigned int faStr1(const char *str) {
    bool inWord = false;
    bool contNum = false;
    int counter = 0;
    int i = 0;
    while (str[i] != '\0') {
        if (str[i] != ' ' && !inWord) {
            inWord = true;
            contNum = isdigit(str[i]);
            counter += !contNum;
        } else if (str[i] == ' ' && inWord) {
            inWord = false;
            contNum = false;
        } else if (isdigit(str[i]) && inWord && !contNum) {
            contNum = true;
            counter--;
        }
        i++;
    }
    return counter;
}

unsigned int faStr2(const char *str) {
    bool inWord = false;
    bool corrWord = false;
    int counter = 0;
    int i = 0;
    while (str[i] != '\0') {
        if (str[i] != ' ' && !inWord) {
            inWord = true;
            corrWord = isupper(str[i]);
            counter += corrWord;
        } else if (str[i] == ' ' && inWord) {
            inWord = false;
            corrWord = false;
        } else if (!islower(str[i]) && inWord && corrWord) {
            corrWord = false;
            counter--;
        }
        i++;
    }
    return counter;
}

unsigned int faStr3(const char *str) {
    bool inWord = false;
    int counter = 0;
    int len = 0;
    int i = 0;
    while (str[i] != '\0') {
        if (str[i] != ' ') {
            counter += !inWord;
            len++;
            inWord = true;
        } else if (str[i] == ' ' && inWord) {
            inWord = false;
        }
        i++;
    }
    return round(static_cast<float>(len)/counter);
}
