// Copyright 2022 UNN-IASR
#include "fun.h"

unsigned int faStr1(const char *str) {
    bool inWord = false;
    bool isDigitInWord = false;
    int count_word = 0;
    int i = 0;
    while (str[i]) {
        if (str[i] != ' ' && inWord == false) {
            inWord = true;
            count_word++;
        }
        if (isdigit(str[i]) == true && inWord == true
                            && isDigitInWord == false) {
            isDigitInWord = true;
            count_word--;
        }
        if (str[i] == ' ' && inWord == true) {
            inWord = false;
            isDigitInWord = false;
        }
        i++;
    }
    return count_word;
}

unsigned int faStr2(const char *str) {
    bool inWord = false;
    bool isNotFirst = false;
    bool isBad = false;
    int count_word = 0;
    int i = 0;
    while (str[i]) {
        if (str[i] != ' ' && inWord == false
            && isalpha(str[i]) == true
            && isupper(str[i]) == true) {
            isNotFirst = true;
            inWord = true;
            count_word++;
        } else if (inWord == true
            && isNotFirst == true
            && str[i] != ' '
            && isBad == false
            && (isalpha(str[i]) == false
            || islower(str[i]) == false)) {
            isBad = true;
            count_word--;
        }
        if (str[i] != ' ' && inWord == false && isalpha(str[i]) == false) {
            isNotFirst = true;
            inWord = true;
            isBad = true;
        }
        if (str[i] == ' ' && inWord == true) {
            inWord = false;
            isNotFirst = false;
            isBad = false;
        }
        i++;
    }
    return count_word;
}

unsigned int faStr3(const char *str) {
    bool inWord = false;
    int count_word = 0;
    int count_char = 0;
    int i = 0;
    while (str[i]) {
        if (str[i] != ' ' && inWord == false) {
            inWord = true;
            count_word++;
        }
        if (str[i] != ' ' && inWord == true) {
            count_char++;
        }
        if (str[i] == ' ' && inWord == true) {
            inWord = false;
        }
        i++;
    }
    return round(count_char*1.0/count_word);
}


