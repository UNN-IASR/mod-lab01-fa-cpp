// Copyright 2022 UNN-IASR
#include "fun.h"
#include <string>
#include <iostream>

int main() {
    const char* str;
    str = "qwe4  gftt e 555gr rrgr  grhh ";
    std::cout << faStr1(str) << std::endl;
    str = "Hello, world!";
    std::cout << faStr2(str) << std::endl;
    str = " six monkeys";
    std::cout << faStr3(str) << std::endl;
    return 0;
}
