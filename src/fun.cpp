// Copyright 2022 UNN-IASR
#include "fun.h"


unsigned int faStr1(const char* str) {
    int i = 0, wordCount = 0;
    bool inWord = false, tmp = false;
    while (str[i] != 0) {
        if (str[i] != ' ' && inWord == false) {
            inWord = true;
        }
        if (str[i] >= 48 && str[i] <= 57) {
            tmp = true;
        }
        if (str[i] == ' ' && inWord == true && tmp == false) {
            inWord = false;
            wordCount++;
        } else if (str[i] == ' ' && inWord == true) {
            inWord = false;
            tmp = false;
        }
        if (str[i + 1] == 0 && inWord == true && tmp == false) {
            wordCount++;
        }
        i++;
    }
    return wordCount;
}

unsigned int faStr2(const char* str) {
    int i = 0, wordCount = 0;
    bool inWord = false, tmpCapital = false, tmpRange = false;
    while (str[i] != 0) {
        if (str[i] != ' ' && inWord == false) {
            inWord = true;
        }
        if (i == 0 && str[i] >= 'A' && str[i] <= 'Z') {
            tmpCapital = true;
        } else if (i > 0 && str[i - 1] == ' ' 
            && str[i] >= 'A' && str[i] <= 'Z') {
            tmpCapital = true;
        }
        if ((str[i] < 'a' || str[i]>'z') && str[i] != ' ') {
            if (i == 0 && tmpCapital == false) {
                tmpRange = true;
            } else if (i > 0 && str[i - 1] != ' ') {
                tmpRange = true;
            }
        }
        if (str[i] == ' ' && inWord == true) {
            if (tmpCapital == true && tmpRange == false) {
                wordCount++;
            }
            inWord = false;
            tmpCapital = false;
            tmpRange = false;
        }
        if (str[i + 1] == 0 && inWord == true 
            && tmpRange == false && tmpCapital == true) {
            wordCount++;
        }
        i++;
    }
    return wordCount;
}

unsigned int faStr3(const char* str) {
    int i = 0, wordCount = 0, tmp = 0;
    bool inWord = false;
    while (str[i] != 0) {
        if (str[i] != ' ' && inWord == false) {
            inWord = true;
        }
        if (str[i] == ' ' && inWord == true) {
            inWord = false;
            wordCount++;
        }
        if (inWord == true) {
            tmp++;
        }
        if (str[i + 1] == 0 && inWord == true) {
            wordCount++;
        }
        i++;
    }
    double result = static_cast<double>(tmp) / wordCount;
    return static_cast<int>(result + 0.5);
}