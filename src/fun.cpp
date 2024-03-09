// Copyright 2022 UNN-IASR
#include "fun.h"
#include <ctype.h>
#include <cmath>
unsigned int faStr1(const char *str) {
    bool flag = false;
    int i = 0;
    int count = 0;
    int obshag = 0;
    while (str[i])
    {
        if (!flag && str[i] != ' ' ){
            flag    = true;
            count   = 1;
        } else if (flag && str[i] == ' '){
            flag    = false;
            obshag += count;
        }
        if (flag && isdigit(str[i])){
            count = 0;
        }
        i++;
    }
    return obshag;
}

unsigned int faStr2(const char *str) {
    bool flag = false;
    int i = 0;
    int count = 0;
    int obshag = 0;
    while (str[i])
    {
        if (!flag && str[i] != ' ' && str[i] >= 65 && str[i] <= 90){
            flag    = true;
            count   = 1;
        } else if (flag && str[i] == ' '){
            flag = false;
            obshag += count;
        } else if (str[i] < 97 || str[i] > 122){
            count = 0;
        }
        i++;
    }
    return obshag;
}

unsigned int faStr3(const char *str) {
     bool flag = false;
    int i = 0;
    float count = 0;
    int sum = 0;
    double res = 0;
    while (str[i])
    {
        if (!flag && str[i] != ' '){
            flag = true;
            count++;
        } else if (flag && str[i] == ' '){
            flag = false;

        }
        if (flag && str[i] != ' '){
            sum++;
        }
        i++;
    }
    double intpart, fractpart; 
    res = sum / count;
    fractpart = modf(res, &intpart);
    if (fractpart >= 0.5){
        return (int)res + 1;
    } else{
        return (int)res;
    }
}
