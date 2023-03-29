#include "main.h"

/**
 * print_numbers - function print numbers with recursion
 *
 * @number: input
 * @len: pointer counte the lenght of operration
 *
 * Return: void
 */
void print_numbers(int number, int *len)
{
	if (number == -2147483648)
	{
		*len += 11;
		write(1, "-2147483648", 11);
		return;
	}
	if (number < 0)
	{
		*len += _putchar('-');
		number *= -1;
	}
	if (number >= 0 && number <= 9)
		*len += _putchar(number + 48);
	else
	{
		print_numberss(number / 10, len);
		print_numberss(number % 10, len);
	}
}

/**
 * print_plus - print the flag '+' for positive numbers
 * @num: the number to print
 * @len: pointer to the length counter
 */

void print_plus(int num, int *len)
{
	if (num >= 0)
		*len += _putchar('+');
	print_numbers(num, len);
}

/**
 * print_space - print a space before a number if it is positive
 * @num: the number to print
 * @len: pointer to the lenght counter
 */

void print_space(int num, int *len)
{
	if (num >= 0)
		*len += _putchar(' ');
	print_numbers(num, len);
}

/**
 * print_prefix - print a prefix before the number if it's non-zero
 * @num: the number to print
 * @c: the conversion specifier
 * @len: pointer to the length counter
 */
void print_prefix(int num, char c, int *len)
{
	if (num != 0)
	{
		if (c == 'o')
			*len += _putchar('0');
		else if (c == 'x' || 'X')
			*len += _putstr("0x");
	}
	if (c == 'o')
		print_octal_number(num, len);
	else
	print_hex_number(num, c, len);
}
