#include <iostream>
#include "fun.h"
#include <windows.h>

using namespace std;

int main()
{
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);   
    const char* str = "Hello world Test123 ABC def Ghi";

    cout << "Без цифр: " << faStr1(str) << endl;
    cout << "С заглавной: " << faStr2(str) << endl;
    cout << "Средняя длина: " << faStr3(str) << endl;

    return 0;
}
