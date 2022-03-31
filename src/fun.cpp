// Copyright 2022 UNN-IASR
#include "fun.h"
#include <cctype>

unsigned int faStr1(const char *str) {
    int i = 0;
    int figure = 0;
    int inWord = 0;
    int count = 0;
    while (str[i]){
        if ((str[i] != ' ') && (str[i - 1] == ' ')) {
            count++;
            inWord = 1;
        }
        if (isdigit(str[i]))
            if (inWord == 1) {
                count--;
                inWord = 0;
            }
        i++;
    }
    return count;
}
unsigned int faStr2(const char *str) {
   int i = 0;
   int inWord = 0;
   int count = 0;
    while (str[i]){
        if ((str[i] != ' ')  && (str[i - 1] == ' ') && (isupper(str[i]))) {
          count++;
          inWord = 1;
        }
        i++;
        if (str[i] == ' ')
            inWord = 0;
        if (((str[i] < 97) || (str[i]>122)))
            if (inWord == 1) {
                count--;
                    inWord = 0;
            }
    }
    return count; 
}
unsigned int faStr3(const char *str) {
   int i = 0;
    int length = 0;
    int inWord = 0;
    int count = 0;
    while (str[i])
    {
        if ((str[i] != ' ') && (str[i - 1] == ' ') ) {
            count++;
            inWord = 1;
        }       
        if (inWord == 1)
            length++;
            
        if (str[i] == ' ')
            inWord = 0;
        i++;
    }
    return length / count;
}
