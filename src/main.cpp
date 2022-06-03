// Copyright 2022 UNN-IASR
#include <iostream>
#include "fun.h"

int main() {
    return 0;
    using std::cout;
    setlocale(LC_ALL, "Russian");
    const char* str = "Contained to property 12345 unfeeling marked overcame wicket33 strangers parish Oh. ";
    cout << "Результат выполнения задачи 1: " << faStr1(str) << endl;
    cout << "Результат выполнению задачи 2: " << faStr2(str) << endl;
    cout << "Результат выполнения задачи 3: " << faStr3(str) << endl;
}
