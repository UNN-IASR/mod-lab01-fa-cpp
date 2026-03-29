// Copyright 2022 UNN-IASR

#include "fun.h"
#include <iostream>
#include <windows.h>

int main() {
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

    std::cout << "Задача №1" << std::endl;

    char test1[] = "hello world test dasdsad";
    std::cout << "Строка: \"" << test1 << "\"" << std::endl;
    std::cout << "Слов без цифр: " << faStr1(test1) << std::endl
              << std::endl;

    char test2[] = "abc123 def 456 ghi";
    std::cout << "Строка: \"" << test2 << "\"" << std::endl;
    std::cout << "Слов без цифр: " << faStr1(test2) << std::endl
              << std::endl;

    std::cout << "Задача №2" << std::endl;

    char test3[] = "Hello world Java program";
    std::cout << "Строка: \"" << test3 << "\"" << std::endl;
    std::cout << "Слов с заглавной буквой и строчными: "
              << faStr2(test3) << std::endl << std::endl;

    char test4[] = "Cat Dog123 Fish Tree APPLE";
    std::cout << "Строка: \"" << test4 << "\"" << std::endl;
    std::cout << "Слов с заглавной буквой и строчными: "
              << faStr2(test4) << std::endl << std::endl;

    std::cout << "Задача №3" << std::endl;

    char test5[] = "hello world";
    std::cout << "Строка: \"" << test5 << "\"" << std::endl;
    std::cout << "Средняя длина слова: " << faStr3(test5) << std::endl
              << std::endl;

    char test6[] = "a bb ccc dddd";
    std::cout << "Строка: \"" << test6 << "\"" << std::endl;
    std::cout << "Средняя длина слова: " << faStr3(test6) << std::endl
              << std::endl;

    char test7[] = "   one   two   three   ";
    std::cout << "Строка: \"" << test7 << "\"" << std::endl;
    std::cout << "Средняя длина слова: " << faStr3(test7) << std::endl
              << std::endl;

    char test8[] = "";
    std::cout << "Строка: (пустая)" << std::endl;
    std::cout << "Средняя длина слова: " << faStr3(test8) << std::endl
              << std::endl;

    char test9[] = "     ";
    std::cout << "Строка: (только пробелы)" << std::endl;
    std::cout << "Средняя длина слова: " << faStr3(test9) << std::endl
              << std::endl;

    char test10[] = "programming";
    std::cout << "Строка: \"" << test10 << "\"" << std::endl;
    std::cout << "Средняя длина слова: " << faStr3(test10) << std::endl
              << std::endl;

    char test11[] = "abc 123 !@#";
    std::cout << "Строка: \"" << test11 << "\"" << std::endl;
    std::cout << "Средняя длина слова: " << faStr3(test11) << std::endl
              << std::endl;

    char test12[] = "a bc def";
    std::cout << "Строка: \"" << test12 << "\"" << std::endl;
    std::cout << "Средняя длина слова: " << faStr3(test12) << std::endl
              << std::endl;

    char test13[] = "a bc defg";
    std::cout << "Строка: \"" << test13 << "\"" << std::endl;
    std::cout << "Средняя длина слова: " << faStr3(test13) << std::endl
              << std::endl;

    char test14[] = "a bc defgh";
    std::cout << "Строка: \"" << test14 << "\"" << std::endl;
    std::cout << "Средняя длина слова: " << faStr3(test14) << std::endl
              << std::endl;

    return 0;
}
