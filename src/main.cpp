// Copyright 2022 UNN-IASR
#include "fun.h"

int main() {
    const char* ex1 = "This is a Test123 string With some 456numbers 789";
    const char* ex2 = "Hello World 123 I love programming";
    const char* ex3 = "One two three";

    std::cout << faStr1(ex1) << std::endl;
    std::cout << faStr2(ex2) << std::endl;
    std::cout << faStr3(ex3) << std::endl;

    return 0;
}
