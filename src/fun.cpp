// Copyright 2022 UNN-IASR
#include "fun.h"
#include <cctype>

unsigned int faStr1(const char *str) {
  int i = 0;
  int wordsWithoutDigits = 0;
  bool inValidWord = false;
  bool inWord = false;
  while (str[i]) {
    char current = str[i];
    if (current == ' ') {
      if (inValidWord) {
        wordsWithoutDigits++;
      }
      inWord = false;
      inValidWord = false;
    } else {
      if (!inWord) {
        inValidWord = true;
      }
      if (isdigit(current)) {
        inValidWord = false;
      }
      inWord = true;
    }
    i++;
  }
  return wordsWithoutDigits;
}

unsigned int faStr2(const char *str) {
  int i = 0;
  int result = 0;
  bool inWord = false;
  bool inValidWord = false;
  while (str[i]) {
    char current = str[i];
    if (current == ' ') {
      if (inValidWord) {
        result++;
      }
      inWord = false;
      inValidWord = false;
    } else if (!inWord) {
      inWord = true;
      if (isupper(current)) {
        inValidWord = true;
      }
    } else if (inWord && (isupper(current) || !isalpha(current))) {
      inValidWord = false;
    }
    i++;
  }
  if (inValidWord) {
    result++;
  }
  return result;
}

unsigned int faStr3(const char *str) {
  int i = 0;
  bool inWord = false;
  int wordsCount = 0;
  int totalChars = 0;
  while (str[i]) {
    char current = str[i];
    if (current == ' ') {
      inWord = false;
    } else {
      if (!inWord) {
        inWord = true;
        wordsCount++;
      }
      totalChars++;
    }
    i++;
  }
  return totalChars / wordsCount;
}

