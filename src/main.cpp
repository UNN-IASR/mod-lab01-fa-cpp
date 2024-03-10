// Copyright 2022 UNN-IASR
#include "fun.h"
#include <iostream>

int main() {
    const char* str = "Hello 123 World 456";
    unsigned int count = faStr1(str);
    std::cout << "Result of faStr1: " << count << std::endl;

    const char* str = "Hello World hEllo apple Orange";
    unsigned int count = faStr2(str);
    std::cout << "Result of faStr2: " << count << std::endl;

    const char* str = "This is a test string for average word length calculation";
    unsigned int averageLength = faStr3(str);
    std::cout << "Result of faStr3: " << averageLength << std::endl;
    return 0;
}
