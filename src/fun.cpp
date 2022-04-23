// Copyright 2022 UNN-IASR
#include <math.h>
#include <iostream>
#include <cctype>
#include "fun.h"

unsigned int faStr1(const char* str) {
int iterator = 0;
int count = 0;
int inWord = 0;
while (*(str + iterator)) {
if (*(str + iterator) != ' '
&& !finWord(inWord) && !isdigit(*(str + iterator))) {
count++;
inWord = 1;}
else if (finWord(inWord)
&& *(str + iterator) == ' ') inWord = 0;
else if (isdigit(*(str + iterator))
&& inWord == 0) inWord = 2;
else
if (inWord == 1 && isdigit(*(str + iterator))) {
inWord = 2;
count--;}
iterator++;
}
return count;
}
unsigned int faStr2(const char* str) {
int iterator = 0;
int count = 0;
int inWord = 0;
while (*(str + iterator)) {
if (inWord == 0 && isupper(*(str + iterator))) {
count++;
inWord = 1;}
else if (!islowermy(*(str + iterator))
&& !finWord(inWord)) inWord = 2;
else if (*(str + iterator) == ' '
&& finWord(inWord)) inWord = 0;
else
if (!islowermy(*(str + iterator)) && inWord == 1) {
inWord = 2;
count--;}
iterator++;
}
return count;
}
unsigned int faStr3(const char* str) {
int count = 0;
int sum = 0;
bool inWord = false;
int iterator = 0;
while (*(str + iterator)) {
if (*(str + iterator) != ' ' && inWord == false) {
count++;
inWord = true;
} else if (inWord == true && *(str + iterator) == ' ') {
inWord = false;}
if (inWord == true)
sum++;
iterator++;
}
count = round(static_cast<double>(sum) / static_cast<double>(count));
return count;
}
bool finWord(int inWord) {
if (inWord != 0)
return true;
else
return false;
}
bool islowermy(char a) {
if (static_cast<int>(a) >= 97 && static_cast<int>(a) <= 122)
return true;
else
return false;
}
