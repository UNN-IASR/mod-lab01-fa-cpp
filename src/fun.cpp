// Copyright 2022 UNN-IASR
#include "fun.h"
#include <cctype>

unsigned int faStr1(const char *str) {
    if (!str) return 0;
    unsigned int count = 0;
    bool inWord = false, hasDigit = false;

    while (*str) {
        if (std::isspace(static_cast<unsigned char>(*str))) {
            if (inWord && !hasDigit) ++count;
            inWord = false;
            hasDigit = false;
        } else {
            inWord = true;
            if (std::isdigit(static_cast<unsigned char>(*str))) hasDigit = true;
        }
        ++str;
    }
    if (inWord && !hasDigit) ++count;
    return count;
}

unsigned int faStr2(const char *str) {
    if (!str) return 0;
    unsigned int count = 0;
    bool inWord = false, validStart = false, validBody = true;

    while (*str) {
        unsigned char ch = static_cast<unsigned char>(*str);
        if (std::isspace(ch)) {
            if (inWord && validStart && validBody) ++count;
            inWord = false; validStart = false; validBody = true;
        } else {
            if (!inWord) {
                validStart = (ch >= 'A' && ch <= 'Z');
                validBody = true;
                inWord = true;
            } else {
                if (!(ch >= 'a' && ch <= 'z')) validBody = false;
            }
        }
        ++str;
    }
    if (inWord && validStart && validBody) ++count;
    return count;
}

unsigned int faStr3(const char *str) {
    if (!str) return 0;
    unsigned int totalLen = 0, wordCount = 0, curLen = 0;

    while (*str) {
        if (std::isspace(static_cast<unsigned char>(*str))) {
            if (curLen > 0) { totalLen += curLen; ++wordCount; curLen = 0; }
        } else {
            ++curLen;
        }
        ++str;
    }
    if (curLen > 0) { totalLen += curLen; ++wordCount; }

    return wordCount == 0 ? 0 : (totalLen + wordCount / 2) / wordCount;
}
