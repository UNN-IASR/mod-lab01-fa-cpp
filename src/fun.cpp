// Copyright 2022 UNN-IASR
#include "fun.h"
#include <math.h>
#include <iostream>

unsigned faStr1(const char *str) {
    bool inW = false, haveN = false;
    int wCount = 0, i = 0;

    while (str[i]) {
        if (!isblank(str[i])) {
            if (!inW) inW = true;
            if (isdigit(str[i])) haveN = true;
        } else {
            if (inW) {
                if (!haveN) wCount++;
                inW = false;
                haveN = false;
            }
        }
        i++;
    }

    if (inW && !haveN) wCount++;
    return wCount;
}

unsigned faStr2(const char *str) {
    bool inW = false, reject = false;
    int wCount = 0, i = 0;

    while (str[i]) {
        if (!isblank(str[i])) {
            if (!inW) {
                inW = true;
                if (!isupper(str[i])) reject = true;
            } else {
                if (!islower(str[i])) reject = true;
            }
        } else {
            if (inW) {
                if (!reject) wCount++;
                inW = false;
                reject = false;
            }
        }
        i++;
    }

    if (inW && !reject) wCount++;
    return wCount;
}

unsigned faStr3(const char *str) {
    bool inW = false;
    int wCount = 0, symSum = 0, i = 0;

    while (str[i]) {
        if (!isblank(str[i])) {
            if (!inW) {
                inW = true;
                wCount++;
            }
            symSum++;
        } else {
            if (inW) inW = false;
        }
        i++;
    }

    return symSum / wCount;
}
