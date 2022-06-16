// Copyright 2022 UNN-IASR
unsigned int faStr1(const char* str) {
    int i = 0;
    int a = 0;
    bool b = false;
    bool c = false;
    
    while (str[i] != 0) {
        char d = str[i];
        if (d != ' ' && !b)
            b = true;
        if (d >= '0' && d <= '9')
            c = true;
        if (d == ' ' && b && !c) {
            b = false;
            a++;
        } else if (d == ' ' && b) {
            b = false;
            c = false;
        }
        i++;
    }
    if (b && !c)
        a++;
    return a;
}

unsigned int faStr2(const char* str) {
    int i = 0;
    int a = 0;
    bool b = false;
    bool c = false;

    while (str[i] != 0) {
        char d = str[i];
        if (d != ' ') {
            if (d >= 'A' && d <= 'Z' && !b && !c)
                b = true;
            else if (d >= 'A' && d <= 'Z' && b && !c)
                c = true;
            else if ((d < 'a' || d > 'z') && b && !c)
                c = true;
        }
        if (d == ' ' && b && !c) {
            b = false;
            a++;
        }
        if (d == ' ' && b && c) {
            b = false;
            c = false;
        }
        i++;
    }
    if (b && !c)
        a++;
    return a;
}

unsigned int faStr3(const char* str) {
    int i = 0;
    int a = 0;
    int b = 0;
    bool c = false;

    while (str[i] != 0) {
        if (str[i] != ' ' && !c)
            c = true;
        if (str[i] == ' ' && c) {
            c = false;
            a++;
        }
        if (c)
            b++;
        i++;
    }
    if (c)
        a++;
    return static_cast<int>(static_cast<double>(b) / a + 0.5);
}

