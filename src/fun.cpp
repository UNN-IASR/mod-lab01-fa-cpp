// Copyright 2022 UNN-IASR
#include "fun.h"

unsigned int faStr1(const char *str) {
    int Count = 0;
    bool InWord = false;
    bool IsNumber = false;

    while (*str) {
        if (*str != ' ' && InWord == false) {
            Count++;
            InWord = true;
        } else if (*str == ' ' && InWord == true) {
            InWord = false;
            IsNumber = false;
        } else if ((*str >= '0' && *str <= '9') && InWord == true &&
           IsNumber == false) {
            IsNumber = true;
            Count--;
        }
        str++;
    }
    return Count;
}

unsigned int faStr2(const char *str) {
    int Count = 0;
    bool InWord = false;
    bool IsValid = true;
    int Posiotion = 0;

    while (*str) {
        if (*str != ' ' && InWord == false) {
            InWord = true;
            Posiotion = 0;
            Posiotion++;
            if (*str >= 'A' && *str <= 'Z') {
                IsValid = true;
            } else {
                IsValid = false;
            }
        } else if (*str == ' ' && InWord == true) {
            InWord = false;
            if (IsValid == true) {
                Count++;
            }
        } else if (InWord == true && *str != ' ') {
            if (!(*str >= 'a' && *str <= 'z')) {
                IsValid = false;
            }
        }
        str++;
    }

    if (InWord && IsValid) {
        Count++;
    }

    return Count;
}

unsigned int faStr3(const char *str) {
    int WordCount = 0;
    int LettersCount = 0;
    bool InWord = false;

    while (*str) {
        if (*str != ' ' && InWord == false) {
            WordCount++;
            LettersCount++;
            InWord = true;
        } else if (*str == ' ' && InWord == true) {
            InWord = false;
        } else if (InWord == true && *str != ' ') {
            LettersCount++;
        }
        str++;
    }

    if (WordCount > 0) {
        double Avg = static_cast<double>(LettersCount) / WordCount;
        LettersCount = (unsigned int)(Avg + 0.5);
    } else {
        LettersCount = 0;
    }

    return LettersCount;
}