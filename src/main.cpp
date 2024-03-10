// Copyright 2022 UNN-IASR
#include "fun.h"

int main() {
    //Работа функции faStr1
    char str1[] = "111";
    std::cout << faStr1(str1); //0
    std::cout << "\n";

    char str2[] = "Hel1o";
    std::cout << faStr1(str2); //0
    std::cout << "\n";

    char str3[] = "Hello";
    std::cout << faStr1(str3); //1
    std::cout << "\n";

    char str4[] = "Hello w0rld every0ne"; 
    std::cout << faStr1(str4); //1
    std::cout << "\n";

    char str_[] = "qwe4  gftt e 555gr rrgr  grhh ";
    std::cout << faStr1(str_); //4
    std::cout << "\n";

    char str_1[] = "  qwe4 ";
    std::cout << faStr1(str_1); //0
    std::cout << "\n\n";

    //Работа функции faStr2
    char str5[] = "Hello World";
    std::cout << faStr2(str5); //2
    std::cout << "\n";

    char str6[] = "Hello world";
    std::cout << faStr2(str6); //1
    std::cout << "\n";

    char str7[] = "helLO wOrLd";
    std::cout << faStr2(str7); //0
    std::cout << "\n";

    char str8[] = "HELLO WORLD";
    std::cout << faStr2(str8); //0
    std::cout << "\n";

    char str9[] = "He;;o w0*-d";
    std::cout << faStr2(str9); //0
    std::cout << "\n";

    char str_2[] = "Hello, world!";
    std::cout << faStr2(str_2); //0
    std::cout << "\n\n";

    //Работа функции faStr3
    char str10[] = "Hello World";
    std::cout << faStr3(str10); //5
    std::cout << "\n";

    char str11[] = "1 12 123 1234 12345";
    std::cout << faStr3(str11); //3
    std::cout << "\n";

    char str12[] = "Life, believe, is not a dream so dark as sages say";
    std::cout << faStr3(str12); //4
    std::cout << "\n";

    char str13[] = " bad dog ";
    std::cout << faStr3(str13); //3
    std::cout << "\n";

    char str14[] = " six monkeys";
    std::cout << faStr3(str14); //5
    std::cout << "\n";
    return 0;
}
