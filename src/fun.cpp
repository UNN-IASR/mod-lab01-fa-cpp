// Copyright 2024 <Copyright Owner>
#include "fun.h"
#include <cctype>

unsigned int faStr1(const char* str) {
    if (str == nullptr) return 0;

    unsigned int count = 0;
    int i = 0;

    while (str[i] != '\0') {
        while (str[i] != '\0' && isspace(str[i])) i++;

        if (str[i] == '\0') break;

        bool hasDigit = false;
        bool hasLetter = false;

        while (str[i] != '\0' && !isspace(str[i])) {
            if (isdigit(str[i]))
                hasDigit = true;
            else if (isalpha(str[i]))
                hasLetter = true;
            i++;
        }

        if (!hasDigit && hasLetter)
            count++;
    }

    return count;
}

unsigned int faStr2(const char* str) {
    if (str == nullptr) return 0;

    unsigned int count = 0;
    int i = 0;

    while (str[i] != '\0') {
        while (str[i] != '\0' && isspace(str[i])) i++;

        if (str[i] == '\0') break;

        bool valid = true;

        if (!isupper(str[i]) || !isalpha(str[i]))
            valid = false;

        i++;

        while (str[i] != '\0' && !isspace(str[i])) {
            if (!islower(str[i]) || !isalpha(str[i]))
                valid = false;
            i++;
        }

        if (valid)
            count++;
    }

    return count;
}

unsigned int faStr3(const char* str) {
    if (str == nullptr) return 0;

    unsigned int totalLength = 0;
    unsigned int wordCount = 0;
    int i = 0;

    while (str[i] != '\0') {
        while (str[i] != '\0' && isspace(str[i])) i++;

        if (str[i] == '\0') break;

        unsigned int length = 0;

        while (str[i] != '\0' && !isspace(str[i])) {
            length++;
            i++;
        }

        totalLength += length;
        wordCount++;
    }

    if (wordCount == 0)
        return 0;

    double average = static_cast<double>(totalLength) / wordCount;
    return static_cast<unsigned int>(average + 0.5);
}
