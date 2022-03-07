// Copyright 2022 UNN-IASR
#include "fun.h"

int main() {
    const char* str = "My mame is Alice ";
    unsigned int result1 = faStr1(str);
    unsigned int result2 = faStr2(str);
    unsigned int result3 = faStr3(str);
    std::cout << result1 << std::endl;
    std::cout << result2 << std::endl;
    std::cout << result3 << std::endl;
}
