// Copyright 2026 <UNN-IASR>

#include "fun.h"
#include <cctype>
#include <cmath>

// Задача 1: слова без цифр
unsigned int faStr1(const char *str) {
    // Состояния: 0 - вне слова,
    // 1 - в слове (цифр нет), 2 - в слове (есть цифра)
    int state = 0;
    unsigned int count = 0;

    for (int i = 0; str[i] != '\0'; i++) {
        char c = str[i];
        bool isSpace = isspace(c);
        bool isDigit = isdigit(c);

        switch (state) {
            case 0:
                if (!isSpace) {
                    state = isDigit ? 2 : 1;
                }
                break;
            case 1:
                if (isSpace) {
                    count++;
                    state = 0;
                } else if (isDigit) {
                    state = 2;
                }
                break;
            case 2:
                if (isSpace) state = 0;
                break;
        }
    }
    if (state == 1) count++;
    return count;
}

// Задача 2: слова вида [A-Z][a-z]*
unsigned int faStr2(const char *str) {
    // Состояния: 0 - вне слова, 1 - первый символ заглавный,
    // 2 - продолжение (только строчные), 3 - слово не подходит
    int state = 0;
    unsigned int count = 0;

    for (int i = 0; str[i] != '\0'; i++) {
        char c = str[i];
        bool isSpace = isspace(c);
        bool isUpper = isupper(c) && isalpha(c);
        bool isLower = islower(c) && isalpha(c);

        switch (state) {
            case 0:
                if (!isSpace) {
                    state = isUpper ? 1 : 3;
                }
                break;
            case 1:
                if (isSpace) {
                    count++;
                    state = 0;
                } else if (isLower) {
                    state = 2;
                } else {
                    state = 3;
                }
                break;
            case 2:
                if (isSpace) {
                    count++;
                    state = 0;
                } else if (!isLower) {
                    state = 3;
                }
                break;
            case 3:
                if (isSpace) state = 0;
                break;
        }
    }
    if (state == 1 || state == 2) count++;
    return count;
}

// Задача 3: средняя длина слова
unsigned int faStr3(const char *str) {
    int state = 0;
    unsigned int totalLen = 0;
    unsigned int wordCount = 0;
    unsigned int curLen = 0;

    for (int i = 0; str[i] != '\0'; i++) {
        char c = str[i];
        bool isSpace = isspace(c);

        switch (state) {
            case 0:
                if (!isSpace) {
                    state = 1;
                    curLen = 1;
                }
                break;
            case 1:
                if (isSpace) {
                    totalLen += curLen;
                    wordCount++;
                    state = 0;
                } else {
                    curLen++;
                }
                break;
        }
    }
    if (state == 1) {
        totalLen += curLen;
        wordCount++;
    }

    if (wordCount == 0) return 0;
    return static_cast<unsigned int>(
        round(static_cast<double>(totalLen) / wordCount));
}