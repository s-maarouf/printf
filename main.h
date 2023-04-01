#ifndef main_h
#define main_h

#include <unistd.h>
#include <stdlib.h>
#include <stdarg.h>
#include <string.h>
#include <stdio.h>

#define BUFFER_SIZE 1024

/**
* struct convert - defines a structure for symbols and functions

*
* @sym: The operator
* @f: The function associated
*/
struct convert
{
	char *sym;
	int (*f)(va_list);
};
typedef struct convert conver_t;

int _printf(const char *format, ...);
int _print_char(va_list list);
int _print_str(va_list list);
int print_percent(__attribute__((unused))va_list list);
int print_integer(va_list list);
int unsigned_integer(va_list list);
int print_binary(va_list list);
int print_hex(va_list list);
int print_heX(va_list list);
int print_octal(va_list list);
int print_pointer(va_list list);
int print_reversed(va_list arg);
int rot13(va_list list);
int print_S(va_list list);



int _putchar(char c);
void _puts(char *str);
char *rev_string(char *s);
unsigned int base_len(unsigned int num, int base);
int parser(const char *format, conver_t f_list[], va_list arg_list);
int print_unsgined_number(unsigned int n);
int print_number(va_list args);
int hex_check(int num, char x);
char *rev_string(char *s);
int _putchar_buff(char c);

#endif
