// Copyright 2022 UNN-IASR
#include "fun.h"
#include <cctype>

unsigned int faStr1(const char *str) {
    enum State { S_SPACE, S_WORD_CLEAN, S_WORD_DIRTY };
    State state = S_SPACE;
    unsigned int count = 0;

    for (int i = 0; str[i] != '\0'; i++) {
        char c = str[i];
        bool sp  = isspace(static_cast<unsigned char>(c));
        bool dig = isdigit(static_cast<unsigned char>(c));

        switch (state) {
        case S_SPACE:
            if (!sp) {
                state = dig ? S_WORD_DIRTY : S_WORD_CLEAN;
            }
            break;
        case S_WORD_CLEAN:
            if (sp) {
                count++;
                state = S_SPACE;
            } else if (dig) {
                state = S_WORD_DIRTY;
            }
            break;
        case S_WORD_DIRTY:
            if (sp) {
                state = S_SPACE;
            }
            break;
        }
    }
    if (state == S_WORD_CLEAN) {
        count++;
    }
    return count;
}

unsigned int faStr2(const char *str) {
    enum State { S_SPACE, S_WORD_GOOD, S_WORD_BAD };
    State state = S_SPACE;
    unsigned int count = 0;

    for (int i = 0; str[i] != '\0'; i++) {
        char c = str[i];
        bool sp    = isspace(static_cast<unsigned char>(c));
        bool upper = (c >= 'A' && c <= 'Z');
        bool lower = (c >= 'a' && c <= 'z');

        switch (state) {
        case S_SPACE:
            if (!sp) {
                state = upper ? S_WORD_GOOD : S_WORD_BAD;
            }
            break;
        case S_WORD_GOOD:
            if (sp) {
                count++;
                state = S_SPACE;
            } else if (!lower) {
                state = S_WORD_BAD;
            }
            break;
        case S_WORD_BAD:
            if (sp) {
                state = S_SPACE;
            }
            break;
        }
    }
    if (state == S_WORD_GOOD) {
        count++;
    }
    return count;
}

unsigned int faStr3(const char *str) {
    enum State { S_SPACE, S_WORD };
    State state = S_SPACE;
    unsigned int wordCount  = 0;
    unsigned int totalChars = 0;
    unsigned int curLen     = 0;

    for (int i = 0; str[i] != '\0'; i++) {
        char c = str[i];
        bool sp = isspace(static_cast<unsigned char>(c));

        switch (state) {
        case S_SPACE:
            if (!sp) {
                curLen = 1;
                state = S_WORD;
            }
            break;
        case S_WORD:
            if (sp) {
                wordCount++;
                totalChars += curLen;
                curLen = 0;
                state = S_SPACE;
            } else {
                curLen++;
            }
            break;
        }
    }
    if (state == S_WORD) {
        wordCount++;
        totalChars += curLen;
    }
    if (wordCount == 0) {
        return 0;
    }
    return (totalChars + wordCount / 2) / wordCount;
}
