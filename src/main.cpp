#include "fun.h"

int main() {
    setlocale(LC_ALL, "Russian");
    const char* str = "Contained to property 445unfeeling marked overcame wicket33 strangers parish Oh";
    std::cout << "Результат выполнения задачи 1: " << faStr1(str) << std::endl;
    std::cout << "Результат выполнению задачи 2: " << faStr2(str) << std::endl;
    std::cout << "Результат выполнения задачи 3: " << faStr3(str) << std::endl;
}
