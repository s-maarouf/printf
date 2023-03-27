#include "main.h"

/**
 * print_binary - converts an unsigned int to binary and prints it
 * @list: arguments list containing the unsigned int to be converted
 *
 * Return: number of characters printed
 */
int print_binary(va_list list)
{
	unsigned int num = va_arg(list, unsigned int);
	int count = 0;
	unsigned int temp;

	if (num == 0)
		return (_putchar('0'));

	temp = num;
	while (temp > 0)
	{
		count++;
		temp >>= 1;
	}

	while (count--)
	{
		char c = (num & (1 << count)) ? '1' : '0';

		_putchar(c);
	}

	return (count);
}
