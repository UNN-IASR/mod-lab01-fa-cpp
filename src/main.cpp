// Copyright 2022 UNN-IASR
#include "fun.h"

int main()
{
    char str1[] = "I have no n4mbers in 4 w0rds";
    char str2[] = "I Have 2 words sTarTing with BIG Le11ers";
    char str3[] = "Middle length of these words is four";

    std::cout << faStr1(str1) << std::endl;
    std::cout << faStr2(str2) << std::endl;
    std::cout << faStr3(str3);
}
