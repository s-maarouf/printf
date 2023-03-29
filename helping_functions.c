#include "main.h"

/**
 * rev_string - reverses a string in place
 *
 * @s: string to reverse
 * Return: A pointer to a character
 */
char *rev_string(char *s)
{
	int len;
	int head;
	char tmp;
	char *dest;

	for (len = 0; s[len] != '\0'; len++)
	{
	}

	dest = malloc(sizeof(char) * len + 1);
	if (dest == NULL)
		return (NULL);

	memcpy(dest, s, len);
	for (head = 0; head < len; head++, len--)
	{
		tmp = dest[len - 1];
		dest[len - 1] = dest[head];
		dest[head] = tmp;
	}
	return (dest);
}

/**
 * base_len - Calculates the length for an octal number
 *
 * @num: The number for which the length is being calculated
 * @base: Base to be calculated by
 *
 * Return: An integer representing the length of a number
 */
unsigned int base_len(unsigned int num, int base)
{
	unsigned int i;

	for (i = 0; num > 0; i++)
	{
		num = num / base;
	}
	return (i);
}

/**
 * print_pointer - prints a pointer's memory address in hexadecimal notation
 * @list: argument list containing the pointer to be printed
 *
 * Return: number of characters printed
 */
int print_pointer(va_list list)
{
	void *ptr = va_arg(list, void *);
	char buffer[1024];
	int count;

	count = sprintf(buffer, "%p", ptr);
	write(1, buffer, count);
	return (count);
}

/**
 * print_reversed - Calls a function to reverse and print a string
 * @arg: Argument passed to the function
 * Return: The amount of characters printed
 */
int print_reversed(va_list arg)
{
	int len;
	char *str;
	char *ptr;

	str = va_arg(arg, char *);
	if (str == NULL)
		return (-1);
	ptr = rev_string(str);
	if (ptr == NULL)
		return (-1);
	for (len = 0; ptr[len] != '\0'; len++)
		_putchar(ptr[len]);
	free(ptr);
	return (len);
}
