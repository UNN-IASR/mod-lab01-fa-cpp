// Copyright 2022 UNN-IASR
#include "fun.h"
#include <cctype>
#include <cmath>

unsigned int faStr1(const char *str) {
    if (!str) return 0;
    
    unsigned int count = 0;
    bool inWord = false;
    bool hasDigit = false;
    
    for (const char *p = str; *p != '\0'; ++p) {
        if (std::isspace(*p)) {
            if (inWord && !hasDigit) {
                ++count;
            }
            inWord = false;
            hasDigit = false;
        } else {
            if (!inWord) {
                inWord = true;
                hasDigit = false;
            }
            if (std::isdigit(*p)) {
                hasDigit = true;
            }
        }
    }
    if (inWord && !hasDigit) {
        ++count;
    }
    return count;
}

unsigned int faStr2(const char *str) {
    if (!str) return 0;
    
    unsigned int count = 0;
    bool inWord = false;
    bool valid = true;
    bool firstChar = true;
    
    for (const char *p = str; *p != '\0'; ++p) {
        if (std::isspace(*p)) {
            if (inWord && valid) {
                ++count;
            }
            inWord = false;
            firstChar = true;
            valid = true;
        } else {
            if (!inWord) {
                inWord = true;
                firstChar = true;
                valid = true;
            }
            
            if (firstChar) {
                if (!(*p >= 'A' && *p <= 'Z')) {
                    valid = false;
                }
                firstChar = false;
            } else {
                if (!(*p >= 'a' && *p <= 'z')) {
                    valid = false;
                }
            }
        }
    }
    if (inWord && valid) {
        ++count;
    }
    return count;
}

unsigned int faStr3(const char *str) {
    if (!str) return 0;
    
    unsigned int totalLength = 0;
    unsigned int wordCount = 0;
    bool inWord = false;
    unsigned int currentLength = 0;
    
    for (const char *p = str; *p != '\0'; ++p) {
        if (std::isspace(*p)) {
            if (inWord) {
                totalLength += currentLength;
                ++wordCount;
                inWord = false;
                currentLength = 0;
            }
        } else {
            if (!inWord) {
                inWord = true;
                currentLength = 0;
            }
            ++currentLength;
        }
    }
    if (inWord) {
        totalLength += currentLength;
        ++wordCount;
    }
    
    if (wordCount == 0) return 0;
    
    double average = static_cast<double>(totalLength) / wordCount;
    return static_cast<unsigned int>(std::round(average));
}
