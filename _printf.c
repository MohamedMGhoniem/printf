#include "main.h"

int _printf(const char *format, ...)
{
    va_list args;
    int printed_chars = 0;
    int i = 0;

    va_start(args, format);

    while (format && format[i])
    {
        if (format[i] == '%')
        {
            i++;
            if (format[i] == 'c')
            {
                char c = va_arg(args, int);
                putchar(c);
                printed_chars++;
            }
            else if (format[i] == 's')
            {
                char *str = va_arg(args, char*);
                while (*str)
                {
                    putchar(*str);
                    str++;
                    printed_chars++;
                }
            }
            else if (format[i] == '%')
            {
                putchar('%');
                printed_chars++;
            }
            else if (format[i] == 'd' || format[i] == 'i')
            {
                int num = va_arg(args, int);
                printf("%d", num);
                printed_chars += digits_count(num);
            }
            else
            {
                putchar('%');
                putchar(format[i]);
                printed_chars += 2;
            }
        }
        else
        {
            putchar(format[i]);
            printed_chars++;
        }
        i++;
    }

    va_end(args);

    return printed_chars;
}

int digits_count(int num)
{
    int count = 0;
    if (num == 0)
        return 1;
    if (num < 0)
    {
        count++;
        num *= -1;
    }
    while (num > 0)
    {
        count++;
        num /= 10;
    }
    return count;
}

