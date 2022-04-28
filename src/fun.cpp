// Copyright 2022 UNN-IASR

#include "fun.h"

unsigned int faStr1(const char *str)
{
    char a = str[0];
    int words_counter = 0;
    bool in_word = false;
    bool is_word_contains_numb = false;
    int words_with_numb = 0;
    for (int i = 0; str[i] != '\0'; i++) {
        if (str[i] != ' ') {
            //new word
            if (!in_word) {
                in_word = true;
                words_counter++;
            }
            else {
                //inside word
                if (str[i] >= '0' && str[i] <= '9') {
                    is_word_contains_numb = true;
                }
            }
            
        }
        //word ending
        if (str[i] == ' ' && in_word) {
            if (!is_word_contains_numb) {
                words_with_numb++;
            }
            is_word_contains_numb = false;
            in_word = false;
        }
    }
    return words_with_numb;
}
unsigned int faStr2(const char *str)
{
    char a = str[0];
    int words_counter = 0;
    bool in_word = false;
    bool is_word_starts_with_capital_letter = false;
    int searched_words_counter = 0;
    bool second_switcher = false;
    for (int i = 0; str[i] != '\0'; i++) {
        if (str[i] != ' ') {
            //new word
            if (!in_word) {
                if (str[i] >= 'A' && str[i] <= 'Z') {
                    is_word_starts_with_capital_letter = true;
                }
                in_word = true;
                words_counter++;
            }
            else {
                if (str[i] <= 'a' || str[i] >= 'z') {
                    second_switcher = true;
                }
            }

        }
        //word ending
        if (str[i] == ' ' && in_word) {
            if (is_word_starts_with_capital_letter && !second_switcher) {
                searched_words_counter++;
            }
            is_word_starts_with_capital_letter = false;
            second_switcher = false;
            in_word = false;
        }
    }
    return searched_words_counter;
}
unsigned int faStr3(const char *str)
{
    char a = str[0];
    int words_counter = 0;
    bool in_word = false;
    int sum_word_symbols = 0;
    for (int i = 0; str[i] != '\0'; i++) {
        if (str[i] != ' ') {
            //new word
            if (!in_word) {
                in_word = true;
                words_counter++;
            }
            sum_word_symbols++;

        }
        //word ending
        if (str[i] == ' ' && in_word) {
            in_word = false;
        }
    }
    return sum_word_symbols / words_counter;
}
