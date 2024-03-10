#include <iostream>
#include <cmath>
#include <cctype>

unsigned int faStr1(const char *str) {
    bool isNumber = false;
    bool inWord = false;
    int counter = 0;
    int i=0;
    while(str[i] != '\0') {
        if(str[i] != ' ' && !inWord) {
            inWord = true;
            isNumber = false;
            counter++;
        } else if((str[i] >= '0') && (str[i] <= '9') && inWord && !isNumber) {
            isNumber = true; 
            counter--;
        } else if(str[i] == ' ' && inWord) {
            isNumber = false;
            inWord = false;
        }
        i++;
    }
    return counter;
}

unsigned int faStr2(const char *str) {
    bool isCorrectWord = false;
    bool inWord = false;
    int counter = 0;
    int i=0;
    while(str[i] != '\0') {
        if(str[i] != ' ' && !inWord) {
            inWord = true;
            isCorrectWord = isupper(str[i]);
            counter += isCorrectWord;
        } else if(str[i] == ' ' && inWord) {
            isCorrectWord = false;
            inWord = false;
        } else if(inWord && isCorrectWord && !(str[i] >= 97 && str[i] <= 122)) {
            isCorrectWord = false;
            counter--;
        }
        i++;
    }
    return counter;
}

unsigned int faStr3(const char *str) {
    bool inWord = false;
    int counter = 0;
    int i=0;
    int len = 0;
    while(str[i] != '\0') {
        if(str[i] != ' ') {
            if(!inWord) counter++;
            inWord = true;
            len++;
        } else if(str[i] == ' ' && inWord) {
            inWord = false;
        }
        i++;
    }
    return round(static_cast<float>(len)/counter);
}
