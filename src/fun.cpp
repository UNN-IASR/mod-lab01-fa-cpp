// Copyright 2022 UNN-IASR
#include <cctype>
#include <vector>
#include <cstring>
#include <cmath>
unsigned int faStr1(const char *str) {
    int i = 0;
    int wordCounter = 0;
    bool inWordIndicator = false;
    bool hasDigits = false;
    while (str[i] != '\0') {
        if (!isspace(str[i])) {
            inWordIndicator = true;
            if (isdigit(str[i])) {
                hasDigits = true;
            }
        } else {
            if (inWordIndicator) {
                if (!hasDigits)
                    wordCounter++;
                hasDigits = false;
                inWordIndicator = false;
            }
        }
        i++;
    }
    if (inWordIndicator) {
        if (!hasDigits)
            wordCounter++;
    }
    return wordCounter;
}
unsigned int faStr2(const char *str) {
int i = 0;
    int wordCounter = 0;
    bool inWordIndicator = false;
    bool goodWordIndicator = false;
    while (str[i] != '\0') {
        if (!isspace(str[i])) {
            if (!inWordIndicator) {
                if (isalpha(str[i]) && isupper(str[i])) {
                    goodWordIndicator = true;
                }
                inWordIndicator = true;
            } else {
                if (goodWordIndicator) {
                    if (!isalpha(str[i])) {
                        goodWordIndicator = false;
                    }
                }
            }
        } else {
            if (inWordIndicator) {
                if (goodWordIndicator)
                    wordCounter++;
                goodWordIndicator = false;
                inWordIndicator = false;
            }
        }
        i++;
    }
    return wordCounter;
}
unsigned int faStr3(const char *str) {
    using std::vector;
    vector <int> wordsLength;
    int i = 0;
    int wordCounter = 0;
    bool inWordIndicator = false;
    int beginIndex = -1;
    int endIndex = -1;
    while (str[i] != '\0') {
        if (!isspace(str[i])) {
            inWordIndicator = true;
            if (beginIndex == -1) {
                beginIndex = i;
            }
        } else {
            if (inWordIndicator) {
                wordCounter++;
                inWordIndicator = false;
                endIndex = i;
                wordsLength.push_back(endIndex - beginIndex);
                beginIndex = -1;
                endIndex = -1;
            }
        }
        i++;
    }
    if (inWordIndicator) {
        wordCounter++;
        endIndex = strlen(str);
        wordsLength.push_back(endIndex - beginIndex);
    }
    double sum = 0;
    for (int i = 0; i < wordsLength.size(); i++) {
        sum += wordsLength[i];
    }
    sum = round(sum / wordsLength.size());
    return sum;
}
