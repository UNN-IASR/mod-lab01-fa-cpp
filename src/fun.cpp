#include "fun.h"
#include <cctype>

unsigned int faStr1(const char* str)
{
    unsigned int count = 0;

    while (*str)
    {
        // пропускаем пробелы
        while (*str && isspace(*str)) str++;

        if (!*str) break;

        bool hasDigit = false;

        // обрабатываем слово
        while (*str && !isspace(*str))
        {
            if (isdigit(*str))
                hasDigit = true;
            str++;
        }

        if (!hasDigit)
            count++;
    }

    return count;
}

unsigned int faStr2(const char* str)
{
    unsigned int count = 0;

    while (*str)
    {
        while (*str && isspace(*str)) str++;

        if (!*str) break;

        bool valid = true;

        // первая буква
        if (!isupper(*str))
            valid = false;

        str++;

        // остальные символы
        while (*str && !isspace(*str))
        {
            if (!islower(*str))
                valid = false;
            str++;
        }

        if (valid)
            count++;
    }

    return count;
}

unsigned int faStr3(const char* str)
{
    unsigned int totalLength = 0;
    unsigned int wordCount = 0;

    while (*str)
    {
        while (*str && isspace(*str)) str++;

        if (!*str) break;

        unsigned int length = 0;

        while (*str && !isspace(*str))
        {
            length++;
            str++;
        }

        totalLength += length;
        wordCount++;
    }

    if (wordCount == 0)
        return 0;

    // округление
    return (totalLength + wordCount / 2) / wordCount;
}
