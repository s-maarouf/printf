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

	for (; *str; str++)
	{
		if (*str < 32 || *str >= 127)
		{
			count += _putchar('\\');
			count += _putchar('x');
			count += _putchar(*str / 16 + (*str / 16 > 9 ? 'A' - 10 : '0'));
			count += _putchar(*str % 16 + (*str % 16 > 9 ? 'A' - 10 : '0'));
		}
		else
		{
			count += _putchar(*str);
		}
	}

	return (count);
}

/**
 * _putchar_buff - uses a local buffer of 1024 to call write
 * @c: character to print
 * Return: 1 on success. else return -1
 */

int _putchar_buff(char c)
{
	static char buff[1024];
	static int i;

	if (c == -1 || i >= 1024)
	{
		write(1, &buff, i);
		i = 0;
	}
	if (c != -1)
	{
		buff[i] = c;
		i++;
	}
	return (1);
}
