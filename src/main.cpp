// Copyright 2022 UNN-IASR
#include "fun.h"
#include <iostream>
#include <string>
using namespace std;

int main() {
    const char* str;
    str = "qwe4  gftt e 555gr rrgr  grhh ";
    cout << faStr1(str) << endl;
    str = "Hello, world!";
    cout << faStr2(str) << endl;
    str = " six monkeys";
    cout << faStr3(str) << endl;
    return 0;
}
