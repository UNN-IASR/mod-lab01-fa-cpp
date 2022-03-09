// Copyright 2022 UNN-IASR
#include "fun.h"

unsigned int faStr1(const char* str) {
        int k = 0,
            count = 0,
            inWord = 0,
            num = 0;
        while (str[k] != '\0') {
            if (inWord == 0 && str[k] != ' ') {
                if (str[k] > '9' || str[k] < '0') num = 1;
                inWord = 1;
            } else if (inWord == 1 && str[k] != ' ' && num == 1) {
                if (str[k] >= '0' && str[k] <= '9') num = 0;
            } else if (inWord == 1 && str[k] == ' ') {
                if (num == 1) count++;
                num = 0;
                inWord = 0;
            }
            k++;
        }
        if (inWord == 1 && num == 1) count++;
        return count;
}

    unsigned int faStr2(const char* str) {
            int k = 0,
                count = 0,
                inWord = 0,
                num = 0;
            while (str[k] != '\0') {
                if (inWord == 0 && str[k] >= 'A' && str[k] <= 'Z') {
                    inWord = 1;
                    num = 1;
                } else if (inWord == 1 && str[k] != ' ' && num == 1) {
                    if (str[k] >= 'A' && str[k] <= 'Z') num = 0;
                    if (str[k] > 'z' || str[k] < 'A') num = 0;
                } else if (inWord == 1 && str[k] == ' ') {
                    if (num == 1) count++;
                    num = 0;
                    inWord = 0;
                }
                k++;
            }
            if (inWord == 1 && num == 1) count++;
            return count;
    }

        unsigned int faStr3(const char* str) {
                int k = 0,
                    count = 0,
                    inWord = 0,
                    O = 0,
                    result;
                float S = 0;
                while (str[k] != '\0') {
                    if (inWord == 0 && str[k] != ' ') {
                        count++;
                        inWord = 1;
                        O++;
                    } else if (inWord == 1 && str[k] != ' ') {
                        O++;
                    } else if (inWord == 1 && str[k] == ' ') {
                        S = S + O;
                        inWord = 0;
                        O = 0;
                    }
                    k++;
                }
                if (inWord == 1) S = S + O;
                S = S / static_cast<float>(count);
                result = S;
                return result;
        }
