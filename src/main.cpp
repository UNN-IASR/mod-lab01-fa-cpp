// Copyright 2022 UNN-IASR
#include <iostream>

#include "fun.h"

int main() {
    // Test 1
    std::cout << "[TEST 1]\n";
    const char* test1[] = {
        "abc 123 xyz 456 qwe",
        "asd123 fgh456 zxc789",
        "   qwe   rty    uio   ",
        "99999",
        "",
        "     "
    };

    for (int i = 0; i < 6; i++) {
        std::cout << "  \"" << test1[i] << "\" -> " << faStr1(test1[i]) << "\n";
    }

    // Test 2
    std::cout << "\n[TEST 2]\n";
    const char* test2[] = {
        "Abc def Ghi jkl Mno pqr",
        "Xyz Abc Def Ghi",
        "   Qwe   Asd    Zxc   ",
        "Ab12 Cd34 Ef56",
        "A B C D E F"
    };

    for (int i = 0; i < 5; i++) {
        std::cout << "  \"" << test2[i] << "\" -> " << faStr2(test2[i]) << "\n";
    }

    // Test 3
    std::cout << "\n[TEST 3]\n";
    const char* test3[] = {
        "qwe asd zxc rty fgh",
        "a bb ccc dddd eeeee",
        "   abc   def    ghi   ",
        "",
        "x y z w v",
        "   "
    };

    for (int i = 0; i < 6; i++) {
        std::cout << "  \"" << test3[i] << "\" -> " << faStr3(test3[i]) << "\n";
    }

    return 0;
}