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

    while (*str) {
        if (std::isalpha(*str)) {
            if (!inWord) {
                inWord = true;
                ++count;
            }
        } else {
            inWord = false;
        }
        ++str;
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
unsigned int faStr2(const char *str) {
    unsigned int count = 0;  // Count of words meeting the criteria
    bool inWord = false;  // If we are inside a word
    // If the first character of the word is an uppercase Latin letter
    bool isLatinUppercase = false;

    while (*str) {
        if (std::isalpha(*str)) {
            if (!inWord) {
                inWord = true;
                if (std::isupper(*str)) {
                    isLatinUppercase = true;
                } else {
                    isLatinUppercase = false;
                }
            } else {
                if (!std::islower(*str)) {
                    isLatinUppercase = false;
                }
            }
        } else {
            if (inWord && isLatinUppercase) {
                ++count;
            }
            inWord = false;
        }
        ++str;
    }

    if (inWord && isLatinUppercase) {
        ++count;
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
