// Copyright 2022 UNN-IASR
#include "fun.h"

unsigned int faStr1(const char *str) {
    unsigned int count = 0;
    int i = 0;

    bool inWord = false;
    bool withNumber = false;


    while (*(str + i)) {
        if (!inWord && *(str + i) != ' ') {
            inWord = true;
        }

        if ('0' <= *(str + i) <= '9') {
            withNumber = true;
        }

        i++;

        if ((*(str + i) == ' ' || !*(str + i)) && inWord) {
            inWord = false;
            if (!withNumber) {
                count++;
            }
            withNumber = false;
        }
    }

    return count;
}

unsigned int faStr2(const char *str) {
    unsigned int count = 0;
    int i = 0;

    bool inWord = false;
    bool rightFormaat = true;


    while (*(str + i)) {
        if (!inWord && *(str + i) != ' ') {
            inWord = true;
            if (static_cast<int>(*(str + i)) < 65 ||
                static_cast<int>(*(str + i)) > 90) {
                rightFormaat = false;
            }
        }


        i++;

        if (inWord && *(str + i) != ' ' && *(str + i)) {
            if (static_cast<int>(*(str + i)) < 97 ||
                static_cast<int>(*(str + i)) > 122) {
                rightFormaat = false;
            }
        }

        if ((*(str + i) == ' ' || !*(str + i)) && inWord) {
            inWord = false;
            if (rightFormaat) {
                count++;
            }
            rightFormaat = true;
        }
    }

    return count;
}

unsigned int faStr3(const char *str) {
    int count = 0;
    int i = 0;

    int sum = 0;

    bool inWord = false;



    while (*(str + i)) {
        if (!inWord && *(str + i) != ' ') {
            inWord = true;
        }

        if (*(str + i) != ' ') {
            sum++;
        }

        i++;

        if ((*(str + i) == ' ' || !*(str + i)) && inWord) {
            inWord = false;
            count++;
        }
    }

    return sum/count;
}
