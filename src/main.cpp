// Copyright 2022 UNN-IASR
#include <iostream>
#include "fun.h"

int main() {
    const char* s1 = "hello world";
    const char* s2 = "one two three four";
    const char* s3 = "   spaced   words   here  ";
    const char* s4 = "singleword";
    const char* s5 = "";

    std::cout << "s1: " << faStr3(s1) << std::endl; // 5
    std::cout << "s2: " << faStr3(s2) << std::endl; // ~3-5 (среднее)
    std::cout << "s3: " << faStr3(s3) << std::endl; // проверка пробелов
    std::cout << "s4: " << faStr3(s4) << std::endl; // длина слова
    std::cout << "s5: " << faStr3(s5) << std::endl; // 0

    return 0;
}
