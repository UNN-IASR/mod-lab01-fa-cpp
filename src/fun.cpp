// Copyright 2022 UNN-IASR
#include "fun.h"
#include <cmath>
unsigned int faStr1(const char* str) {
    bool inWord = false, num = false;
    int count = 0, i = 0;
    while (str[i] != '\0') {
        if (str[i] != ' ' && inWord == false) {
            inWord = true;
            count++;
                } else if (str[i] == ' ' && inWord == true) {
            inWord = false;
            num = false;
        }
        if (inWord == true && num == false && (str[i] >= '0' && str[i] <= '9')) {
            count--;
            num = true;
        }
        i++;
    }
    return count;
}

unsigned int faStr2(const char* str) {
    bool inWord = false, AA = false, no = false;
    int count = 0, i = 0;
    while (str[i] != '\0') {
        if (str[i] != ' ' && inWord == false) {
            if (inWord == false && str[i] >= 'A' && str[i] <='Z') {
                AA = true;
            }
            inWord = true;
            count++;
        } else if (str[i] == ' ' && inWord == true) {
            inWord = false;
            AA = false;
            no = false;
		}
        if (i != 0 && str[i - 1] != ' ') {
            if (inWord && !no && (!AA || str[i] < 'a' || str[i] > 'z')) {
                count--;
                no = true;
            }
        }
        i++;
    }
    return count;
}

unsigned int faStr3(const char* str) {
    bool inWord = false;
    int i = 0;
    float count = 0, count_s = 0;
    float lenght = 0;
    while (str[i] != '\0') {
        if (str[i] != ' ' && inWord == false) {
            inWord = true;
            count++;
        } else if (str[i] == ' ' && inWord == true) { inWord = false; }
        if (str[i] != ' ') { count_s++; }
        i++;
    }
    lenght = round(count_s / count);
    return lenght;
}
