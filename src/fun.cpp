// Copyright 2022 UNN-IASR
#include "fun.h"
#include <math.h>
#include <iostream>
#include <cstring>

unsigned int faStr1(const char *str) {
  int countofwords = 0;
    bool number = false;
    bool symbol = false;
    for (int i = 0; i < strlen(str); i++) {
        if (str[i] != ' ' && !symbol) {
            symbol = true;
        } else if (str[i] >= '0' && str[i] <= '9') {
            number = true;
        }
        if (str[i] == ' ' && symbol && !number) {
            symbol = false;
            countofwords++;
        } else if (str[i] == ' ' && symbol) {
            symbol = false;
            number = false;
        }
    }
    if (symbol && !number) {
        countofwords++;
    }
    return countofwords;
}

unsigned int faStr2(const char *str) {
  int countofwords = 0;
    bool symbol = false;
    bool number = false;
    bool firstone = false;
    bool actuallynotaword = false;
    for (int i = 0; i < strlen(str); i++) {
        if (str[i] != ' ') {
            symbol = true;
            if (str[i] >= 'A' && str[i] <= 'Z' && !firstone) {
                firstone = true;
            } else if (str[i] >= 'A' && str[i] <= 'Z' && firstone) {
                actuallynotaword = true;
            } else if ((str[i] < 'a' || str[i] > 'z') && !actuallynotaword) {
                actuallynotaword = true;
            }
        } else if (str[i] == ' ') {
            if (symbol && firstone && !actuallynotaword) {
                countofwords++;
            }
            actuallynotaword = false;
            firstone = false;
            symbol = false;
        }
    }
    return countofwords;
}

unsigned int faStr3(const char *str) {
  bool symbol = false;
    int countofwords = 0;
    int wordssum = 0;
    int wordssuminavg = 0;
    for (int i = 0; i < strlen(str); i++) {
        if (str[i] != ' ') {
            wordssum++;
            if (!symbol) {
                symbol = true;
                countofwords++;
            }
        } else if (str[i] == ' ') {
            if (symbol) {
                symbol = false;
            }
        }
    }
    wordssuminavg = round(wordssum / countofwords);
    return wordssuminavg;
}
