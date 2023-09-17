/**
* printf - function to print
* @format: string
* @...: indefinte var
*
*Return: num of chars
*/

#include "main.h"
int _printf(const char *format, ...)
{
	va_list args;
	int ch_count = 0;

	if (format == NULL)
		return (-1);

	va_start(args, format);

	for (; *format; format++)
	{
		if (*format == '%')
		{
			format++;
			if (*format == '\0')
				break;
			if (*format == '%')
			{
				write(1, format, 1);
				ch_count++;
			}
			else if (*format == 'c')
			{
				char c = (char)va_arg(args, int);

				write(1, &c, 1);
				ch_count++;
			}
			else if (*format == 's')
			{
				char *str = va_arg(args, char *);

				int s_len = strlen(str);
				write(1, str, s_len);
				ch_count += s_len;
			}
		}
		else
		{
			write(1, format, 1);
			ch_count++;
		}
	}

	va_end(args);
	return (ch_count);
}
