// Copyright 2022 UNN-IASR
#include "fun.h"

unsigned int faStr1(const char *str) {
    unsigned int count = 0;
    bool in_word = false;
    bool has_digit = false;

    for (const char *p = str; ; ++p) {
        char c = *p;
        bool is_space = (c == ' ' || c == '\t' || c == '\n' ||
                         c == '\r' || c == '\f' || c == '\v');

        if (c == '\0' || is_space) {
            if (in_word) {
                if (!has_digit) {
                    ++count;
                }
                in_word = false;
                has_digit = false;
            }
            if (c == '\0') {
                break;
            }
        } else {
            if (!in_word) {
                in_word = true;
                has_digit = false;
            }
            if (c >= '0' && c <= '9') {
                has_digit = true;
            }
        }
    }

    return count;
}

unsigned int faStr2(const char *str) {
    unsigned int count = 0;
    bool in_word = false;
    bool valid_word = false;
    bool first_char = false;

    for (const char *p = str; ; ++p) {
        char c = *p;
        bool is_space = (c == ' ' || c == '\t' || c == '\n' ||
                         c == '\r' || c == '\f' || c == '\v');

        if (c == '\0' || is_space) {
            if (in_word) {
                if (valid_word) {
                    ++count;
                }
                in_word = false;
                valid_word = false;
                first_char = false;
            }
            if (c == '\0') {
                break;
            }
        } else {
            if (!in_word) {
                in_word = true;
                first_char = true;
                valid_word = (c >= 'A' && c <= 'Z');
            } else if (valid_word) {
                if (first_char) {
                    first_char = false;
                }
                if (!(c >= 'a' && c <= 'z')) {
                    valid_word = false;
                }
            }
        }
    }

    return count;
}

unsigned int faStr3(const char *str) {
    unsigned int words_count = 0;
    unsigned int total_length = 0;
    unsigned int current_length = 0;
    bool in_word = false;

    for (const char *p = str; ; ++p) {
        char c = *p;
        bool is_space = (c == ' ' || c == '\t' || c == '\n' ||
                         c == '\r' || c == '\f' || c == '\v');

        if (c == '\0' || is_space) {
            if (in_word) {
                total_length += current_length;
                ++words_count;
                current_length = 0;
                in_word = false;
            }
            if (c == '\0') {
                break;
            }
        } else {
            in_word = true;
            ++current_length;
        }
    }

    if (words_count == 0) {
        return 0;
    }

    return (total_length + words_count / 2) / words_count;
}
