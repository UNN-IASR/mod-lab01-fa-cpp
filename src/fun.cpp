// Copyright 2022 UNN-IASR
#include <cctype>
#include <math.h>
#include "fun.h"

//определяет слова, не содержащие цифр и подсчитывает количество таких слов.
unsigned int faStr1(const char* str)
{
    bool inWord = false;
    bool isNumber = false; //определяет наличие цифр в слове
    int count = 0;
    int i = 0;
    while (str[i])
    {
        //чтение слова на начале слова
        if (str[i] != ' ' && inWord == false)
        {
            inWord = true;
            count++;
        }
        //нашли цифру в слове
        if (isdigit(str[i]) && inWord == true && isNumber == false)
        {
            isNumber = true;
            count--;
        }
        //окончание слова
        else if (str[i] == ' ' && inWord == true)
        {
            inWord = false;
            isNumber = false;
        }
        i++;
    }
    return count;
}

//количество слов, начинающиеся на заглавную латинскую букву, а среди других символов этих слов только латинские строчные буквы.
unsigned int faStr2(const char* str)
{
    bool inWord = false;
    bool badWord = false; //бракует слово
    int count = 0;
    int i = 0;
    while (str[i])
    {
        //чтение слова на начале слова
        if (str[i] != ' ' && inWord == false)
        {
            inWord = true;
            {
                if (isupper(str[i]))
                    count++;
                else
                    badWord = true;
            }
        }
        //нашли не строчную букву в слове
        else if ((str[i] < 'a' || str[i] > 'z') && str[i] != ' ' && inWord == true && badWord == false)
        {
            badWord = true;
            count--;
        }
        //окончание слова
        else if (str[i] == ' ' && inWord == true)
        {
            badWord = false;
            inWord = false;
        }
        i++;
    }
    return count;
}

// находит среднюю длину слова в строке, округляя ее до целого значения по правилам округления.
unsigned int faStr3(const char* str)
{
    bool inWord = false;
    int count = 0;
    int sum = 0; //сумма длин всех слов
    int lenghtNow = 0; //длина текущего слова
    int i = 0;
    while (str[i])
    {
        if (str[i] != ' ' && inWord == false)
        {
            inWord = true;
            count++;
            lenghtNow++;
        }
        else if (str[i] != ' ' && inWord == true) lenghtNow++;
        else if (str[i] == ' ' && inWord == true)
        {
            inWord = false;
            sum += lenghtNow;
            lenghtNow = 0;
        }
        i++;
    }
    sum += lenghtNow; //т.к. \0 цикл не учитывает
    if ((sum%count) >= 0.5) return (sum / count) + 1;
    else return sum / count;
}
