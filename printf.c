
/**
 * _printf - Function to print formatted output
 * @format: String
 * @...: Indefinite arguments
 *
 * Return: Number of characters printed
 */
#include "main.h"
int _printf(const char *format, ...)
{
	va_list args;
	int ch_count = 0;

	if (format == NULL)
		return (-1);
	va_start(args, format);
	while (*format)
	{
		if (*format != '%')
		{
			write(1, format, 1);
			ch_count++;
		}
		else
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
		format++;
	}
	va_end(args);
	return (ch_count);
}
