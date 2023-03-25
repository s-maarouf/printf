#include "main.h"

/**
 * _putchar - is a function that prints character
 *
 * @c: input character to print
 *
 * Return: character to print
 */

int _putchar(char c)
{
	return (write(1, &c, 1));
}
