#include "main.h"
int digits_count(int num);
int handle_format(char specifier, va_list args);
void handle_char(char c);
int handle_string(char *str);
void handle_integer(int num);
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
 * handle_format - to handle format
 * @specifier: first arg
 * @args: second arg
 *
 * Return: num of digits
 */
int handle_format(char specifier, va_list args)
{
	if (specifier == 'c')
	{
		char c = va_arg(args, int);

		handle_char(c);
		return (1);
	}
	else if (specifier == 's')
	{
		char *str = va_arg(args, char *);

		return (handle_string(str));
	}
	else if (specifier == '%')
	{
		putchar('%');
		return (1);
	}
	else if (specifier == 'd' || specifier == 'i')
	{
		int num = va_arg(args, int);

		handle_integer(num);
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
 * handle_char - handling char
 * @c: first arg
 *
*/
void handle_char(char c)
{
	putchar(c);
}
/**
 * handle_string - handling string
 * @str: first arg
 *
 * Return: num of char
*/
int handle_string(char *str)
{
	int printed_chars = 0;

	while (*str)
	{
		putchar(*str);
		str++;
		printed_chars++;
	}
	return (printed_chars);
}
/**
 * handle_integer - handling_integer
 * @num: first arg
*/
void handle_integer(int num)
{
	printf("%d", num);
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
