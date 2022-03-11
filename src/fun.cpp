// Copyright 2022 UNN-IASR
#include "fun.h"
#include <ctype.h>
#include <math.h>

unsigned int faStr1(const char *str) {
    int count = 0;
    bool in_word = false;
    int iteration = 0;
    bool contains_number = false;
    while (str[iteration]) {
        char current_char = str[iteration];
        if (in_word == false && current_char != ' ') {
            in_word = true;
            count++;
        } else if (in_word == true && current_char == ' ') {
            if (contains_number) {
                contains_number = false;
                count--;
            }
            in_word = false;
        }
        if (in_word == true && isdigit(current_char)) {
            contains_number = true;
        }
        iteration++;
    }
    if (contains_number) {
        return count - 1;
    }
    return count;
}

unsigned int faStr2(const char *str) {
    int count = 0;
    bool in_word = false;
    int iteration = 0;
    bool correct_word = false;
    while (str[iteration]) {
        char current_char = str[iteration];
        int number_of_char = static_cast<int>(current_char);
        if (in_word == false && current_char != ' ') {
            in_word = true;
            if (65 <= number_of_char && number_of_char <= 90) {
                correct_word = true;
            }
            count++;
        } else if (in_word == true && current_char == ' ') {
            if (!correct_word) {
                count--;
            }
            correct_word = false;
            in_word = false;
        } else if (in_word == true && current_char != ' ') {
            if (number_of_char < 97 || number_of_char > 122) {
                correct_word = false;
            }
        }
        iteration++;
    }
    if (correct_word == false) {
        return count - 1;
    }
    return count;
}

unsigned int faStr3(const char *str) {
    int count = 0;
    float characters = 0;
    bool in_word = false;
    int iteration = 0;
    while (str[iteration]) {
        char current_char = str[iteration];
        if (in_word == false && current_char != ' ') {
            in_word = true;
            count++;
        } else if (in_word == true && current_char == ' ') {
            in_word = false;
        }
        if (in_word == true) {
            characters++;
        }
        iteration++;
    }
    return round(characters / count);
}
