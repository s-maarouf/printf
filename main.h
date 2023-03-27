#ifndef main_h
#define main_h

#include <unistd.h>
#include <stdlib.h>
#include <stdarg.h>

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
int print_percent(__attribute__((unused))va_list list);
int _print_char(va_list list);
int _print_str(va_list list);
int print_integer(va_list list);
int unsigned_integer(va_list list);
int _putchar(char c);
int parser(const char *format, conver_t f_list[], va_list arg_list);


int print_unsgined_number(unsigned int n);
int print_number(va_list args);

#endif
