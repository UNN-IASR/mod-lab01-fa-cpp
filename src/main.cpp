// Copyright 2022 UNN-IASR
#include <iostream>
#include "fun.h"

int main() {
    // Task 1:
    const char *s1a = "hello world unn123 adw 99ac";

    std::cout << "=== 1 ===" << std::endl;
    std::cout << "\"" << s1a << "\" -> "
              << faStr1(s1a) << " (expected 2)" << std::endl;

    // Task 2:
    const char *s2a = "Hello World qwe BAR baz";

    std::cout << "\n=== 2 ===" << std::endl;
    std::cout << "\"" << s2a << "\" -> "
              << faStr2(s2a) << " (expected 2)" << std::endl;

    // Task 3
    const char *s3a = "hi hello zdravstvuite";

    std::cout << "\n=== 3 ===" << std::endl;
    std::cout << "\"" << s3a << "\" -> "
              << faStr3(s3a) << " (expected 4)" << std::endl;

    return 0;
}
