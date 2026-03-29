// Copyright 2022 UNN-IASR
#include "fun.h"

unsigned int faStr1(const char* str) {
    if (!str) return 0;

    unsigned int cnt = 0;
    const char* p = str;

    while (*p) {
        while (*p == ' ') ++p;
        if (!*p) break;

        bool hasDigit = false;

        for (; *p && *p != ' '; ++p) {
            if (*p >= '0' && *p <= '9')
                hasDigit = true;
        }

        if (!hasDigit)
            ++cnt;
    }

    return cnt;
}

unsigned int faStr2(const char* str) {
    if (!str) return 0;

    unsigned int cnt = 0;
    const char* p = str;

    while (*p) {
        while (*p == ' ') ++p;
        if (!*p) break;

        bool val = true;
        int pos = 0;

        for (; *p && *p != ' '; ++p, ++pos) {
            if (pos == 0) {
                if (!(*p >= 'A' && *p <= 'Z'))
                    val = false;
            }
            else {
                if (!(*p >= 'a' && *p <= 'z'))
                    val = false;
            }
        }

        if (val && pos > 0)
            ++cnt;
    }

    return cnt;
}

unsigned int faStr3(const char* str) {
    if (!str) return 0;

    const char* p = str;
    unsigned int words = 0;
    unsigned int total = 0;

    while (*p) {
        while (*p == ' ') ++p;
        if (!*p) break;

        int len = 0;

        for (; *p && *p != ' '; ++p)
            ++len;

        total += len;
        ++words;
    }

    if (words == 0)
        return 0;

    return (total + words / 2) / words;
}