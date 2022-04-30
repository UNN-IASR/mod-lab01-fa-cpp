// Copyright 2022 UNN-IASR
#include "fun.h"

unsigned int faStr1(const char* str) {
        int i = 0, schet = 0, Slovo = 0, Numer = 0;
        while (str[i] != '\0') {
                if (Slovo == 0 && str[i] != ' ') {
                        if (str[i] > 57 || str[i] < 48) Numer = 1;
                        Slovo = 1;
                } else if (Slovo == 1 && str[i] != ' ' && Numer == 1) {
                        if (str[i] >= 48 && str[i] <= 57) {
                                Numer = 0;
                        }
                } else if (Slovo == 1 && str[i] == ' ') {
                        if (Numer == 1) {
                        schet++;
                        }
                        Numer = 0;
                        Slovo = 0;
                }
                i++;
        }
        if (Slovo == 1 && Numer == 1) {
                schet++;
        }
        return schet;
}
unsigned int faStr2(const char* str) {
        int i = 0, schet = 0, Slovo = 0, Number = 0;
        while (str[i] != '\0') {
                if (Slovo == 0 && str[i] >= 65 && str[i] <= 90) {
                        Slovo = 1;
                        Number = 1;
                } else if (Slovo == 1 && str[i] != ' ' && Number == 1) {
                        if (str[i] >= 65 && str[i] <= 90) {
                                Number = 0;
                        }
                        if (str[i] > 122 || str[i] < 65) {
                                Number = 0;
                        }
                } else if (Slovo == 1 && str[i] == ' ') {
                        if (Number == 1) {
                                schet++;
                        }
                        Number = 0;
                        Slovo = 0;
                }
                i++;
        }
        if (Slovo == 1 && Number == 1) {
                schet++;
        }
        return schet;
}
unsigned int faStr3(const char* str) {
        int i = 0, schet = 0, Slovo = 0, Leng = 0, Answer;
        float Sum = 0;
        while (str[i] != '\0') {
                if (Slovo == 0 && str[i] != ' ') {
                        schet++;
                        Slovo = 1;
                        Leng++;
                } else if (Slovo == 1 && str[i] != ' ') {
                        Leng++;
                        } else if (Slovo == 1 && str[i] == ' ') {
                        Sum = Sum + Leng;
                        Slovo = 0;
                        Leng = 0;
                }
                i++;
        }
        if (Slovo == 1) Sum = Sum + Leng;
        Sum = Sum / static_cast<float>(schet);
        Answer = Sum;
        if (Sum - static_cast<float>(Answer) >= 0.5) Answer++;
        return Answer;
}
