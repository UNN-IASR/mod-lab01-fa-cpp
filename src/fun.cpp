// Copyright 2022 UNN-IASR
#include "fun.h"
#include <cctype>

// Task 1
unsigned int faStr1(const char *str) {
    enum State { S_SPACE, S_VALID, S_DIGIT };
    State state = S_SPACE;
    unsigned int count = 0;

    for (const char *p = str; ; ++p) {
        char c = *p;

        switch (state) {
            case S_SPACE:
                if (c == '\0') {
                    return count;
                } else if (isspace((unsigned char)c)) {
                } else if (isdigit((unsigned char)c)) {
                    state = S_DIGIT;
                } else {
                    state = S_VALID;
                }
                break;

            case S_VALID:
                if (c == '\0') {
                    ++count;
                    return count;
                } else if (isspace((unsigned char)c)) {
                    ++count;
                    state = S_SPACE;
                } else if (isdigit((unsigned char)c)) {
                    state = S_DIGIT;
                } else {
                }
                break;

            case S_DIGIT:
                if (c == '\0') {
                    return count;
                } else if (isspace((unsigned char)c)) {
                    state = S_SPACE;
                } else {
                }
                break;
        }
    }
}

// Task 2
unsigned int faStr2(const char *str) {
    enum State { S_SPACE, S_UPPER, S_LOWER, S_REJECT };
    State state = S_SPACE;
    unsigned int count = 0;

    for (const char *p = str; ; ++p) {
        char c = *p;

        switch (state) {
            case S_SPACE:
                if (c == '\0') {
                    return count;
                } else if (isspace((unsigned char)c)) {
                } else if (c >= 'A' && c <= 'Z') {
                    state = S_UPPER;
                } else {
                    state = S_REJECT;
                }
                break;

            case S_UPPER:
                if (c == '\0') {
                    ++count;
                    return count;
                } else if (isspace((unsigned char)c)) {
                    ++count;
                    state = S_SPACE;
                } else if (c >= 'a' && c <= 'z') {
                    state = S_LOWER;
                } else {
                    state = S_REJECT;
                }
                break;

            case S_LOWER:
                if (c == '\0') {
                    ++count;
                    return count;
                } else if (isspace((unsigned char)c)) {
                    ++count;
                    state = S_SPACE;
                } else if (c >= 'a' && c <= 'z') {
                } else {
                    state = S_REJECT;
                }
                break;

            case S_REJECT:
                if (c == '\0') {
                    return count;
                } else if (isspace((unsigned char)c)) {
                    state = S_SPACE;
                }
                break;
        }
    }
}

// Task 3
unsigned int faStr3(const char *str) {
    enum State { S_SPACE, S_WORD };
    State state = S_SPACE;
    unsigned int totalLen = 0;
    unsigned int wordCount = 0;
    unsigned int curLen = 0;

    for (const char *p = str; ; ++p) {
        char c = *p;

        switch (state) {
            case S_SPACE:
                if (c == '\0') {
                    if (wordCount == 0) return 0;
                    return (totalLen + wordCount / 2) / wordCount;
                } else if (isspace((unsigned char)c)) {
                } else {
                    curLen = 1;
                    state = S_WORD;
                }
                break;

            case S_WORD:
                if (c == '\0') {
                    totalLen += curLen;
                    ++wordCount;
                    if (wordCount == 0) return 0;
                    return (totalLen + wordCount / 2) / wordCount;
                } else if (isspace((unsigned char)c)) {
                    totalLen += curLen;
                    ++wordCount;
                    state = S_SPACE;
                } else {
                    ++curLen;
                }
                break;
        }
    }
}
