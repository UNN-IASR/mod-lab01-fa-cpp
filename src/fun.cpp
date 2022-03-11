// Copyright 2022 UNN-IASR
#include "fun.h"

unsigned int faStr1(const char *str) {
int i = 0;
int count = 0;
bool numb = false;
bool inWord = false;
while (str[i]) {
        if (str[i] != ' ') {
            inWord = true;
            if (inWord == true && numb == false && isdigit(str[i]))
               numb = true;
        } else if (str[i] == ' ' && inWord == true && numb == false) {
        count++;
        inWord = false;
        numb = false;
        } else if (str[i] == ' ' && inWord == true && numb == true) {
        inWord = false;
        numb = false;
        }
    i++;
}
    return count;
}

unsigned int faStr2(const char *str) {
    int i = 0;
    int count = 0;
    bool inW = false; // inWord
    bool Zg_ch = false; // Zaglav_char
    bool enlow = false; // eng_lowercase_char
    while (str[i]) {
  if (str[i] != ' ') {
    inW = true;
  if (inW == true && Zg_ch == false && enlow == false)
    if (str[i] >= 'A' && str[i] <= 'Z')
     Zg_ch = true;
  if (inW == true && Zg_ch == true && str[i] >= 'a' && str[i] <= 'z')
     enlow = true;
  if (inW == true && Zg_ch == true && isalpha(str[i]) == 0)
     enlow = false;
  } else if (str[i] == ' ' && inW == true && Zg_ch == true && enlow == true) {
        count++;
        inW = false;
        Zg_ch = false;
        enlow = false;
        } else if (str[i] == ' ' && inW == true) {
        inW = false;
        Zg_ch = false;
        enlow = false;
}
i++;
}
return count;
}

unsigned int faStr3(const char *str) {
    int i = 0;
    int str_chars = 0;
    int av_length = 0;
    int WordAm = 0; // words Amount
    bool inWord = false;
    while (str[i]) {
            if (inWord == false && str[i] != ' ') {
              WordAm++;
              inWord = true;
            } else if (inWord == true && str[i] == ' ') {
              inWord = false;
            }
            if (str[i] != ' ')
              str_chars++;
  i++;
    }
    av_length = round(str_chars/WordAm);
    return av_length;
}
