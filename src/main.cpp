// Copyright 2022 UNN-IASR
#include <stdio.h>
#include "fun.h"

int main() {
    const char* testMessage =
    " GNEURSHK -3500 is The Thing  of Fut4ure  until the fds234 34h 4h Est s4";
    unsigned int result1 = faStr1(testMessage);
    unsigned int result2 = faStr2(testMessage);
    unsigned int result3 = faStr3(testMessage);
    printf("Words not containing numbers: %d", result1);
    printf("Capitalized words containing only latin letters: %d", result2);
    printf("Average word length: %d", result3);
    return 0;
}
