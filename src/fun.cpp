// Copyright 2022 UNN-IASR
#include <iostream>
#include <cmath>
#include <cctype>
unsigned int faStr1(const char *str) {
    bool InWord = false;
    bool HaveANumbers = false;
    int NumOfWords = 0;
    int i = 0;
    while (str[i]) {
        if (!isblank(str[i])) {
            if (!InWord)
                InWord = true;
            if (isdigit(str[i])) HaveANumbers = true;
        } else {
            if (InWord) {
                if (!HaveANumbers) NumOfWords++;
                InWord = false;
                HaveANumbers = false;
            }
        }
        i++;
    }
    if (InWord && !HaveANumbers) NumOfWords++;
    return NumOfWords;
}

unsigned int faStr2(const char *str) {
    bool flag = false;
    int i = 0;
    int count = 0;
    int result = 0;
    while (str[i]) {
        if (!flag && str[i] != ' ' && str[i] >= 65 && str[i] <= 90) {
            flag = true;
            count = 1;
        }
        else if (flag && str[i] == ' ') {
            flag = false;
            result += count;
        }
        else if (str[i] < 97 || str[i] > 122) {
            count = 0;
        }
        i++;
    }
    return result;
}

unsigned int faStr3(const char *str) {
    bool inWord = false;
    int counter = 0;
    int i = 0;
    int len = 0;
    while (str[i] != '\0') {
        if (str[i] != ' ') {
            if (!inWord) counter++;
            inWord = true;
            len++;
        } else if (str[i] == ' ' && inWord) {
            inWord = false;
        }
        i++;
    }
    return round(static_cast<float>(len)/counter);
}
