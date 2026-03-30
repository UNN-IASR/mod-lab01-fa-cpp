// Copyright 2022 UNN-IASR
#include <cmath>
#include <cctype>
#include "fun.h"

unsigned int faStr1(const char* str) {
    if (str == nullptr || str[0] == '\0')
        return 0;

    int i = 0;
    unsigned int count = 0;

    while (str[i] != '\0') {
        while (str[i] != '\0' && !std::isalnum(static_cast<unsigned char>(str[i]))) {
            i++;
        }

        if (str[i] == '\0')
            break;

        bool has_digit = false;
        bool has_letter = false;

        while (str[i] != '\0' && std::isalnum(static_cast<unsigned char>(str[i]))) {
            if (std::isdigit(static_cast<unsigned char>(str[i])))
                has_digit = true;
            if (std::isalpha(static_cast<unsigned char>(str[i])))
                has_letter = true;
            i++;
        }

        if (has_letter && !has_digit)
            count++;
    }

    return count;
}

unsigned int faStr2(const char* str) {
    if (str == nullptr || str[0] == '\0')
        return 0;

    int i = 0;
    unsigned int count = 0;

    while (str[i] != '\0') {
        while (str[i] != '\0' && !std::isalpha(static_cast<unsigned char>(str[i]))) {
            i++;
        }

        if (str[i] == '\0')
            break;

        bool ok = true;

        if (!std::isupper(static_cast<unsigned char>(str[i]))) {
            while (str[i] != '\0' && std::isalpha(static_cast<unsigned char>(str[i]))) {
                i++;
            }
            continue;
        }

        i++;

        while (str[i] != '\0' && std::isalpha(static_cast<unsigned char>(str[i]))) {
            if (!std::islower(static_cast<unsigned char>(str[i])))
                ok = false;
            i++;
        }

        if (ok)
            count++;
    }

    return count;
}

unsigned int faStr3(const char* str) {
    if (str == nullptr || str[0] == '\0')
        return 0;

    int i = 0;
    int letters_count = 0;
    int words_count = 0;

    while (str[i] != '\0') {
        while (str[i] != '\0' && !std::isalpha(static_cast<unsigned char>(str[i]))) {
            i++;
        }

        if (str[i] == '\0')
            break;

        int current_len = 0;

        while (str[i] != '\0' && std::isalpha(static_cast<unsigned char>(str[i]))) {
            current_len++;
            i++;
        }

        if (current_len > 0) {
            letters_count += current_len;
            words_count++;
        }
    }

    if (words_count == 0)
        return 0;

    return static_cast<unsigned int>(
        std::round(static_cast<double>(letters_count) / words_count));
}
