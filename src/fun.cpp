// Copyright 2022 UNN-IASR
#include "fun.h"

unsigned int faStr1(const char *str) {
    bool inWord = false;
    bool cifra = false;
    int count = 0;
    int i = 0;
    while (str[i])
    {
        if (str[i] != ' ')
        {
            inWord = true;
        }
        if (str[i] == '0' || str[i] == '1' || str[i] == '2' || str[i] == '3' || str[i] == '4' || str[i] == '5' || str[i] == '6' || str[i] == '7' || str[i] == '8' || str[i] == '9')
        {
            cifra = true;
        }
        if (str[i] == ' ' && inWord == true)
        {
            if (cifra ==  false)
            {
                count++;
            }
            inWord = false;
            cifra = false;
        }
        i++;
        
    }
    
    return count;
}

unsigned int faStr2(const char *str) {
    bool first = true;//первая буква
    bool correct = false;
    bool second = false;
    int count = 0;
    int i = 0;
    while (str[i])
    {
        if (str[i] >= 'A' && str[i] <= 'Z' && first == true) //первая буква заглавная
        {
            correct = true;
            first = false;
        }
        else if (str[i] >= 'a' && str[i] <= 'z')
        {
            first = false;
            second = true;
        }
        else if (str[i] != ' ')
        {
            correct = false;
        }
        else
        {
            if (correct == true && second == true)
            {
                count++;
                
            }
            first = true;

            correct = false;
            second = false;
        }
        i++;
    }
    return count;
}

unsigned int faStr3(const char *str) {
    bool inWord = false;
    int count = 0;
    int len = 0;
    int i = 0;
    while (str[i])
    {
        if (str[i] != ' ' && inWord == false)
        {
            inWord = true;
            count++;
        }
        if (str[i] != ' ')
        {
            len++;
        }
        if (str[i] == ' ' && inWord == true)
        {
            inWord = false;
        }
        i++;
    }
    float res = len / (float)count;
    
    
    if (count == 0)
    {
        return 0;
    }
    
    else 
    {
        if (res -  (int)res >= 0.5)
        {
            return (int)res+1;
        }
        else
        {
            return (res);
        }
    }
    
}
