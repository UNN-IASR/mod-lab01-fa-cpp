// Copyright 2022 UNN-IASR
#include "fun.h"
#include <iostream>
using namespace std;
unsigned int faStr1(const char *str) {
    bool InWord = false;
    bool HaveANumbers = false;
    int NumOfWords = 0;
    int i = 0;
    while (str[i]) {
        if (!isblank(str[i])) {
            if (!InWord) //проверка на вхождение в слово
                InWord = true;
            if (isdigit(str[i])) HaveANumbers = true; //проверка встречи числа
        }
        else if (InWord) {
            if (!HaveANumbers) NumOfWords++;
            InWord = false;
            HaveANumbers = false;
        }
        i++;
    }
    if (InWord && !HaveANumbers) NumOfWords++;
    return NumOfWords;
}

unsigned int faStr2(const char *str) {
    bool InWord = false;
    bool Reject = false;
    int NumOfWords = 0;
    int i = 0;
    while (str[i]) {
        if (!isblank(str[i])) {
            if (!InWord) {//проверка на вхождение в слово c заглавной буквы
                InWord = true;
                if (!isupper(str[i])) Reject = true; //проверка заглавной буквы
            }
            else if (!islower(str[i])) Reject = true; //проверка встречи не строчной буквы
        }
        else if (InWord) {
            if (!Reject) NumOfWords++;
            InWord = false;
            Reject = false;
        }
        i++;
    }
    if (InWord && !Reject) NumOfWords++;
    return NumOfWords;
}

unsigned int faStr3(const char *str) {
    bool InWord = false;
    int NumOfWords = 0;
    int SumOfSymbols = 0;
    int i = 0;
    while (str[i]) {
        if (!isblank(str[i])) {
            if (!InWord) {        //проверка на вхождение в слово c заглавной буквы
                InWord = true;
                NumOfWords++;
            }
            SumOfSymbols++;
        }
        else if (InWord) InWord = false;
        i++;
    }
    return round(SumOfSymbols/(double)NumOfWords);
}
