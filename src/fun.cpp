// Copyright 2022 UNN-IASR

#include "fun.h"

bool isSpace(char c) {
    return c == ' ';
}

bool isDigit(char c) {
    return c >= '0' && c <= '9';
}

bool isUpperLatin(char c) {
    return c >= 'A' && c <= 'Z';
}

bool isLowerLatin(char c) {
    return c >= 'a' && c <= 'z';
}

unsigned int faStr1(const char *str) {
    if (str == nullptr) {
        return 0;
    }

    unsigned int count = 0;
    int i = 0;

    while (str[i] != '\0') {
        while (str[i] != '\0' && isSpace(str[i])) {
            i++;
        }

        if (str[i] == '\0') {
            break;
        }

        bool hasDigit = false;

        while (str[i] != '\0' && !isSpace(str[i])) {
            if (isDigit(str[i])) {
                hasDigit = true;
            }
            i++;
        }

        if (!hasDigit) {
            count++;
        }
    }

    return count;
}

unsigned int faStr2(const char *str) {
    if (str == nullptr) {
        return 0;
    }

    unsigned int count = 0;
    int i = 0;

    while (str[i] != '\0') {
        while (str[i] != '\0' && isSpace(str[i])) {
            i++;
        }

        if (str[i] == '\0') {
            break;
        }

        bool valid = true;
        int wordLength = 0;

        if (!isUpperLatin(str[i])) {
            valid = false;
        }

        wordLength++;
        i++;

        while (str[i] != '\0' && !isSpace(str[i])) {
            if (!isLowerLatin(str[i])) {
                valid = false;
            }
            wordLength++;
            i++;
        }

        if (valid && wordLength > 0) {
            count++;
        }
    }

    return count;
}

unsigned int faStr3(const char *str) {
    if (str == nullptr) {
        return 0;
    }

    unsigned int wordCount = 0;
    unsigned int totalLength = 0;
    int i = 0;

    while (str[i] != '\0') {
        while (str[i] != '\0' && isSpace(str[i])) {
            i++;
        }

        if (str[i] == '\0') {
            break;
        }

        unsigned int currentLength = 0;

        while (str[i] != '\0' && !isSpace(str[i])) {
            currentLength++;
            i++;
        }

        totalLength += currentLength;
        wordCount++;
    }

    if (wordCount == 0) {
        return 0;
    }

    return (totalLength + wordCount / 2) / wordCount;
}
