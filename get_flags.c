#include "main.h"

/**
 * get_flags - Calculates active flags
 * @format: Formatted string in which to print the arguments
 * @i: take a parameter.
 * Return: Flags:
 */
int get_flags(const char *format, int *i)
{
    int curr_i = *i + 1;
    int flags = 0;
    const char FLAGS_CH[] = "-+0# ";
    const int FLAGS_ARR[] = {F_MINUS, F_PLUS, F_ZERO, F_HASH, F_SPACE};

    while (format[curr_i] != '\0')
    {
        for (int j = 0; FLAGS_CH[j] != '\0'; j++)
        {
            if (format[curr_i] == FLAGS_CH[j])
            {
                flags |= FLAGS_ARR[j];
                break;
            }
        }
        if (FLAGS_CH[j] == '\0')
            break;
        curr_i++;
    }

    *i = curr_i - 1;
    return flags;
}
