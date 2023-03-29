#include "main.h"

/**
 * rot13 - Converts string to rot13
 * @list: string to convert
 * Return: converted string
 */
int rot13(va_list list)
{
	int i;
	int x;
	char *str;
	char s[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz";
	char u[] = "NOPQRSTUVWXYZABCDEFGHIJKLMnopqrstuvwxyzabcdefghijklm";

	str = va_arg(list, char *);
	if (str == NULL)
		return (-1);
	for (i = 0; str[i] != '\0'; i++)
	{
		for (x = 0; x <= 52; x++)
		{
			if (str[i] == s[x])
			{
				_putchar(u[x]);
				break;
			}
		}
		if (x == 53)
			_putchar(str[i]);
	}
	return (i);
}

/**
 * print_S - prints a string with non-printable characters in hex format
 * @list: arguments list containing the string to be printed
 *
 * Return: number of characters printed
 */
int print_S(va_list list)
{
	char *str = va_arg(list, char *);
	int count = 0;

	if (str == NULL)
		str = "(null)";

	while (*str)
	{
		if (*str < 32 || *str >= 127)
		{
			count += _putchar('\\');
			count += _putchar('x');
			count += _putchar('0');
			count += _putchar('0' + (*str / 16));
			count += _putchar('0' + (*str % 16));
		}
		else
		{
			count += _putchar(*str);
		}

		str++;
	}

	return (count);
}
