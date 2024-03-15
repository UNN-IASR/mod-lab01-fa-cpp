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
    bool isBadWord = false;
    int count_word = 0;
    int i = 0;
    while (str[i]) {
        if (str[i] != ' ' && inWord == false
        && isalpha(str[i]) == true
        && isupper(str[i]) == true) {
            inWord = true;
            count_word++;
        } else 
        if (str[i] != ' ' && inWord == false
        && (isalpha(str[i]) == false
        || isupper(str[i]) == false)) {
            inWord = true;
            isBadWord = true;
        } else
        if (str[i] != ' ' && inWord == true
        && isBadWord == false
        && (isalpha(str[i]) == false
        || islower(str[i]) == false)) {
            isBadWord = true;
            count_word--;
        } else
        if (str[i] == ' ' && inWord == true) {
            inWord = false;
            isBadWord = false;
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
    if (count_word != 0) {
        return round(count_char*1.0/count_word);
    } else {
        return 0;
    }
}
