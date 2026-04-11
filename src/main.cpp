// Copyright 2022 UNN-IASR
#include <iostream>
#include "fun.h"

int main() {
    const char *str = "  Hello world 123 Test abcZ A bc  ";

    std::cout << "faStr1 = " << faStr1(str) << std::endl;
    std::cout << "faStr2 = " << faStr2(str) << std::endl;
    std::cout << "faStr3 = " << faStr3(str) << std::endl;

    return 0;
}
