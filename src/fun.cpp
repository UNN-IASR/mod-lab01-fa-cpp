// Copyright 2022 UNN-IASR
#include "fun.h"
#include <math.h>
#include <ctype.h>

unsigned int faStr1(const char *str) {
    unsigned int answer = 0;
    bool isInWord = false;
    bool containsNumbers = false;
    int i = 0;
    while (str[i] != '\0') {
        if (!isInWord && str[i] != ' ') {
            isInWord = true;
            containsNumbers = isdigit(str[i]);
        } else if (isInWord && str[i] != ' ') {
            if (isdigit(str[i]))
                containsNumbers = true;
        }
        if (isInWord && (str[i] == ' ' || str[i+1] == '\0')) {
            if (!containsNumbers)
                answer++;
            containsNumbers = false;
            isInWord = false;
        }

        i++;
    }
    return answer;
}

unsigned int faStr2(const char *str) {
    unsigned int answer = 0;
    bool isInWord = false;
    bool isAcceptable = true;
    int i = 0;
    while (str[i] != '\0') {
        if (!isInWord && str[i] != ' ') {
            isInWord = true;
            isAcceptable = isupper(str[i]);
        } else if (isInWord && str[i] != ' ') {
            if (!islower(str[i]))
                isAcceptable = false;
        }
        if (isInWord && (str[i] == ' ' || str[i+1] == '\0')) {
            if (isAcceptable)
                answer++;
            isAcceptable = true;
            isInWord = false;
        }

        i++;
    }
    return answer;
}

unsigned int faStr3(const char *str) {
    unsigned int wordsCount = 0;
    unsigned int sumLength = 0;
    bool isInWord = false;
    int i = 0;
    while (str[i] != '\0') {
        if (!isInWord && str[i] != ' ') {
            isInWord = true;
            wordsCount++;
            sumLength++;
        } else if (isInWord && str[i] != ' ') {
            sumLength++;
        }
        if (isInWord && (str[i] == ' ' || str[i+1] == '\0'))
            isInWord = false;

        i++;
    }
    double length = static_cast<double>(sumLength);
    return static_cast<int>(round(length / wordsCount));
}
