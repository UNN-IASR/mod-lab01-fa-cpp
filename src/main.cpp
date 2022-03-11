// Copyright 2022 UNN-IASR
#include <iostream>
#include "fun.h"

int main() {
    using std::cout;
    const char* str = "Back to the 1980s Retrowave";
    unsigned int result1 = faStr1(str);
    unsigned int result2 = faStr2(str);
    unsigned int result3 = faStr3(str);
    cout << "Result of 1-st function = "; cout << result1;
    cout << "Result of 2-nd function = "; cout << result2;
    cout << "Result of 3-rd function = "; cout << result3;
}
