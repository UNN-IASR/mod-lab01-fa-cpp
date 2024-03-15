// Copyright 2022 UNN-IASR
#include "fun.h"

int main() {
    //char *str = new char[1024];
    const char *str = "a1 a2 a3 a A A111 a3 a1a1a a11 Aaaa a a 1Aa 1aA 1a";
    //std::cin.getline(str, 1024);
    //const char *str = "A1 Aa A A aa 1Aa 1A 1a";
    //const char *str = "1Aa 1A 1a";
    std::cout << faStr1(str) << std::endl;
    std::cout << faStr2(str) << std::endl;
    std::cout << faStr3(str) << std::endl;
    return 0;
}
