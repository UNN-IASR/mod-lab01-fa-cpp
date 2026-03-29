// Copyright 2022 UNN-IASR
#include <iostream>
#include "../include/fun.h"


int main() {
    std :: cout << faStr1("Hello world") << std :: endl;      // 2
    std :: cout << faStr1("Hello123 world") << std :: endl;   // 1
    std :: cout << faStr1("123 456 789") << std :: endl;      // 0
    std :: cout << faStr1("test") << std :: endl;             // 1
    std :: cout << faStr1("") << std :: endl;                 // 0
    std :: cout << faStr1("abc def ghi") << std :: endl;      // 3
    std :: cout << faStr1("a1b c2d e3f") << std :: endl;      // 0
    std :: cout << faStr1("   Hello   ") << std :: endl;      // 1
    std :: cout << faStr1("Hello, World!") << std :: endl;    // 2
    std :: cout << faStr1("Test1 Test2 Test") << std :: endl; // 1

    std :: cout << faStr2("Hello World") << std :: endl;  // 2
    std :: cout << faStr2("hello World") << std :: endl;  // 1
    std :: cout << faStr2("Hello123") << std :: endl;     // 0
    std :: cout << faStr2("A") << std :: endl;            // 1
    std :: cout << faStr2("Abc Def GHI") << std :: endl;  // 2
    std :: cout << faStr2("Test1 Test2") << std :: endl;  // 0
    std :: cout << faStr2("   Hello   ") << std :: endl;  // 1
    std :: cout << faStr2("Hello, World") << std :: endl; // 1

    std :: cout << faStr3("Hello World") << std :: endl;      // 5
    std :: cout << faStr3("Hi World") << std :: endl;         // 4
    std :: cout << faStr3("Test") << std :: endl;             // 4
    std :: cout << faStr3("") << std :: endl;                 // 0
    std :: cout << faStr3("   ") << std :: endl;              // 0
    std :: cout << faStr3("Hello   World") << std :: endl;    // 5
    std :: cout << faStr3("a b c") << std :: endl;            // 1
    std :: cout << faStr3("aaa bbbb") << std :: endl;         // 4
    std :: cout << faStr3("aa bbb") << std :: endl;           // 3
    std :: cout << faStr3("cat dog elephant") << std :: endl; // 5
    return 0;
}
