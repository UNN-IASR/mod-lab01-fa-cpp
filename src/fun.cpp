// Copyright 2022 UNN-IASR
#include "fun.h"
#include <cctype>
#include <math.h>

unsigned int faStr1(const char  *   str) {
  int i = 0;
  bool invWord = false; // Допустимое ли слово или нет
  bool word = false; // Находимся ли мы в слове в данный момент
  int WnD = 0; // Количество слов, в которых не содержатся цифры

  while (str[i]) {
    char value = str[i];

    if (value == ' ' && word == true) {
      invWord = false;
      word = false;
    } else if (value != ' ' && word == false) {
      word = true;
      WnD++;
    } else if (isdigit(value) && word == true && !invWord) {
      invWord = true;
      WnD--;
    }

    i++;
  }

  return WnD;
}

unsigned int faStr2(const char  *   str) {
  int i = 0;
  bool invalidWord = false; // Допустимое ли слово или нет
  bool word = false; // Находимся ли мы в слове в данный момент
  int prettyWord = 0; // Кол-во слов с заглавными

  while (str[i]) {
    char value = str[i];

    if (value != ' ' && word == false) { // Если начало слова
      word = true;
      if (isupper(value) && value != ' ') {
        prettyWord++;
      } else {
        invalidWord = true;
      }
    } else if (isalpha(value)) {
      invalidWord = true;
      prettyWord--;
    } else if ((value == ' ' && word == true)) {
      invalidWord = false;
      word = false;
    } // Если конец слова

    i++;
  } 
}

unsigned int faStr3(const char  *   str) {
  bool word = false;
  int count = 0;
  int sum = 0;
  int lengthNow = 0; // исправлено на lengthNow
  int i = 0;

  while (str[i]) {
    if (str[i] != ' ' && word == false) {
      word = true;
      count++;
      lengthNow++; // исправлено на lengthNow
    } else if (str[i] != ' ' && word == true) {
      lengthNow++; // исправлено на lengthNow
    } else if (str[i] == ' ' && word == true) {
      word = false;
      sum += lengthNow; // исправлено на lengthNow
      lengthNow = 0;
    }

    i++;
  }

  sum += lengthNow; // исправлено на lengthNow

  if ((sum % count) >= 0.5) {
    return (sum / count) + 1;
  } else {
    return sum / count;
  }
}


