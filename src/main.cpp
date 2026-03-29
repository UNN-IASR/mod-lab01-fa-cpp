// Copyright 2022 UNN-IASR
#include "fun.h"

#include <iostream>

int main()
{
    const char *s1 = "abc test12 hello  world7 code";
    const char *s2 = "Apple Orange banana Cat Dog X Yz John Smith A1 Test";
    const char *s3 = "   one   three seven   ";

    std::cout << "Строка 1: \"" << s1 << "\"" << std::endl;
    std::cout << "faStr1 = " << faStr1(s1) << std::endl;
    std::cout << std::endl;

    std::cout << "Строка 2: \"" << s2 << "\"" << std::endl;
    std::cout << "faStr2 = " << faStr2(s2) << std::endl;
    std::cout << std::endl;

    std::cout << "Строка 3: \"" << s3 << "\"" << std::endl;
    std::cout << "faStr3 = " << faStr3(s3) << std::endl;
    std::cout << std::endl;

    return 0;
}
