// Copyright 2022 UNN-IASR
#include "fun.h"
#include <ctype.h>
#include <cmath>

unsigned int faStr1(const char *str) {

    int i = 0;
    bool wentIntoWord = false;
    int tempWord = 0;
    int numWords = 0;

    while (str[i]) {
        if (str[i] != ' ' && !wentIntoWord) {
            wentIntoWord = true;
            tempWord = 1;
        } else if (wentIntoWord && str[i] == ' ') {
            numWords += tempWord;
            wentIntoWord = false;
        }
        if (isdigit(str[i]) && wentIntoWord) {
            tempWord = 0;
        }
        i++;
    }
    return numWords;
    }

unsigned int faStr2(const char *str) {

    int i = 0;
    bool wentIntoWord = false;
    int tempWord = 0;
    int numWords = 0;

    while (str[i]) {
        if (str[i] != ' ' && !wentIntoWord && isupper(str[i])) {
            wentIntoWord = true;
            tempWord = 1;
        } else if (wentIntoWord && str[i] == ' ') {
            numWords += tempWord;
            wentIntoWord = false;
        } else if (wentIntoWord && !islower(str[i])) tempWord = 0;
        i++;
    }
    return numWords;
    }

unsigned int faStr3(const char *str) {

    int i = 0;
    bool wentIntoWord = false;
    int countWords = 0;
    int lenWords = 0;

    while (str[i]) {
        if (str[i] != ' ') {
            if (wentIntoWord) {
                lenWords++;
            } else {
                countWords++;
                lenWords++;
                wentIntoWord = true;
            }
        } else if (wentIntoWord && str[i] == ' ') {
            wentIntoWord = false;
        }
        i++;
    }
    return round(static_cast<float>(lenWords) / countWords);
    }
