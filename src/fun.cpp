// Copyright 2022 UNN-IASR
#include "fun.h"

unsigned int faStr1(const char *str) {
    bool flag1 = false, flag2 = false; 
    int count = 0, i = 0;
    while (str[i]) { 
        if (str[i] != ' ' && flag1 == false) {
            flag1 = true;
            count++;
        }
        else if (isdigit(str[i]) && flag1 == true && flag2 == false) {
            flag2 = true;
            count--;
        }
        else if (str[i] == ' ' && flag1 == true) {
            flag1 = false;
            flag2 = false;
        }
        i++;
    }
    return count;
}

unsigned int faStr2(const char *str) {
    bool flag = false;
    int i = 0, num = 0, count = 0;
    while (str[i])
    {
        if (!flag && str[i] != ' ' && str[i] >= 65 && str[i] <= 90) {
            flag = true;
            num = 1;
        }
        else if (flag && str[i] == ' ') {
            flag = false;
            count += num;
        }
        else if (str[i] < 97 || str[i] > 122) {
            num = 0;
        }
        i++;
    }
    return count;
}

unsigned int faStr3(const char *str) {
    bool flag = false;
    int i = 0, sum = 0;
    float count = 0;
    while (str[i])
    {
        if (!flag && str[i] != ' ') {
            flag = true;
            count++;
        }
        else if (flag && str[i] == ' ') {
            flag = false;

        }
        if (flag && str[i] != ' ') {
            sum++;
        }
        i++;
    }
    return static_cast<int>(round(static_cast<double>(sum) / count));
}
