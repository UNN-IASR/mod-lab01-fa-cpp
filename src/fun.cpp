// Copyright 2022 UNN-IASR
#include <cmath>
#include "fun.h"

unsigned int faStr1(const char* str) {
    if (str == nullptr || str[0] == '\0')
        return 0;

    int l = 0;
    int count = 0;

    while (str[l] != '\0') {
        if (str[l] == ' ') {
            l++;
        } else {
            bool hasDigit = false;

            while (str[l] != ' ' && str[l] != '\0') {
                if (str[l] >= '0' && str[l] <= '9') {
                    hasDigit = true;
                }
                l++;
            }

            if (!hasDigit) {
                count++;
            }
        }
    }

    return count;
}

unsigned int faStr2(const char* str) {
    if (str == nullptr || str[0] == '\0')
        return 0;

    int l = 0;
    int count = 0;

    while (str[l] != '\0') {
        if (str[l] == ' ') {
            l++;
        } else {
            bool itsokay = true;

            if (!(str[l] >= 'A' && str[l] <= 'Z')) {
                while (str[l] != ' ' && str[l] != '\0') {
                    l++;
                }
                continue;
            }

            l++;

            while (str[l] != ' ' && str[l] != '\0') {
                if (!(str[l] >= 'a' && str[l] <= 'z')) {
                    itsokay = false;
                }
                l++;
            }

            if (itsokay) {
                count++;
            }
        }
    }

    return count;
}

unsigned int faStr3(const char* str) {
    if (str == nullptr || str[0] == '\0')
        return 0;

    int l = 0;
    int countsymbol = 0;
    int countword = 0;
    bool inWord = false;

    while (str[l] != '\0') {
        if (str[l] != ' ') {
            countsymbol++;
            if (!inWord) {
                inWord = true;
                countword++;
            }
        } else {
            inWord = false;
        }
        l++;
    }

    if (countword == 0)
        return 0;

    unsigned int rez = std::round(static_cast<double>(countsymbol) / countword);
    return rez;
}
