// Copyright 2022 UNN-IASR
#include <iostream>
#include "fun.h"

int main() {
    using std::cout;
    setlocale(LC_ALL, "Russian");
    const char* str = "Chamomile is a good name for a cat";
    cout << "Кол-во слов без цифр: " << faStr1(str);
    cout << "Кол-во слов с заглавной буквы: " << faStr2(str);
    cout << "Средняя длина слова: " << faStr3(str);
}
