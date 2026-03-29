// Copyright 2022 UNN-IASR
#include "fun.h"

unsigned int faStr1(const char *str) {
    int count = 0;
    bool inWord = false;
    bool number = false;
    while (*str) {
        if (*str != ' ' && inWord == false) {
            inWord = true;
            number = false;
            if (*str >= '0' && *str <= '9') {
                number = true;
            }
        } else if (*str != ' ' && inWord == true) {
            if (*str >= '0' && *str <= '9') {
                number = true;
            }
        } else if (*str == ' ' && inWord == true) {
            if (number == false) {
                count++;
            }
            inWord = false;
        }
        str++;
    }
    if (inWord == true && number == false) {
        count++;
    }
    return count;
}

unsigned int faStr2(const char *str) {
    int count = 0;
    bool inWord = false;
    bool letters = false;
    bool withCapital = false;
    while (*str) {
        if (*str != ' ' && inWord == false) {
            inWord = true;
            letters = true;
            if (*str >= 'A' && *str <= 'Z') {
                withCapital = true;
            }
        } else if (*str != ' ' && inWord == true) {
            if (!(*str >= 'a' && *str <= 'z')) {
                letters = false;
            }
        } else if (*str == ' ' && inWord == true) {
            if (letters == true && withCapital == true) {
                count++;
            }
            inWord = false;
            letters = false;
            withCapital = false;
        }
        str++;
    }
    if (inWord == true && letters == true && withCapital == true) {
        count++;
    }
    return count;
}

unsigned int faStr3(const char *str) {
    int count_word = 0;
    int count_letters = 0;
    bool inWord = false;
    while (*str) {
        if (*str != ' ' && inWord == false) {
            inWord = true;
            count_word++;
            count_letters++;
        } else if (*str != ' ' && inWord == true) {
            count_letters++;
        } else if (*str == ' ' && inWord == true) {
            inWord = false;
        }
        str++;
    }
    if (count_word == 0) {
        return 0;
    }
    return (count_letters * 2 + count_word) / (count_word * 2);
}
