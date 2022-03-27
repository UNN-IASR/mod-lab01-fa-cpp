// Copyright 2022 UNN-IASR
#include "fun.h"
unsigned int faStr1(const char* str) {
    int i = 0; int j = 0; int k = 0; int number = 1;
    while (str[i] != '\0') {
        if ((str[i] != ' ')&&(k == 0)) {
            if ((str[i] < '0') ||(str[i] > '9')) {
            number = 0;
            }
            k = 1;
        } else if ((str[i] !=' ') && (k == 1 && number == 0)) {
                if ((str[i] >= '0') && (str[i] <= '9')) {
                    number = 1;
                }
            } else {
                if ((k == 1) && (str[i] == ' ')) {
                    if (number == 0) {
                        j+=1;
                    }
                number = 1; k = 0;
                }
            }
        i+=1;
    }
    if ((k == 1) && (number == 0)) {
        j+=1;
    }
    return j;
}
unsigned int faStr2(const char* str) {
    int i = 0; int j = 0; int k = 0; int number = 1;
    while (str[i] != '\0') {
        if ((str[i] != ' ') && (k == 0) && (str[i] >= 'A') && (str[i] <= 'Z')) {
            k = 1; number = 0;
        } else if ((str[i] != ' ') && (k == 1 && number == 0)) {
                if ((str[i] >= 65) && (str[i] <= 90)) {
                    number = 1;
                }
                if ((str[i] > 122) || (str[i] < 65)) {
                        number = 1;
                    }
            } else if ((k == 1) && (str[i] == ' ')) {
                    if (number == 0) {
                        j += 1;
                    }
                    number = 1; k = 0;
                } i+=1;
    }
    if ((k == 1) && (number == 0)) {
        j+=1;
    }

    return j;
}
unsigned int faStr3(const char* str) {
    int i = 0, j = 0, k = 0, l = 0, number = 0; float s = 0, g = 0;
    while (str[i] != '\0') {
        if ((str[i] != ' ') && (k == 0)) {
            j+=1; k = 1; l += 1;
        } else if ((str[i] != ' ') && (k == 1)) {
                l += 1;
            } else if ((str[i]== ' ') && (k == 1)) {
                s += l; k = 0; l = 0;
             } i+=1;
    }
    if (k == 1) {
        s = s + l;
    }
    s = s / static_cast<float>(j); g = s;
    if (s - static_cast<float>(g) >= 0.5) {
        g += 1;
    }
    return g;
}
