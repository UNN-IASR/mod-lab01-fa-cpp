// Copyright 2022 UNN-IASR
#include "fun.h"

int main() {
    const char* example1 = "Thg#rg 5fd ff4yh 5 .f h  ";
    const char* example2 = " Thgrg 5fd ff4yh T5 f* H K";
    const char* example3 = " &#g^ gddg #^HDF5Hs rujrtj 46375";
    std::cout << faStr1(example1) << std::endl;
    std::cout << faStr2(example2) << std::endl;
    std::cout << faStr3(example3) << std::endl;
    return 0;
}
