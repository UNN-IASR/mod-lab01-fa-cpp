// Copyright 2022 UNN-IASR
#include "fun.h"
#include <math.h>
#include <stdio.h>
#include <iostream>
#include <vector>
#include <cstring>

unsigned int faStr1(const char* str) {
    bool space = true;
    bool correct = true;
    int counter = 0;
    for (int i = 0; i < strlen(str); i++) {
        if (i != 0 && str[i] == ' ' && space == false) {
            if (correct == true) {
                counter++;
            }
            space = true;
            correct = true;
        }
        else if (static_cast<int>(str)[i] >= 48 && static_cast<int>(str)[i] <= 57) {
            correct = false;
            space = false;
        }
        else if (str[i] != ' ') {
            if (i == strlen(str) - 1 && correct == true) {
                    counter++;
                }
            space = false;
        }
    }
    return counter;
}

unsigned int faStr2(const char* str) {
    int counter = 0;
    bool space = true;
    bool correct1 = false;
    bool correct2 = false;
    bool correct3 = false;
    for (int i = 0; i < strlen(str); i++) {
        if (str[i] == ' ') {
            if (correct1 == true && correct2 == true && correct3 == false) {
                counter++;
                correct1 = false;
                correct2 = false;
                correct3 = false;
            }
            space = true;
        }
        else if ((int)str[i] >= 65 && (int)str[i] <= 90 && space == true) {
            correct1 = true;
            space = false;
        }
        else if ((int)str[i] >= 97 && (int)str[i] <= 122 && space == false) {
            correct2 = true;
            space = false;
            if (i == strlen(str) - 1 && correct1 == true && correct2 == false) {
                counter++;
                correct1 = false;
                correct2 = false;
                correct3 = false;
            }
        }
        else if (!((int)str[i] >= 97 && (int)str[i] <= 122) && space == false) {
            correct3 = true;
            space = false;
            if (i == strlen(str) - 1 && correct1 == true && correct2 == false) {
                counter++;
                correct1 = false;
                correct2 = false;
                correct3 = false;
            }
        }
    }
    return counter;
}

unsigned int faStr3(const char* str) {
    int lenght = 0;
    int average_lenght = 0;
    std::vector<int> numbers;
    for (int i = 0; i < strlen(str); i++) {
        if (str[i] == ' ') {
            if (lenght != 0) {
                numbers.push_back(lenght);
            }
            lenght = 0;
        }
        else if (str[i] != ' ') {
            lenght++;
            if (i == strlen(str) - 1) {
                numbers.push_back(lenght);
            }
        }
    }
    for (int i = 0; i < numbers.size(); i++) {
        average_lenght += numbers[i];
    }
    average_lenght = round(average_lenght / numbers.size());

    return average_lenght;
}
