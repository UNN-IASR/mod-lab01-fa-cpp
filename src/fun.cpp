// Copyright 2022 UNN-IASR
#include "fun.h"
#include <math.h>

unsigned int faStr1(const char* str){
    bool inWord = false;//изначально вне слова
    bool outNums = false;
    int count = 0;
    int i = 0;
    while (str[i] != '\0'){
        if (str[i] != ' ' && inWord == false)
            inWord = true;
        else 
            if (!((str[i] >= 'A' && str[i] <= 'Z') 
                || (str[i] >= 'a' && str[i] <= 'z'))
                && inWord == true && str[i] != ' ')
                outNums = true;
        else if (str[i] == ' ' && inWord == true){
            if (outNums == false)
                count++;
            else
                outNums = false;
            inWord = false;
        }
        i++;
    }
    return count;
}
unsigned int faStr2(const char* str){
    bool inWord = false;//изначально вне слова
    bool outNums = false;
    int count = 0;
    int i = 0;
    while (str[i] != '\0'){
        if (str[i] != ' ' && inWord == false 
            && (str[i] >= 'A' && str[i] <= 'Z'))
            inWord = true;
        else if (!(str[i] >= 'a' && str[i] <= 'z') 
            && inWord == true && str[i] != ' ')
            outNums = true;
        else if (str[i] == ' ' && inWord == true){
            if (outNums == false)
                count++;
            else
                outNums = false;
            inWord = false;
        }
        i++;
    }
    return count;
}
unsigned int faStr3(const char* str){
    bool inWord = false;
    int count = 0;
    int space = 0;
    int i = 0;
    int res = 0;
    while (str[i] != '\0'){
        if (str[i] != ' ' && inWord == false)
            inWord = true;
        else if (str[i] == ' ' && inWord == true){
            inWord = false;
            count++;
        }
        if (str[i] == ' ')
            space++;
        i++;
    }
    if (i != 0 && str[i - 1] != ' ')
        count++;
    if (count != 0)
        res = round((i - space) / count);
    return res;
}
