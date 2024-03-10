// Copyright 2022 UNN-IASR
#include "fun.h"

int main() {
    const char* str = "Hello 123 World 456";
    unsigned int count = faStr1(str);
    std::cout << "Number of words without digits: " << count << std::endl;

    const char* str = "Hello World hEllo apple Orange";
    unsigned int count = faStr2(str);
    std::cout << "Number of words starting with an uppercase Latin letter and consisting only of lowercase Latin letters: " << count << std::endl;

    const char* str = "This is a test string for average word length calculation";
    unsigned int averageLength = faStr3(str);
    std::cout << "Average word length: " << averageLength << std::endl;
    return 0;
}
