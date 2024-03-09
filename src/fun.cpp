// Copyright 2022 UNN-IASR
#include "fun.h"
bool myFind(char* mas, char elem) {
     for (int i = 0; i < sizeof(mas); i++) {
        if (elem == mas[i])
            return true;
    }
    return false;
}
unsigned int faStr1(const char *str) {
    char num[10] = {'0', '1', '2', '3', '4', '5', '6', '7', '8', '9'};
    bool inWord = false;
    bool haveNum = false;
    int count = 0;
    int i = 0;
    while (str[i] != '\0') {
        if (str[i] != ' ' && inWord == false) {
            inWord = true;
            if(myFind(num, str[i]))
                haveNum = true;
            else
                count += 1;
        }
        else {
            if (myFind(num, str[i]) && haveNum==false) {
                haveNum = true;
                count--;
            }
            if (str[i] == ' ' && inWord == true) {
                inWord = false;
                haveNum = false;
             }
        }
        i++;
    }
    return count;
}

unsigned int faStr2(const char *str) {
        
    bool inWord = false;
    bool capitalLetter = false;
    int count = 0;
    int i = 0;
    bool haveNum = false;
    while (str[i] != '\0')
    {
        if (str[i] >= 65 && str[i] <= 90 && inWord == false) { //в ascii-code заглавные буквы
            inWord = true;
            capitalLetter = true;
            count += 1;
        }
        else {
            if ((str[i] < 97 || str[i] > 122) && str[i]!=' ' && haveNum == false && capitalLetter==true) {
                haveNum = true;
                count--;
            }
            if (str[i] == ' ' && inWord == true) {
                inWord = false;
                haveNum = false;
                capitalLetter = false;
            }
        }
        i++;
    }
    return count;
}

unsigned int faStr3(const char *str) {
    bool inWord = false;
    int count = 0;
    int i = 0;
    int sum = 0;
    int start = 0;
    while (str[i] != '\0') {
        if (str[i] != ' ' && inWord == false) {
            inWord = true;
            count += 1;
            start = i;
        }
        else {                
            if (str[i] == ' ' && inWord == true) {
                inWord = false;
                sum+=i-start;
            }
        }
        i++;
    }
    if (inWord == true) {
        sum += i - start;
    }
    return sum/count;
}
