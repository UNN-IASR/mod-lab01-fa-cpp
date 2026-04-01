// Copyright 2022 UNN-IASR
#include <iostream>
#include "fun.h"

int main() {
    const char* str = "Hello world123 raz dva vanek9423423";
    std::cout << faStr1(str) << "\n";
    std::cout << faStr2(str) << "\n";
    
    std::cout << faStr3(str) << "\n";
    return 0;
}
