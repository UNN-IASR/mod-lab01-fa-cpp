// Copyright 2026 <UNN-IASR>

#include <iostream>
#include "fun.h"

int main() {
    const char *t1 = "  hello world 123abc test99 ";
    const char *t2 = "Hello World hEllo WORLD ok Abc";
    const char *t3 = "one two three hi";

    std::cout << "faStr1: " << faStr1(t1) << std::endl;
    std::cout << "faStr2: " << faStr2(t2) << std::endl;
    std::cout << "faStr3: " << faStr3(t3) << std::endl;
    return 0;
}
