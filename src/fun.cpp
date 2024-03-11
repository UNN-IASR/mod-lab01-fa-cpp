// Copyright 2022 UNN-IASR
#include "fun.h"

unsigned int faStr1(const char *str) {
    return 0;
}

unsigned int faStr2(const char *str) {
    unsigned int count = 0;
    bool inWord = false;
    int UpperWordMark = 0;


    for (int i = 0; str[i] != '\0'; i++) {
        if (isupper(str[i])) {
            inWord = true;
            UpperWordMark = i;
        }


        else if (inWord && !islower(str[i]) && !isspace(str[i])) {
            for (int j = UpperWordMark; j <= i; j++) {
                if (!isalpha(str[j])) {
                    inWord = false;
                }
            }
            if (inWord) {
                count++;
            }
 
            inWord = false;
        }

        else if (inWord && !islower(str[i]) && isspace(str[i])) {
            for (int j = UpperWordMark; j < i; j++) {
                if (!isalpha(str[j])) {
                    inWord = false;
                }
            }
            if (inWord) {
                count++;
            }

            inWord = false;
        }

        else if (inWord && islower(str[i])) {
            continue;
        }

    }


    return count;
}

unsigned int faStr3(const char *str) {
    return 0;
}
