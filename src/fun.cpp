#include <cctype>
#include <math.h>

unsigned int faStr1(const char *  str) {
  int i = 0;
  bool invWord = false; // булевая переменная, определяющая, допустимое ли слово или нет
  bool word = false; // булевая переменная, определяющая, находимся ли мы в слове в данный момент
  int WnD = 0; // Количество слов, в которых не содержатся цифры

  while (str[i]) {
    char value = str[i];

    if (value == ' ') {
      invWord = false;
      word = false;
    } else {
      word = true;
      if (isdigit(value) && !invWord) {
        invWord = true;
        WnD++;
      }
    }

    i++;
  }

  return WnD;
}

unsigned int faStr2(const char *  str) {
  int i = 0;
  bool invalidWord = false; // булевая переменная, определяющая, допустимое ли слово или нет
  bool word = false; // булевая переменная, определяющая, находимся ли мы в слове в данный момент
  int prettyWord = 0; // Количество слов, в которых содержится заглавная латинская буква

  while (str[i]) {
    char value = str[i];

    if (value == ' ') { // Если строка начинается с пробела
      invalidWord = false;
      word = false;
    } else if (value != ' ' && word == false) { // Если начало слова
      word = true;
      if (isupper(value)) {
        prettyWord++;
      } else if (isalpha(value)) {
        invalidWord = true;
        prettyWord--;
      }
    } else if ((value == ' ' && word == true)) {
      invalidWord = false;
      word = false;
    } // Если конец слова

    i++;
  }

  return prettyWord;
}

unsigned int faStr3(const char *  str) {
  bool word = false;
  int count = 0;
  int sum = 0;
  int lenghtNow = 0;
  int i = 0;

  while (str[i]) {
    if (str[i] != ' ' && word == false) {
      word = true;
      count++;
      lenghtNow++;
    } else if (str[i] != ' ' && word == true) {
      lenghtNow++;
    } else if (str[i] == ' ' && word == true) {
      word = false;
      sum += lenghtNow;
      lenghtNow = 0;
    }

    i++;
  }

  sum += lenghtNow;

  if ((sum % count) >= 0.5) {
    return (sum / count) + 1;
  } else {
    return sum / count;
  }
}
