// Copyright 2022 UNN-IASR
#include "fun.h"
#include <iostream>
using namespace std;

int main() {
    const char* example1 = "Thg#rg 5fd ff4yh 5 .f h  ";
    const char* example2 = " Thgrg 5fd ff4yh T5 f* H";
    const char* example3 = " &#g^ gddg #^HDF5Hs rujrtj 46375";
    cout << faStr1(example1) << endl;
    cout << faStr2(example2) << endl;
    cout << faStr3(example3) << endl;
    return 0;
}
