#include "main.h"

/**
 * _printf - Prints formatted output to stdout
 * @format: A string containing zero or more format specifiers
 *
 * Return: The number of characters printed (excluding the null byte used to
 *         end output to strings)
 */
int _printf(const char *format, ...)
{
	int chars_printed = 0;
	va_list args;

	va_start(args, format);
	while (*format)
	{
		if (*format == '%')
		{
			format++;

			if (*format == '%')
			{
				chars_printed += _print_percent();
			}
			else if (*format == 'c')
			{
				char c = (char)va_arg(args, int);
				chars_printed += _print_char(c);
			}
			else if (*format == 's')
			{
				const char *s = va_arg(args, const char *);
				chars_printed += _print_str(s);
			}
			else if (*format == 'd' || *format == 'i')
			{
				int num = va_arg(args, int);
				chars_printed += _print_num(num);
			}
		}
		else
		{
			chars_printed += _print_char(*format);
		}
		format++;
	}

	va_end(args);

	return (chars_printed);
}
