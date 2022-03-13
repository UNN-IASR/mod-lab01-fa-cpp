// Copyright 2022 UNN-IASR
#include "fun.h"
#include <ctype.h>
#include <string>
#include <cmath>

unsigned int faStr1(const char *str) {
     int w = 0;
    bool f = false;
    int i = 0;
    bool s = true;
    while (str[i] == ' ' && str[i] != '\0') {
        i++;
    }
    while (str[i] != '\0') {
        if (str[i] != ' ' && f == false) {
            f = true;
            int k = i;
            while (str[k] != ' ') {
                if (isdigit(str[k])) {
                    s = false;
                    k++;
                }
                k++;
            }
            if (s == true) {
                w++;
            }
        } else {
             if (str[i] == ' ') {
                f = false;
                s = true;
            }
        }
        i++;
    }
    return w;
}

unsigned int faStr2(const char *str) {
    int i = 0;
    int w = 0;
    bool f = false;
    bool s = true;
    while (str[i] == ' ' && str[i] != '\0') {
        i++;
    }
    while (str[i] != '\0') {
        if (str[i] != ' ' && f == false) {
            f = true;
            if (isupper(str[i])) {
                int k = i + 1;
                while (str[k] != ' ') {
                    if (!islower(str[k])) {
                        s = false;
                        k++;
                    }
                    k++;
                }
                if (s == true) {
                    w++;
                }
            }
        } else {
             if (str[i] == ' ') {
                f = false;
                s = true;
            }
        }
        i++;
    }
    return w;
}

unsigned int faStr3(const char *str) {
    int i = 0;
    int w = 0;
    double sym = 0;
    bool f = false;
    double x = 0;
    while (str[i] == ' ' && str[i] != '\0') {
        i++;
    }
    while (str[i] != '\0') {
        if (str[i] != ' ') {
            sym++;
        }
        if (str[i] != ' ' && f == false) {
            f = true;
            w++;
            int k = i;
        } else {
             if (str[i] == ' ') {
                f = false;
            }
        }
        i++;
    }
    x = round(sym / w);
    return x;
}
