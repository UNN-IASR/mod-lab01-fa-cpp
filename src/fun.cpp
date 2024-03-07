// Copyright 2022 UNN-IASR
#include "fun.h"

unsigned int faStr1(const char *str) {
    int i = 0;
int count = 0;
int inWord = 0;//мы вне слова
int number = 0;//цифра не обнаружена
while (str[i] != '\0') {
    if (str[i] != ' ' && inWord == 0) {
        if ('0' <= str[i] && str[i] <= '9') {
            number == 1;
        }
        inWord = 1;
    }

     if (str[i] != ' ' && inWord == 1) {
        if ('0' <= str[i] && str[i] <= '9') {
            number = 1;
        }
    }

    if (str[i] == ' ' && inWord == 1) {
        if (number == 0) {
            count++;
        }
        inWord = 0;
        number = 0;
    }
    i++;
}
if (inWord == 1 && number == 0) {
    count++;
}
return count;
}

unsigned int faStr2(const char *str) {
    int i = 0;
int count = 0;
int inWord = 0;
int pervaiabukva = 0;// первая буква - не заглавная латинская
int malbuk = 0;
while (str[i] != '\0') {
    if (str[i] != ' ' && inWord == 0) {
        if (65 <= str[i] && str[i] <= 90) {
            pervaiabukva = 1;
        }
        inWord = 1;
    }
    if (str[i] != ' ' && inWord == 1) {
        if (97 <= str[i] && str[i] <= 122) {
            malbuk = 1;
        } else {
            malbuk = 0;
        }
    }
    if (str[i] == ' ' && inWord == 1) {
        if (pervaiabukva == 1 && malbuk == 1) {
            count++;
        }
        int inWord = 0;
        int pervaiabukva = 0;
        int malbuk = 0;
    }
    i++;
}
if (inWord == 1 && pervaiabukva == 1 && malbuk == 1) {
    count++;
}
return count;
}

unsigned int faStr3(const char *str) {
     int i = 0;
int inWord = 0;
int countb = 0;
int counts = 0;
while (str[i] != '\0') {
     if (str[i] != ' ') {
         countb++;
         inWord = 1;
     }
     if (str[i] == ' ') {
         if (inWord == 1) {
             counts++;
         }
         inWord = 0;
     }
     i++;
}
if (inWord == 1) {
    counts++;
}
float ans = static_cast<float>(countb) / counts;
if ((ans - static_cast<int>(ans)) >= 0.5)
    return static_cast<int>(ans) + 1;
return static_cast<int>(ans);
}
