// Copyright 2022 UNN-IASR
#include "fun.h"
#include<math.h>
#include<cctype>

unsigned int faStr1(const char *str) {
int Number = 0;
bool flag = false;
bool correct = true;
int index = 0;
while (str[index]) {
    if (str[index] == ' ' && flag) {
        flag = false;
        Number++;
    }
    if (str[index] == ' ')correct = true;
    if (str[index] != ' ' && correct) {
        flag = true;
    }
    if (flag && isdigit(str[index]))correct = false;
    if (!correct)flag = false;
    index++;
}
return Number;
}

unsigned int faStr2(const char *str) {
int Number = 0;
bool flag = false;
bool correct = false;
int index = 0;
while (str[index]) {
    if (str[index] == ' ') {
        if (flag && correct) {
            Number++;
        }
        flag = false;
        correct = false;
    }
    if (!(str[index] >= 'a' && str[index] <= 'z') && flag) {
        correct = false;
    }
    if (str[index] >= 'A' && str[index] <= 'Z' && !flag) {
        correct = true;
        flag = true;
    }
    if (str[index] >= 'a' && str[index] <= 'z' && !flag) {
        correct = false;
        flag = true;
    }
    index++;
}
if (flag && correct) {
    Number++;
}
return Number;
}

unsigned int faStr3(const char *str) {
double Number = 0;
bool flag = false;
double counter = 0;
int index = 0;
while (str[index]) {
    if (str[index] == ' ' && flag) {
        flag = false;
        Number++;
    }
    if (str[index] != ' ') {
        flag = true;
        counter++;
    }
    index++;
}
if (flag) {
    Number++;
}
return (int)round(counter / Number);
}
