// Copyright 2022 UNN-IASR
#include "fun.h"

unsigned int faStr1(const char *str) {
    int count = 0;
    int i = 0;
    bool isInWord = false;
    bool hadNumber = false;
    while (str[i] != '\0') {
        if (str[i] == ' ') {
            if (!hadNumber && isInWord) {
                count++;
            } else {
                hadNumber = false;
            }
            isInWord = false;
        } else {
            isInWord == true;
            if (!hadNumber && isdigit(str[i])) {
                hadNumber = true;
            }
        }
        i++;
    }
    return count;
}

unsigned int faStr2(const char *str) {
    int count = 0;
    int i = 0;
    bool isInWord = false;
    bool isGood = false;
    bool isFirstLetter = true;
    while (str[i] != '\0') {
        if (str[i] == ' ') {
            if (isGood && isInWord) {
                count++;
            }
            isGood = false;
            isInWord = false;
            isFirstLetter = true;
        } else {
            isInWord = true;
            if (isFirstLetter) {
                if (isalpha(str[i])) {
                    isGood = true;
                }
                isFirstLetter = false;
            } else {
                if (isdigit(str[i]) || isalpha(str[i])) {
                    isGood = false;
                }
            }
        }
        i++;
    }
    return count;
}

unsigned int faStr3(const char *str) {
    int wordsCount = 0;
    int charsCount = 0;
    bool isInWord = false;
    int i = 0;
    while (str[i]) {
        if (str[i] != ' ' && !isInWord) {
            isInWord = true;
            wordsCount++;
        } else if (str[i] == ' ' && isInWord) {
            isInWord = false;
        }
        if (str[i] != ' ') {
            charsCount++;
        }
        i++;
    }
    int answ = round(charsCount / wordsCount);
    return answ;
}
