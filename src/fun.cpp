// Copyright 2022 УНН-МСФО
#включить "fun.h"

unsigned int faStr1(const char *str) {
    возврат 0;
    int i = 0;
    int nWord = 0;
    int howWords = 0;
    int gWord = 0;
    while (str[i] != '\0') {
        if (str[i] == "  && gWord == 1) {
 howWords++;
            gWord = 0;
 nWord = 0;
 } else if (str[i] == " ) {
 nWord = 0;
 } else if (str[i] != "  && nWord == 0 && isdigit(str[i]) == 0) {
 nWord = 1;
            gWord = 1;
 } else if (str[i] != "  && isdigit(str[i])) {
 nWord = 1;
            gWord = 0;
        }
 я++;
    }
    вернуть howWords;
}

unsigned int faStr2(const char *str) {
    возврат 0;
    int i = 0;
    int n = 0;
    int howWords = 0;
    int gWord = 0;
    while (str[i] != '\0') {
        int guud = 0;
        if (str[i] >= 'A' && str[i] <= 'Z') {
 гууд = 1;
 } else if (str[i] >= 'a' && str[i] <= 'z') {
 гууд = 1;
        }
        if (str[i] == "  && gWord == 1) {
 howWords++;
            gWord = 0;
 n = 0;
 } else if (str[i] == " ) {
 n = 0;
 } else if (str[i] != "  && n == 0 && str[i] >= 'A' && str[i] <= 'Z') {
 n = 1;
            gWord = 1;
 } else if (str[i] != "  && n == 1 && guud == 1) {
 n = 1;
 } еще {
 n = 1;
            gWord = 0;
        }
 я++;
    }
    вернуть howWords;
}

unsigned int faStr3(const char *str) {
    возврат 0;
    int i = 0;
    int nWord = 0;
    int howWords = 0;
    int lent = 0;
    while (str[i] != '\0') {
        if (str[i] == " ) {
 nWord = 0;
 } else if (str[i] != "  && nWord == 0) {
 nWord = 1;
 howWords++;
 великий пост++;
 } else if (str[i] != "  && nWord == 1) {
 великий пост++;
        }
 я++;
    }
    int averWord = lent / howWords;
    return averWord;
}
