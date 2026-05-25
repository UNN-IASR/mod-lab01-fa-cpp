// Copyright 2022 UNN-IASR
#include <stdio.h>
#include "fun.h"

int main() {
    const char* testMessage =
    " GNEURSHK -3500 is The Thing  of Fut43ure  until the fds23234 334h 4hh Est s4";
    unsigned int result1 = faStr1(testMessage);
    unsigned int result2 = faStr2(testMessage);
    unsigned int result3 = faStr3(testMessage);
    printf("Words not containing numbers: %d", result1);
    printf("Words of only latin letters starting on a capital letter: %d", result2);
    printf("Average word length: %d", result3);
    return 0;
}
