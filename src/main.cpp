#include <iostream>
#include "fun.h"

int main() {
    const char *test1 = "  hello world 123abc test99 ";
    const char *test2 = "Hello World hEllo WORLD ok Abc";
    const char *test3 = "one two three hi";

    std::cout << "faStr1: " << faStr1(test1) << std::endl; // 2 (hello, world)
    std::cout << "faStr2: " << faStr2(test2) << std::endl; // 3 (Hello, World, Abc)
    std::cout << "faStr3: " << faStr3(test3) << std::endl; // 4 (среднее: (3+3+5+2)/4 = 3.25 → 3)
    return 0;
}