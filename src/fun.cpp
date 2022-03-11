// Copyright 2022 UNN-IASR
#include "fun.h"
#include <ctype.h>
#include <stdio.h>
#include <cstring>
#include <cmath>

unsigned int faStr1(const char *str) {
    int count = 0;
    bool isSpace = false;
    bool isCorrect = true;
    for (int i = 0; i < strlen(str); i++) {
        if (str[i] == ' ') {
            isSpace = true;
        }
        if (isdigit(str[i])) {
            isCorrect = false;
        }
        if (i == strlen(str) - 1 && str[i] != ' ') {
            if (isCorrect) {
                count++;
            }
        }
        if (isSpace == true) {
            if (i != 0) {
                if (str[i - 1] != ' ') {
                    if (isCorrect) {
                        count++;
                    }
                }
            }
            isCorrect = true;
            isSpace = false;
        }
    }

    return count;
}

unsigned int faStr2(const char *str) {
    int count = 0;
    bool isSpace = false;
    bool isCorrect = true;
    bool isFirstChar = true;
    for (int i = 0; i < strlen(str); i++) {
        if (str[i] == ' ') {
            isSpace = true;
        } else {
            if (isFirstChar) {
                isFirstChar = false;
                if (!isupper(str[i])) {
                    isCorrect = false;
                }
            } else {
                if (!islower(str[i])) {
                    isCorrect = false;
                }
            }
        }
        if (i == strlen(str) - 1 && str[i] != ' ') {
            if (isCorrect) {
                count++;
            }
        }
        if (isSpace == true) {
            if (i != 0) {
                if (str[i - 1] != ' ') {
                    if (isCorrect) {
                        count++;
                    }
                }
            }
            isCorrect = true;
            isSpace = false;
            isFirstChar = true;
        }
    }

    return count;
}

unsigned int faStr3(const char *str) {
    int countWord = 0;
    int countChar = 0;
    bool isSpace = false;
    for (int i = 0; i < strlen(str); i++) {
        if (str[i] == ' ') {
            isSpace = true;
        } else {
            countChar++;
        }
        if (i == strlen(str) - 1 && str[i] != ' ') {
            countWord++;
        }
        if (isSpace == true) {
            if (i != 0) {
                if (str[i - 1] != ' ') {
                    countWord++;
                }
            }
            isSpace = false;
        }
    }

    return  round(countChar / countWord);
}
