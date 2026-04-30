#include "fun.h"
#include <cctype>
#include <cwctype>

unsigned int faStr1(const char* str)
{
    if (str == nullptr) return 0;
    
    unsigned int count = 0;
    int i = 0;
    
    while (str[i] != '\0')
    {
        // пропускаем пробелы
        while (str[i] != '\0' && isspace(str[i])) i++;
        
        if (str[i] == '\0') break;
        
        bool hasDigit = false;
        bool hasLetter = false;
        
        // обрабатываем слово
        while (str[i] != '\0' && !isspace(str[i]))
        {
            if (isdigit(str[i]))
                hasDigit = true;
            else if (isalpha(str[i]))
                hasLetter = true;
            i++;
        }
        
        // слово не содержит цифр И содержит хотя бы одну букву
        if (!hasDigit && hasLetter)
            count++;
    }
    
    return count;
}

unsigned int faStr2(const char* str)
{
    if (str == nullptr) return 0;
    
    unsigned int count = 0;
    int i = 0;
    
    while (str[i] != '\0')
    {
        // пропускаем пробелы
        while (str[i] != '\0' && isspace(str[i])) i++;
        
        if (str[i] == '\0') break;
        
        bool valid = true;
        
        // проверяем первую букву (должна быть заглавной латинской)
        if (!isupper(str[i]) || !isalpha(str[i]))
            valid = false;
        
        i++;
        
        // проверяем остальные символы (должны быть строчными латинскими)
        while (str[i] != '\0' && !isspace(str[i]))
        {
            if (!islower(str[i]) || !isalpha(str[i]))
                valid = false;
            i++;
        }
        
        if (valid)
            count++;
    }
    
    return count;
}

unsigned int faStr3(const char* str)
{
    if (str == nullptr) return 0;
    
    unsigned int totalLength = 0;
    unsigned int wordCount = 0;
    int i = 0;
    
    while (str[i] != '\0')
    {
        // пропускаем пробелы
        while (str[i] != '\0' && isspace(str[i])) i++;
        
        if (str[i] == '\0') break;
        
        unsigned int length = 0;
        
        // считаем длину слова
        while (str[i] != '\0' && !isspace(str[i]))
        {
            length++;
            i++;
        }
        
        totalLength += length;
        wordCount++;
    }
    
    if (wordCount == 0)
        return 0;
    
    // математическое округление (0.5 вверх)
    double average = static_cast<double>(totalLength) / wordCount;
    return static_cast<unsigned int>(average + 0.5);
}
