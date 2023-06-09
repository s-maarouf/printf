#include "main.h"

/**
 * _printf - A function that reproduce the behaviour of printf
 *
 * @format: A string containing zero or more format specifiers
 *
 * Return: The number of characters printed (excluding the null byte used to
 *         end output to strings)
 */
int _printf(const char *format, ...)
{
	int printed_chars;
	conver_t f_list[] = {
		{"c", _print_char},
		{"s", _print_str},
		{"%", print_percent},
		{"d", print_integer},
		{"i", print_integer},
		{"u", unsigned_integer},
		{"b", print_binary},
		{"x", print_hex},
		{"X", print_heX},
		{"o", print_octal},
		{"p", print_pointer},
		{"r", print_reversed},
		{"R", rot13},
		{"S", print_S},
		{NULL, NULL}
	};
	va_list arg_list;

	if (format == NULL)
		return (-1);

	va_start(arg_list, format);
	printed_chars = parser(format, f_list, arg_list);
	va_end(arg_list);
	return (printed_chars);

}
