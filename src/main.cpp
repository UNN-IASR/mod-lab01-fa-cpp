// Copyright 2022 UNN-IASR
#include "../include/fun.h"
#include <iostream>
using namespace std;

int main()
{
    cout << faStr1("Hello world") << endl;      // 2
    cout << faStr1("Hello123 world") << endl;   // 1
    cout << faStr1("123 456 789") << endl;      // 0
    cout << faStr1("test") << endl;             // 1
    cout << faStr1("") << endl;                 // 0
    cout << faStr1("abc def ghi") << endl;      // 3
    cout << faStr1("a1b c2d e3f") << endl;      // 0
    cout << faStr1("   Hello   ") << endl;      // 1
    cout << faStr1("Hello, World!") << endl;    // 2
    cout << faStr1("Test1 Test2 Test") << endl; // 1

    cout << faStr2("Hello World") << endl;  // 2
    cout << faStr2("hello World") << endl;  // 1
    cout << faStr2("Hello123") << endl;     // 0
    cout << faStr2("A") << endl;            // 1
    cout << faStr2("Abc Def GHI") << endl;  // 2
    cout << faStr2("Test1 Test2") << endl;  // 0
    cout << faStr2("   Hello   ") << endl;  // 1
    cout << faStr2("Hello, World") << endl; // 1

    cout << faStr3("Hello World") << endl;      // 5
    cout << faStr3("Hi World") << endl;         // 4
    cout << faStr3("Test") << endl;             // 4
    cout << faStr3("") << endl;                 // 0
    cout << faStr3("   ") << endl;              // 0
    cout << faStr3("Hello   World") << endl;    // 5
    cout << faStr3("a b c") << endl;            // 1
    cout << faStr3("aaa bbbb") << endl;         // 4
    cout << faStr3("aa bbb") << endl;           // 3
    cout << faStr3("cat dog elephant") << endl; // 5
    return 0;
}
