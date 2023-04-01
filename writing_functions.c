#include "main.h"

/**
 * _putchar - is a function that prints character
 *
 * @c: input character to print
 *
 * Return: character to print
 *

int _putchar(char c)
{
	return (write(1, &c, 1));
}


/**
 * _puts - is a function that prints a string
 *
 * @str: is the input string
 *
 */

void _puts(char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
	{
		write(1, &str[i], 1);
		i++;
	}
}
