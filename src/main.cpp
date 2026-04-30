// Copyright 2024 <Copyright Owner>
#include <iostream>
#include "fun.h"

int main() {
    const char* str = "Hello world Test123 ABC def Ghi";

    std::cout << "Без цифр: " << faStr1(str) << std::endl;
    std::cout << "С заглавной: " << faStr2(str) << std::endl;
    std::cout << "Средняя длина: " << faStr3(str) << std::endl;

    return 0;
}
