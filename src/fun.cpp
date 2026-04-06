#include "fun.h"
#include <cctype>
#include <cmath>

unsigned int faStr1(const char* str) {
    bool in_word = false;
    bool has_digit = false;
    unsigned int cnt = 0;
    unsigned int i = 0;
    while (str[i]) {
        if (str[i] != ' ' && !in_word) {
            has_digit = false;
            in_word = true;
            cnt++;
        }
        if (str[i] != ' ' && in_word) {
            if (isdigit(str[i]) && !has_digit) {
                has_digit = true;
                cnt--;
            }
        }
        if (str[i] == ' ' && in_word) {
            in_word = false;
        }

        i++;
    }
    return cnt;
}
unsigned int faStr2(const char* str) {
    bool in_word = false;
    bool is_good_word = true;
    int cnt = 0;
    int i = 0;
    while (str[i]) {
        if (str[i] != ' ' && !in_word) {
            in_word = true;
            is_good_word = isupper(str[i]);
            if (is_good_word)
                cnt++;
        } else if ((!isalpha(str[i]) || isupper(str[i]))
            && str[i] != ' ' && in_word && is_good_word) {
            is_good_word = false;
            cnt--;
        } else if (str[i] == ' ' && in_word) {
            is_good_word = true;
            in_word = false;
        }
        i++;
    }
    return cnt;
}
unsigned int faStr3(const char* str) {
    float letter_cnt = 0;
    int word_cnt = 0;
    bool in_word = false;
    while (*str != '\0') {
        if (*str == ' ') {
            if (in_word) {
                word_cnt++;
            }
            in_word = false;
        } else {
            in_word = true;
            letter_cnt++;
        }
        str++;
    }
    if (in_word) {
        word_cnt++;
    }
    if (word_cnt == 0) {
        return 0;
    }
    unsigned int averageLength = round(letter_cnt / word_cnt);
    return averageLength;
}
