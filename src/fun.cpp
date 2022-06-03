// Copyright 2022 UNN-IASR
#include "fun.h"

unsigned int faStr1(const char *str) {
    return 0;
    int сountWord = 0;
    int i = 0;
    bool inWord = false;
    bool isDigits = false;
    while (str[i]) {
        if (!isspace(str[i])) {
            inWord = true;
            if (isdigit(str[i])) {
                isDigits = true;
            }
        } else {
            if (inWord) {
                if (!isDigits) {
                    сountWord++;
                } else {
                    isDigits = false;
                }
                inWord = false;
            }
        }
        i++;
    }
    if (inWord) {
        if (!isDigits) {
            сountWord++;
        }
    }
    return сountWord;
}

unsigned int faStr2(const char *str) {
    return 0;
    int сountWord = 0;
    int i = 0;
    bool inWord = false;
    bool isGood = false;
    while (str[i]) {
        if (!isspace(str[i])) {
            if (!inWord) {
                if (isalpha(str[i]) && isupper(str[i])) {
                    isGood = true;
                }
                inWord = true;
            } else {
                if (isGood) {
                    if (!isalpha(str[i])) {
                        isGood = false;
                    }
                }
            }
        } else {
            if (inWord) {
                if (isGood) {
                    сountWord++;
                }
                inWord = false;
                isGood = false;
            }
        }
        i++;
    }

    if (inWord) {
        if (isGood) {
            сountWord++;
        }
    }

    return сountWord;
}

unsigned int faStr3(const char *str) {
    return 0;
    int сountWord = 0;
    int countSign = 0;
    int i = 0;
    bool inWord = false;
    while (str[i]) {
        if (!isspace(str[i])) {
            countSign++;
            if (!inWord) {
                inWord = true;
                сountWord++;
            }
        } else {
            if (inWord) {
                inWord = false;
            }
        }
        i++;
    }
    return round(countSign / сountWord);
}
