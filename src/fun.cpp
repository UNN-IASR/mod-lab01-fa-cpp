// Copyright 2022 UNN-IASR
#include "fun.h"

unsigned int faStr1(const char *str) {
    if (str == nullptr) return 0;
    
    unsigned int count = 0;  
    bool inWord = false;      
    bool hasDigit = false;    
    
    for (int i = 0; str[i] != '\0'; i++) {
        char c = str[i];
        
        if (c == ' ' || c == '\t' || c == '\n') {
            if (inWord && !hasDigit) {
                count++;  
            }
            inWord = false;
            hasDigit = false;
        }
        else {
            inWord = true;  
            
            if (c >= '0' && c <= '9') {
                hasDigit = true;  
            }
        }
    }
    
    if (inWord && !hasDigit) {
        count++;
    }
    
    return count;
}

unsigned int faStr2(const char *str) {
    if (str == 0) return 0;
    
    int result = 0;  
    int i = 0;       
    
    while (str[i] != '\0') {
        while (str[i] == ' ' || str[i] == '\t' || str[i] == '\n') {
            i++;
        }
        
        if (str[i] == '\0') break;
        
        char firstChar = str[i];
        int isGood = 1;  
        
        if (!(firstChar >= 'A' && firstChar <= 'Z')) {
            isGood = 0;  
        }
        
        if (str[i] != '\0') {
            i++;
        }
        
        while (str[i] != '\0' && str[i] != ' ' && str[i] != '\t' && str[i] != '\n') {
            if (!(str[i] >= 'a' && str[i] <= 'z')) {
                isGood = 0;  
            }
            i++;
        }
        
        if (isGood == 1) {
            result++;
        }
    }
    
    return result;
}

unsigned int faStr3(const char *str) {
    if (str == 0) return 0;
    
    int totalLength = 0;  
    int wordCount = 0;     
    int i = 0;
    
    while (str[i] != '\0') {
        while (str[i] == ' ' || str[i] == '\t' || str[i] == '\n') {
            i++;
        }

        if (str[i] == '\0') break;

        int wordLength = 0;
        
        while (str[i] != '\0' && str[i] != ' ' && str[i] != '\t' && str[i] != '\n') {
            wordLength++;
            i++;
        }

        totalLength = totalLength + wordLength;
        wordCount++;
    }
    
    if (wordCount == 0) return 0;
    
    double average = (double)totalLength / wordCount;
    
    unsigned int result = (unsigned int)(average + 0.5);
    
    return result;
}
