// Copyright 2022 UNN-IASR
#include "fun.h"
#include <math.h>
#include <ctype.h>
unsigned int faStr1(const char* str)
{
    int count = 0, i = 0;
    bool word = false, digit = false;
    char ch = ' ';
    while (str[i])
    {
        ch = str[i];
        if (str[i] != ' ')
        {
            if (isdigit(str[i]))
                digit = true;
            word = true;
        }
        if(str[i]== ' ')
        {
            if (word)
            {
                if (!digit)
                    count++;
                word = false;
                digit = false;
            }
        }
        i++;
    }
    if (word && !digit) count++;
    return count;
}

unsigned int faStr2(const char* str)
{
    int count = 0, i = 0;
    bool isGood = false;
    while (str[i])
    {
        char ch = str[i];
        if (!isGood && str[i] != ' ' && isupper(str[i]))
        {
            isGood = true;
        }
        else if (isGood && str[i] == ' ')
        {
            count++;
            isGood = false;
        }
        else if (!islower(str[i])) {
            isGood = false;
        }i++;
    }
    return count;
}
unsigned int faStr3(const char* str)
{
    int length = 0, count = 0, i = 0;
    bool word = false;
    while (str[i])
    {
        if (str[i] != ' ')
        {
            if (!word)
                count++;
            length++;
            word = true;
        }
        else if (str[i] == ' ' && word)
            word = false;
        i++;
    }
    return length / count;
}
