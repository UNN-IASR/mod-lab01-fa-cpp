// Copyright 2022 UNN-IASR
#include <iostream>
#include "fun.h"

int main() {
    const char* str1 = "Hello 123 World 456";
    unsigned int count = faStr1(str1);
    std::cout << "Result of faStr1: " << count << std::endl;

    const char* str2 = "Hello World hEllo apple Orange";
    unsigned int count = faStr2(str2);
    std::cout << "Result of faStr2: " << count << std::endl;

    const char* str3 = "This is a test string";
    unsigned int averageLength = faStr3(str3);
    std::cout << "Result of faStr3: " << averageLength << std::endl;
    return 0;
}
