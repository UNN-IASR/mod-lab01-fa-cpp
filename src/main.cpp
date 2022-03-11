// Copyright 2022 UNN-IASR
#include <iostream>
#include "fun.h"

int main() {
    const char* str1 = "      qe 1e 2 eqweqw 23132qweqweqwe eew2";
    const char* str2 = "      Qe 1e 2 Eqweqw 23132qweqweqwe Eew2";
    const char* str3 = " ewtyg qwertf     ";
    std::cout << "faStr1 - " << faStr1(str1);
    std::cout << "\n";
    std::cout << "faStr2 - " << faStr2(str2);
    std::cout << "\n";
    std::cout << "faStr3 - " << faStr3(str3);
    return 0;
}
