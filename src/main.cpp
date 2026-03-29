// Copyright 2022 UNN-IASR
#include <iostream>
#include "fun.h"
int main()
{
    const char* s1 = "qweqweq 123 hello test45 world";
    const char* s2 = "Hello World Abc aBc X Cat";
    const char* s3 = "one two three for";

    std::cout << faStr1(s1) << std::endl;
    std::cout << faStr2(s2) << std::endl;
    std::cout << faStr3(s3) << std::endl;

    return 0;
}