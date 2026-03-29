#include <iostream>
#include "fun.h"

int main() {
    const char* testStr = "Hello world 123 world1 hello2 Cplusplus CleanCode";
    
    std::cout << "string: " << testStr << std::endl;
    std::cout << "task 1 " << faStr1(testStr) << std::endl;
    std::cout << "task 2 " << faStr2(testStr) << std::endl;
    std::cout << "task 3 " << faStr3(testStr) << std::endl;

    return 0;
}
