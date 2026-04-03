// Copyright 2022 UNN-IASR
#include <iostream>
#include "fun.h"

int main() {
    const char* test1 = "abc 123 def 4567 ghi jk";
    std::cout << "faStr1(\"" << test1 << "\") = " << faStr1(test1) << std::endl;
    
    const char* test2 = "Abc def Ghi jKl MnOp";
    std::cout << "faStr2(\"" << test2 << "\") = " << faStr2(test2) << std::endl;
    
    const char* test3 = "one two three four five";
    std::cout << "faStr3(\"" << test3 << "\") = " << faStr3(test3) << std::endl;
    
    return 0;
}
