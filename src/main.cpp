// Copyright 2022 UNN-IASR
#include <iostream>
#include "fun.h"
using std::cout;
using std::endl;

int main() {
    cout << "Task 1" << endl;
    const char* str1 = "day  week is 4k51q way  5q  a5  2rr2 this";
    unsigned int result1 = faStr1(str1);
    cout << "String: \"" << str1 << "\"" << endl;
    cout << "Number of words for task 1: " << result1 << endl << endl;

    cout << "Task 2" << endl;
    const char* str2 = "Do you Remember this Day?";
    unsigned int result2 = faStr2(str2);
    cout << "String: \"" << str2 << "\"" << endl;
    cout << "Number of words for task 2: " << result2 << endl << endl;

    cout << "Task 3" << endl;
    const char* str3 = " six monkeys in the club";
    unsigned int result3 = faStr3(str3);
    cout << "String: \"" << str3 << "\"" << endl;
    cout << "Number of words for task 3: " << result3 << endl << endl;
    return 0;
}


