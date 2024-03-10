// Copyright 2022 UNN-IASR
#include "fun.h"
#include <cctype>
#include <cmath>

/**
 * Count the number of words in the given string that do not contain digits.
 *
 * @param str The input string to analyze.
 * @return The number of words without digits in the string.
 */
unsigned int faStr1(const char *str) {
    unsigned int count = 0;  // Count of words without digits
    bool inWord = false;  // Flag to indicate if we are inside a word
    bool lastDigit = false;

    while (*str) {
        if (std::isalpha(*str) || std::isdigit(*str)) {
            if (!inWord) {
                inWord = true;
                while (std::isalpha(*str) || std::isdigit(*str)) {
                    if (std::isdigit(*str)) {
                        inWord = false;
                        ++str;
                    }
                    ++str;
                }
                if (inWord) ++count;
            }
        } else {
            inWord = false;
            ++str;
        }
    }

    return count;
}

/**
 * Count the number of words in the given string that start with an uppercase Latin letter
 * and consist only of lowercase Latin letters among other characters.
 *
 * @param str The input string to analyze.
 * @return The number of words meeting the specified criteria.
 */
unsigned int faStr2(const char* str) {
    unsigned int count = 0;  // Count of words meeting the criteria
    bool valid = true;  // Flag to track validity of current word
    int start = -1;  // Index of the start of a word

    for (int idx = 0; str[idx] != '\0'; idx++) {
        if (str[idx] != ' ') {
            if (start != -1) {
                if (!('a' <= str[idx] && str[idx] <= 'z')) {
                    valid = false;
                }
            } else {
                if (!('A' <= str[idx] && str[idx] <= 'Z')) {
                    valid = false;
                }
                start = idx;
            }
        } else {
            if (valid && start != -1) {
                count++;
            }
            start = -1;
            valid = true;
        }
    }

    // Check if the last word in the string was valid and not empty
    if (valid && start != -1) {
        count++;
    }
    return count;
}

/**
 * Calculate the average length of words in the given string, rounding it to the nearest integer.
 *
 * @param str The input string to analyze.
 * @return The average length of words in the string, rounded to the nearest integer.
 */
unsigned int faStr3(const char *str) {
    unsigned int wordCount = 0;  // Count of words
    unsigned int totalLength = 0;  // Total length of words
    bool inWord = false;  // If we are inside a word

    while (*str) {
        if (std::isalpha(*str)) {
            if (!inWord) {
                inWord = true;
                ++wordCount;
            }
            ++totalLength;
        } else {
            inWord = false;
        }
        ++str;
    }

    // Calculate the average length of words
    unsigned int averageLength = 0;
    if (wordCount != 0) {
        averageLength = totalLength / wordCount;
    }

    // Round the average length to the nearest integer
    if (totalLength % wordCount * 2 >= wordCount) {
        averageLength += 1;
    }

    return averageLength;
}
