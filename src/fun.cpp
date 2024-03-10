// Copyright 2022 UNN-IASR
#include "fun.h"

unsigned int faStr1(const char *str) {
    int i = 0;
    int count_word = 0;
    int in_word = 0;
    int number = 0;
    while (str[i])
    {
        if (str[i] != ' ' && in_word == 0)
        {
            if (48 <= str[i] && str[i] <= 57)
            {
                number == 1;
            }
            in_word = 1;
        }

        if (str[i] != ' ' && in_word == 1)
        {
            if (48 <= str[i] && str[i] <= 57)
            {
                number = 1;
            }
        }

        if (str[i] == ' ' && in_word == 1) {
            if (number == 0)
            {
                count_word++;
            }
            in_word = 0;
            number = 0;
        }
        i++;
    }
    if (in_word == 1 && number == 0)
    {
        count_word++;
    }

    return count_word;
}

unsigned int faStr2(const char *str) {
    int i = 0;
    int count_word = 0;
    int in_word = 0;//мы вне слова
    int first_letter = 0;// первая буква - не заглавная латинская 
    int small_letter = 0;
    while (str[i])
    {
        if (str[i] != ' ' && in_word == 0)
        {
            if (65 <= str[i] && str[i] <= 90)
            {
                first_letter = 1;
            }
            in_word = 1;
        }
        if (str[i] != ' ' && in_word == 1)
        {
            if (97 <= str[i] && str[i] <= 122)
            {
                small_letter = 1;
            }
            else
            {
                small_letter = 0;
            }

        }
        if (str[i] == ' ' && in_word == 1)
        {
            if (first_letter == 1 && small_letter == 1)
            {
                count_word++;
            }
            int in_word = 0;
            int first_letter = 0;
            int small_letter = 0;
        }
        i++;
    }
    if (in_word == 1 && first_letter == 1 && small_letter == 1)
    {
        count_word++;
    }
    return count_word;
}

unsigned int faStr3(const char *str) {
    int i = 0;
    int in_word = 0;
    int count_letter = 0;
    int count_word = 0;
    while (str[i])
    {
        if (str[i] != ' ')
        {
            count_letter++;
            in_word = 1;
        }
        if (str[i] == ' ')
        {
            if (in_word == 1)
            {
                count_word++;
            }
            in_word = 0;
        }
        i++;
    }
    if (in_word == 1)
    {
        count_word++;
    }
    float ans = static_cast<float>(count_letter) / count_word;
    if ((ans - static_cast<int>(ans)) >= 0.5)
        return static_cast<int>(ans) + 1;
    return static_cast<int>(ans);
}
