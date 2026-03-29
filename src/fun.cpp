// Copyright 2022 UNN-IASR
#include "../include/fun.h"
#include "cstring"
#include "cmath"
unsigned int faStr1(const char *str)
{
    unsigned int count = 0;
    bool in_word = false;
    bool invalid_word = false;
    for (int i = 0; i < strlen(str); i++)
    {
        if (!in_word && str[i] != ' ')
        {
            in_word = true;
            count++;
        }
        if (in_word)
        {
            if (str[i] >= '0' && str[i] <= '9' && !invalid_word)
            {
                count--;
                invalid_word = true;
            }
            if (str[i] == ' ')
            {
                in_word = false;
                invalid_word = false;
            }
        }
    }
    return count;
}

unsigned int faStr2(const char *str)
{
    unsigned int count = 0;
    bool in_word = false;
    bool invalid_word = false;
    for (int i = 0; i < strlen(str); i++)
    {
        if (!in_word && str[i] >= 'A' && str[i] <= 'Z')
        {
            in_word = true;
            count++;
        }
        else if (in_word)
        {
            if (str[i] == ' ')
            {
                in_word = false;
                invalid_word = false;
            }
            else if ((str[i] < 'a' || str[i] > 'z') && !invalid_word)
            {
                count--;
                invalid_word = true;
            }
        }
    }
    return count;
}

unsigned int faStr3(const char *str)
{

    unsigned int count = 0;
    unsigned int avg = 0;
    double sum = 0;
    bool in_word = false;
    for (int i = 0; i < strlen(str); i++)
    {
        if (!in_word && str[i] != ' ')
        {
            in_word = true;
            count++;
        }
        if (in_word)
        {
            if (str[i] == ' ')
                in_word = false;
            else
                sum++;
        }
    }
    avg = round(sum / count);
    return avg;
}
