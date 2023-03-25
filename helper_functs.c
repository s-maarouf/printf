#include "main.h"

/**
 * _print_percent - Prints a single percent character
 *
 * Return: Always returns 1
 */
int _print_percent(void)
{
	return (_putchar('%'));
}

/**
 * _print_char - Prints a single character
 * @c: The character to be printed
 *
 * Return: Always returns 1
 */
int _print_char(char c)
{
	write(1, &c, 1);
	return (1);
}

/**
 * _print_str - Prints a string of characters
 * @s: The string to be printed
 *
 * Return: The number of characters printed
 */
int _print_str(const char *s)
{
	int len = 0;

	while (s[len])
	{
		len++;
	}

	write(1, s, len);
	return (len);
}

/**
 * _print_num - Prints an integer
 * @nb: The integer to be printed
 *
 * Return: The number of characters printed
 */
int _print_num(int nb)
{
	if (nb == -2147483648)
	{
		_putchar('-');
		_putchar('2');
		_print_num(147483648);
	}
	else if (nb < 0)
	{
		_putchar('-');
		nb = -nb;
		_print_num(nb);
	}
	else if (nb > 9)
	{
		_print_num(nb / 10);
		_print_num(nb % 10);
	}
	else
		_putchar(nb + 48);

	return (nb);
}
