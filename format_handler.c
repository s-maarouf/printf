#include "main.h"

/**
variabke

 * _print_char - Prints a single character
 * @list: list of arguments
 *
 * Return: Always returns 1
 */
int _print_char(va_list list)
{
	_putchar(va_arg(list, int));
	return (1);
}

/**
 * _print_str - Prints a string of characters
 * @list: list of arguments
 *
 * Return: The number of characters printed
 */
int _print_str(va_list list)
{
	int i;
	char *str;

	str = va_arg(list, char *);
	if (str == NULL)
		str = "(null)";
	for (i = 0; str[i] != '\0'; i++)
		_putchar(str[i]);
	return (i);
}

/**
 * print_percent - Prints a percent symbol
 * @list: list of arguments
 * Return: Will return the amount of characters printed.
 */
int print_percent(__attribute__((unused))va_list list)
{
	_putchar('%');
	return (1);
}

/**
 * print_integer - Prints an integer
 * @list: list of arguments
 * Return: Will return the amount of characters printed.
 */
int print_integer(va_list list)
{
	int num_length;

	num_length = print_number(list);
	return (num_length);
}

/**
 * unsigned_integer - Prints Unsigned integers
 * @list: List of all of the argumets
 * Return: a count of the numbers
 */
int unsigned_integer(va_list list)
{
	unsigned int num;

	num = va_arg(list, unsigned int);

	if (num == 0)
		return (print_unsgined_number(num));

	if (num < 1)
		return (-1);
	return (print_unsgined_number(num));
}
