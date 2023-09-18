#include "main.h"
/**
 * _printf - Function to print formatted output
 * @format: String
 * @...: Indefinite arguments
 *
 * Return: Number of characters printed
 */
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
			printed_chars += handle_format(format[i], args);
		}
		else
		{
			putchar(format[i]);
			printed_chars++;
		}
		i++;
	}

	va_end(args);

	return (printed_chars);
}
/**
 * handle_format - handle format in printf
 * @specifier: first arg
 * @args: second arg
 *
 * Return: num of printed chars
 */
int handle_format(char specifier, va_list args)
{
	if (specifier == 'c')
	{
		char c = va_arg(args, int);

		putchar(c);
		return (1);
	}
	else if (specifier == 's')
	{
		char *str = va_arg(args, char *);
		int printed_chars = 0;

		while (*str)
		{
			putchar(*str);
			str++;
			printed_chars++;
		}

		return (printed_chars);
	}
	else if (specifier == '%')
	{
		putchar('%');
		return (1);
	}
	else if (specifier == 'd' || specifier == 'i')
	{
		int num = va_arg(args, int);

		printf("%d", num);
		return (digits_count(num));
	}
	else
	{
		putchar('%');
		putchar(specifier);
		return (2);
	}
}
/**
 * digits_count - count digits
 * @num: first arg
 *
 * Return: count of digits
 */

int digits_count(int num)
{
	int count = 0;

	if (num == 0)
		return (1);

	if (num < 0)
	{
		count++;
		num = -num;
	}

	while (num > 0)
	{
		count++;
		num /= 10;
	}

	return (count);
}
