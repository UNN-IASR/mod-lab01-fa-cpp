// Copyright 2022 UNN-IASR
#include <cmath>
#include "fun.h"

unsigned int faStr1(const char* str) {
    if (str == nullptr || str[0] == '\0')
        return 0;

    int i = 0;
    unsigned int count = 0;

    while (str[i] != '\0') {
        while (str[i] == ' ') {
            i++;
        }

        if (str[i] == '\0')
            break;

        bool only_letters = true;
        bool has_chars = false;

        while (str[i] != ' ' && str[i] != '\0') {
            has_chars = true;
            if (!(str[i] >= 'A' && str[i] <= 'Z') &&
                !(str[i] >= 'a' && str[i] <= 'z')) {
                only_letters = false;
            }
            i++;
        }

        if (has_chars && only_letters) {
            count++;
        }
    }

    return count;
}

unsigned int faStr2(const char* str) {
    if (str == nullptr || str[0] == '\0')
        return 0;

    int i = 0;
    unsigned int count = 0;

    while (str[i] != '\0') {
        while (str[i] == ' ') {
            i++;
        }

        if (str[i] == '\0')
            break;

        bool is_valid = true;
        int word_len = 0;

        if (!(str[i] >= 'A' && str[i] <= 'Z')) {
            while (str[i] != ' ' && str[i] != '\0') {
                i++;
            }
            continue;
        }

        word_len++;
        i++;

        while (str[i] != ' ' && str[i] != '\0') {
            word_len++;
            if (!(str[i] >= 'a' && str[i] <= 'z')) {
                is_valid = false;
            }
            i++;
        }

        if (word_len > 0 && is_valid) {
            count++;
        }
    }

    return count;
}

unsigned int faStr3(const char* str) {
    if (str == nullptr || str[0] == '\0')
        return 0;

    int i = 0;
    int total_len = 0;
    int word_count = 0;

    while (str[i] != '\0') {
        while (str[i] == ' ') {
            i++;
        }

        if (str[i] == '\0')
            break;

        int current_len = 0;

        while (str[i] != ' ' && str[i] != '\0') {
            current_len++;
            i++;
        }

        if (current_len > 0) {
            total_len += current_len;
            word_count++;
        }
    }

    if (word_count == 0)
        return 0;

    return static_cast<unsigned int>(
        std::round(static_cast<double>(total_len) / word_count));
}
