// Copyright 2022 UNN-IASR
#include <math.h>
#include <iostream>
#include <cctype>
#include "fun.h"

unsigned int faStr1(const char* slovo) {
int col_vo = 0;
int iw = 0;
int It = 0;
while (*(slovo + It)) {
if (*(slovo + It) != ' '
&& !isdigit(*(slovo + It)) && !fW(iw)) {
col_vo++;
iw = 1;}
else if (*(slovo + It) == ' '
&& fW(iw)) iw = 0;
else if (isdigit(*(slovo + It))
&& iw == 0) iw = 2;
else
if (isdigit(*(slovo + It)) && iw == 1) {
iw = 2;
col_vo--;}
It++;
}
return col_vo;
}
unsigned int faStr2(const char* slovo) {
int col_vo = 0;
int iw = 0;
int It = 0;
while (*(slovo + It)) {
if (isupper(*(slovo + It)) && iw == 0) {
col_vo++;
iw = 1;}
else if (!ilm(*(slovo + It))
&& !fW(iw)) iw = 2;
else if (*(slovo + It) == ' '
&& fW(iw)) iw = 0;
else
if (!ilm(*(slovo + It)) && iw == 1) {
iw = 2;
col_vo--;}
It++;
}
return col_vo;
}
unsigned int faStr3(const char* slovo) {
int col_vo = 0;
int sum = 0;
bool iw = false;
int It = 0;
while (*(slovo + It)) {
if (*(slovo + It) != ' ' && iw == false) {
col_vo++;
iw = true;
} else if (*(slovo + It) == ' ' && iw == true) {
iw = false;}
if (iw == true)
sum++;
It++;
}
col_vo = round(static_cast<double>(sum) / static_cast<double>(col_vo));
return col_vo;
}
bool fW(int iw) {
if (iw != 0)
return true;
else
return false;
}
bool ilm(char a) {
if (static_cast<int>(a) >= 97 && static_cast<int>(a) <= 122)
return true;
else
return false;
}
