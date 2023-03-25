#ifndef main_h
#define main_h

#include <unistd.h>
#include <stdlib.h>
#include <stdarg.h>

int _printf(const char *format, ...);
int _print_percent(void);
int _print_char(char c);
int _print_str(const char *s);
int _print_num(int n);
int _putchar(char c);

#endif
