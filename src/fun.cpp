#include "fun.h"
#include <cctype>
#include <cmath>

unsigned int faStr1(const char *str) {
    int сountWord = 0;
    int i = 0;
    bool inWord = false;
    bool isDigits = false;    
    while (str[i]) {
        if (!isspace(str[i])) {
            inWord = true;
            if (isdigit(str[i])) isDigits = true;
        } else {
            if (inWord) {
                if (!isDigits) {
                    сountWord ++;
                } else isDigits = false;
                inWord = false;
            }
        }
        i++;
    }
    return сountWord;
}

unsigned int faStr2(const char *str) {
    int сountWord = 0;
    int i = 0;
    bool inWord = false;
    bool isGood = false;
    //bool isBLat = false;
    //bool isFirst = false;
    //bool isSLat = false;
    while (str[i]) {
        if (!isspace(str[i])) {
            if (!inWord) {
                if (isalpha(str[i]) && isupper(str[i])) isGood = true;
                inWord = true; 
            } else {
                if (isGood) {
                    if (!isalpha(str[i])) isGood = false;
                }
            }
        } else {
            if (inWord) {
                if (isGood) сountWord++;
                inWord = false;
                isGood = false;
            }
        }
        i++;
    }
    return сountWord;
}

unsigned int faStr3(const char *str) {
    int сountWord = 0;
    int countSign = 0;
    int i = 0;
    bool inWord = false;
    while (str[i]) {
        if (!isspace(str[i])) {
            countSign++;
            if (!inWord) {
                inWord = true;
                сountWord++;
            }
        } else {
            if (inWord) inWord = false;
        }
        i++;
    }
    return round(countSign / сountWord);
}
