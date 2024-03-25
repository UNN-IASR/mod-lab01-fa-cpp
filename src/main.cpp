#include "fun.h"
#include <iostream>

int main() {
    const char* str = " six monkeys";

    std::cout << "Number of words without digits: " << faStr1(str) << std::endl;
    std::cout << "Number of words starting with uppercase letter: " << faStr2(str) << std::endl;
    std::cout << "Average word length: " << faStr3(str) << std::endl;

    return 0;
}
