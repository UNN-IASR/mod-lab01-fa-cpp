// Copyright 2022 UNN-IASR
#include "fun.h"
#include <iostream>
#include <regex>

unsigned int faStr1(const char *str) {
    std::regex words("\\b[a-zA-Z]+\\b");
    std::regex numbers("[0-9]"); 
    std::string inputStr(str);
    std::sregex_iterator it(inputStr.begin(), inputStr.end(), words);
    std::sregex_iterator itEnd;
    unsigned int count = 0;
    while (it != itEnd) {
        std::smatch match = *it;
        std::string word = match.str();
        if (std::regex_search(word, numbers) == false) {
            count++;
        }
        ++it;
    }
    return count;
}

unsigned int faStr2(const char *str) {
    std::regex wordRegex(R"([A-Z][a-z,.]+)");
    std::string inputStr(str);
    std::sregex_iterator it(inputStr.begin(), inputStr.end(), wordRegex);
    std::sregex_iterator itEnd;
    unsigned int count = 0;
    for (; it != itEnd; ++it) {
        const std::smatch& match = *it;
        bool includesSeparators = false;
        for (char c : match.str()) {
            if (c == ' ' || c == ',' || c == '.') {
                includesSeparators = true;
                break;
            }
        }
        if (!includesSeparators) {
            ++count;
        }
    }
    return count;
}

unsigned int faStr3(const char *str) {
    std::string inputStr(str);
    int wordCount = 0;
    int totalWordLength = 0;
    bool inWord = false;
    for (char c : inputStr) {
        if (std::isalpha(c)) {
            inWord = true;
            totalWordLength++;
        } 
        else if (inWord) {
            wordCount++;
            inWord = false;
        }
    }
    if (inWord) {
        wordCount++;
    }
    if (wordCount == 0) {
        return 0; 
    }
    return totalWordLength / wordCount;
}
