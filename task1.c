/**
 * _printf - Printf function
 * @format: format.
 * Return: Printed chars.
 */
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
            if (format[i] == 'd' || format[i] == 'i')
            {
                int num = va_arg(args, int);
                char buffer[BUFF_SIZE];
		int length = write_number(num >= 0, 0, buffer, 0, 0, 0, 0);

		printed_chars += write_num(0, buffer, 0, 0, 0, length, ' ', ' ');
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
