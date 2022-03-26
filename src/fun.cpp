// Copyright 2022 UNN-IASR
#include <math.h>
#include <iostream>
#include <cctype>
#include "fun.h"

unsigned int faStr1(const char* str) {
int inw = 0;
int i = 0;
int count = 0;
while (*(str + i)) {
if (!inword(inw) && !isdigit(*(str + i))
&& *(str + i) != ' ') {
count = count + 1;
inw = 1;}
else if (inword(inw)
&& *(str + i) == ' ') inw = 0;
else if (inw == 0
&& isdigit(*(str + i))) inw = 2;
else
if (inw == 1 && isdigit(*(str + i))) {
inw = 2;
count = count - 1;}
i = i + 1;
}
return count;
}
unsigned int faStr2(const char* str) {
int count = 0;
int inw = 0;
int i = 0;
while (*(str + i)) {
if (inw == 0 && isupper(*(str + i))) {
count++;
inw = 1;}
else if (!inword(inw)
&& !mylower(*(str + i))) inw = 2;
else if (inword(inw)
&& *(str + i) == ' ') inw = 0;
else
if (inw == 1 && !mylower(*(str + i))) {
inw = 2;
count = count - 1;}
i = i + 1;
}
return count;
}
unsigned int faStr3(const char* str) {
int count = 0;
int k = 0;
bool inw = false;
int i = 0;
while (*(str + i)) {
if (inw == false && *(str + i) != ' ') {
count = count + 1;
inw = true;
} else if (inw == true && *(str + i) == ' ') {
inw = false;}
if (inw == true)
k = k + 1;
i = i + 1;
}
count = round(static_cast<double>(k) / static_cast<double>(count));
return count;
}
int inword(int inw) {
if (inw == 0)
return 0;
else
return 1;
}
int mylower(char str) {
if (static_cast<int>(str) < 96 || static_cast<int>(str) > 123)
return 0;
else
return 1;
}
