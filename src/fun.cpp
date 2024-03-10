// Copyright 2022 UNN-IASR
#include "fun.h"
#include <math.h>
#include <cctype>

unsigned int faStr1(const char* str) {
    bool inWord = false;
    bool isNumber = false; //определяет наличие цифр в слове
    int count = 0;
    int i = 0;
    while (str[i]) { //чтение слова на начале слова
        if (str[i] != ' ' && inWord == false) {
            inWord = true;
            count++;
        }   else if (isdigit(str[i]) && inWord == true && isNumber == false) {
            isNumber = true;
            count--;
        }   else if (str[i] == ' ' && inWord == true) {
            inWord = false;
            isNumber = false;
        }
        i++;
    }
    return count;
}
unsigned int faStr2(const char* str) {
    bool inWord = false;
    bool badWord = false; //бракует слово
    int count = 0;
    int i = 0;
    while (str[i]) {
        if (str[i] != ' ' && inWord == false) {  //чтение слова на начале слова
            inWord = true; {
                if (isupper(str[i]))
                    count++;
                else
                    badWord = true;
            }
        } else if ((str[i] < 'a' || str[i] > 'z') && str[i] != ' ') {
            if (inWord == true && badWord == false) {
                badWord = true;
                count--;
            }
        } else if (str[i] == ' ' && inWord == true) {  //окончание слова
            badWord = false;
            inWord = false;
        }
        i++;
    }
    return count;
}
unsigned int faStr3(const char* str) {
    bool inWord = false;
    int count = 0;
    int sum = 0; //сумма длин всех слов
    int lenghtNow = 0; //длина текущего слова
    int i = 0;
    while (str[i]) {
        if (str[i] != ' ' && inWord == false) {
            inWord = true;
            count++;
            lenghtNow++;
        } else if (str[i] != ' ' && inWord == true) {
            lenghtNow++;
        } else if (str[i] == ' ' && inWord == true) {
            inWord = false;
            sum += lenghtNow;
            lenghtNow = 0;
        }
        i++;
    }
    sum += lenghtNow; //т.к. \0 цикл не учитывает
    if ((sum%count) >= 0.5) {
        return (sum / count) + 1;
    } else {
        return sum / count;
    }
}
