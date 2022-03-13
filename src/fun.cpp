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
    bool isBad = false;
    bool isInWord = false;
    int count = 0;
    int i = 0;
    while (str[i] != '\0') {
        if (isInWord == true && isBad == false && str[i] == ' ') {
            isInWord = false;
        }else if (isInWord == true && isBad == false
            && isdigit(str[i])) {
            isBad = true;
            count--;
        } else if (isInWord == true && isBad == false
            && isalpha(str[i]) && isupper(str[i])) {
            isBad = true;
            count--;
        } else if (isInWord == false && isBad == false
            && !isalpha(str[i]) && !isdigit(str[i])) {
            isInWord = true;
            isBad = true;
        } else if (isInWord == false && isBad == false
            && isalpha(str[i]) && islower(str[i])) {
            isInWord = true;
            isBad = true;
        } else if (isInWord == false && isBad == false
            && isalpha(str[i]) && isupper(str[i])) {
            isInWord = true;
            count++;
        } else if (isInWord == false && isBad == false
            && !isalpha(str[i]) && !isdigit(str[i])) {
            isInWord = true;
            isBad == true;
        } else if (isInWord == true && isBad == false
            && !isalpha(str[i]) & !isdigit(str[i])) {
            isBad = true;
            count--;
        } else if (isInWord == false && isBad == false
            && isdigit(str[i])) {
            isInWord = true;
            isBad = true;
        } else if (isInWord == true && isBad == true
            && str[i] == ' ') {
            isInWord = false;
            isBad = false;
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
