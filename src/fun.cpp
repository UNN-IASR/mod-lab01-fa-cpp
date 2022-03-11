// Copyright 2022 UNN-IASR
#include <iostream>
#include <cmath>
#include "fun.h"

unsigned int faStr1(const char *str) {
    int num = 0;
    int key = 0;
    char prev = ' ';
    int j = 0;
    while (str[j] != '\0') {
        j++;
    }
    j++;
    for (int i = 0; i < j; i++) {
        if ((str[i] != ' ') && (prev == ' ') && (str[i] != '\0')) {
            num++;
        }
        if (str[i] >= 48 && str[i] <= 57) {
            key = 1;
        }
        if (((str[i] == ' ') && (prev != ' ')) || (str[i] == '\0')
            && (prev != ' ')) {
            if (key == 1) {
                num--;
                key = 0;
            }
        }
        prev = str[i];
    }
    return num;
}

unsigned int faStr2(const char *str) {
    int num = 0;
    int key0 = 0;
    int key1 = 0;
    char prev = ' ';
    int j = 0;
    while (str[j] != '\0') {
        j++;
    }
    j++;
    for (int i = 0; i < j; i++) {
        if ((str[i] != ' ') && (prev == ' ') && (str[i] != '\0')) {
            if ((str[i] <= 64) || (str[i] >= 91)) {
                key1 = 1;
            }
            num++;
        }
        if (((str[i] <= 64) || (str[i] >= 123)) && (str[i] != '\0')
            && (str[i] != ' ')) {
            key0 = 1;
        }
        if (((str[i] == ' ') && (prev != ' ')) || (str[i] == '\0')
            && (prev != ' ')) {
            if ((key0 == 1) || (key1 == 1)) {
                num--;
                key0 = 0;
                key1 = 0;
            }
        }
        prev = str[i];
    }
    return num;
}

unsigned int faStr3(const char *str) {
    double num = 0;
    double key = 0;
    char prev = ' ';
    int j = 0;
    while (str[j] != '\0') {
        j++;
    }
    j++;
    for (int i = 0; i < j; i++) {
        if ((str[i] != ' ') && (prev == ' ') && (str[i] != '\0')) {
            num++;
        }
        if ((str[i] != ' ') && (str[i] != '\0')) {
            key++;
        }
        prev = str[i];
    }
    return round(key / num);
}
