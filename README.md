# PRINTF

## About this project:
This is a project to be done in a group of two people.<br>
The goal is to reproduce the same behaviour of `printf` and handle all kind of formats.<br>
There should be one project repository per group. The other members do not fork or clone the project to ensure only one of the team has the repository in their github account otherwise you risk scoring 0%
<br>

## Authorized functions and macros:
```
write
malloc
free
va_start
va_end
va_copy
va_arg
```
<br>

## Compilation:
The code is compiled this way:
```sh
$ gcc -Wall -Werror -Wextra -pedantic -std=gnu89 *.c
```

Example of test file that you could use:
```sh
alex@ubuntu:~/c/printf$ cat main.c
```
```c
#include <limits.h>
#include <stdio.h>
#include "main.h"

/**
 * main - Entry point
 *
 * Return: Always 0
 */
int main(void)
{
    int len;
    int len2;
    unsigned int ui;
    void *addr;

    len = _printf("Let's try to printf a simple sentence.\n");
    len2 = printf("Let's try to printf a simple sentence.\n");
    ui = (unsigned int)INT_MAX + 1024;
    addr = (void *)0x7ffe637541f0;
    _printf("Length:[%d, %i]\n", len, len);
    printf("Length:[%d, %i]\n", len2, len2);
    _printf("Negative:[%d]\n", -762534);
    printf("Negative:[%d]\n", -762534);
    _printf("Unsigned:[%u]\n", ui);
    printf("Unsigned:[%u]\n", ui);
    _printf("Unsigned octal:[%o]\n", ui);
    printf("Unsigned octal:[%o]\n", ui);
    _printf("Unsigned hexadecimal:[%x, %X]\n", ui, ui);
    printf("Unsigned hexadecimal:[%x, %X]\n", ui, ui);
    _printf("Character:[%c]\n", 'H');
    printf("Character:[%c]\n", 'H');
    _printf("String:[%s]\n", "I am a string !");
    printf("String:[%s]\n", "I am a string !");
    _printf("Address:[%p]\n", addr);
    printf("Address:[%p]\n", addr);
    len = _printf("Percent:[%%]\n");
    len2 = printf("Percent:[%%]\n");
    _printf("Len:[%d]\n", len);
    printf("Len:[%d]\n", len2);
    _printf("Unknown:[%r]\n");
    printf("Unknown:[%r]\n");
    return (0);
}
```
```sh
alex@ubuntu:~/c/printf$ gcc -Wall -Wextra -Werror -pedantic -std=gnu89 -Wno-format *.c
alex@ubuntu:~/c/printf$ ./printf
Let's try to printf a simple sentence.
Let's try to printf a simple sentence.
Length:[39, 39]
Length:[39, 39]
Negative:[-762534]
Negative:[-762534]
Unsigned:[2147484671]
Unsigned:[2147484671]
Unsigned octal:[20000001777]
Unsigned octal:[20000001777]
Unsigned hexadecimal:[800003ff, 800003FF]
Unsigned hexadecimal:[800003ff, 800003FF]
Character:[H]
Character:[H]
String:[I am a string !]
String:[I am a string !]
Address:[0x7ffe637541f0]
Address:[0x7ffe637541f0]
Percent:[%]
Percent:[%]
Len:[12]
Len:[12]
Unknown:[%r]
Unknown:[%r]
alex@ubuntu:~/c/printf$
```
<br>

## Tasks:

### 0) I'm not going anywhere. You can print that wherever you want to. I'm here and I'm a Spur for life

Write a function that produces output according to a format.
* Prototype: `int _printf(const char *format, ...);`
* Returns: the number of characters printed (excluding the null byte used to end output to strings)
* write output to stdout, the standard output stream
* `format` is a character string. The format string is composed of zero or more directives.
* You need to handle the following conversion specifiers:
	* `c`
	* `s`
	* `%`
* You don’t have to reproduce the buffer handling of the C library printf function.
* You don’t have to handle the flag characters/field width/precision/length modifiers.
<br>

### 1) Education is when you read the fine print. Experience is what you get if you don't

Handle the following conversion specifiers:
* `d`
* `i`
* You don’t have to handle the flag characters/field width/precision/length modifiers.
<br>

### 2) With a face like mine, I do better in print

Handle the following custom conversion specifiers:
* `b`: the unsigned int argument is converted to binary

```sh
alex@ubuntu:~/c/printf$ cat main.c
```
```c
#include "main.h"

/**
 * main - Entry point
 *
 * Return: Always 0
 */
int main(void)
{
    _printf("%b\n", 98);
    return (0);
}
```
```sh
alex@ubuntu:~/c/printf$ gcc -Wall -Wextra -Werror -pedantic -std=gnu89 main.c
alex@ubuntu:~/c/printf$ ./a.out
1100010
alex@ubuntu:~/c/printf$
```
<br>

### 3) What one has not experienced, one will never understand in print

Handle the following conversion specifiers:
* `u`
* `o`
* `x`
* `X`
* You don’t have to handle the flag characters/field width/precision/length modifiers.
<br>

### 4) Nothing in fine print is ever good news

Use a local buffer of 1024 chars in order to call `write` as little as possible.
<br>

### 5) My weakness is wearing too much leopard print

Handle the following custom conversion specifier:
* `S`: prints the string.
* Non printable characters (0 < ASCII value < 32 or >= 127) are printed this way: `\x`, followed by the ASCII code value in hexadecimal (upper case - always 2 characters)
```sh
alex@ubuntu:~/c/printf$ cat main.c
```
```c
#include "main.h"

/**
 * main - Entry point
 *
 * Return: Always 0
 */
int main(void)
{
    _printf("%S\n", "Best\nSchool");
    return (0);
}
```
```sh
alex@ubuntu:~/c/printf$ gcc -Wall -Wextra -Werror -pedantic -std=gnu89 main.c
alex@ubuntu:~/c/printf$ ./a.out
Best\x0ASchool
alex@ubuntu:~/c/printf$
```
<br>

### 6) How is the world ruled and led to war? Diplomats lie to journalists and believe these lies when they see them in print

Handle the following conversion specifier:
* `p`.
* You don’t have to handle the flag characters/field width/precision/length modifiers.
<br>

### 7) The big print gives and the small print takes away

Handle the following flag characters for non-custom conversion specifiers:
* `+`
* space
* `#`
<br>

### 8) Sarcasm is lost in print

Handle the following length modifiers for non-custom conversion specifiers:
* `l`
* `h`
Conversion specifiers to handle: `d`, `i`, `u`, `o`, `x`, `X`
<br>

### 9) Print some money and give it to us for the rain forests

Handle the field width for non-custom conversion specifiers.
<br>

### 10) The negative is the equivalent of the composer's score, and the print the performance

Handle the precision for non-custom conversion specifiers.
<br>

### 11) It's depressing when you're still around and your albums are out of print

Handle the `0` flag character for non-custom conversion specifiers.
<br>

### 12) Every time that I wanted to give up, if I saw an interesting textile, print what ever, suddenly I would see a collection

Handle the `-` flag character for non-custom conversion specifiers.
<br>

### 13) Print is the sharpest and the strongest weapon of our party

Handle the following custom conversion specifier:
* `r`: prints the reversed string
<br>

### 14) The flood of print has turned reading into a process of gulping rather than savoring

Handle the following custom conversion specifier:
* `R`: prints the rot13'ed string
<br>

### 15) *

All the above options work well together.
<br>
<br>
<br>
<br>

## Author's notes:

This project was made by [@s-maarouf](https://github.com/s-maarouf) and [@oyindoubra](https://github.com/oyindoubra)

**The project is not 100% complete we couldn't handle everything!**

Here are the completed tasks:
- ** [0](https://github.com/s-maarouf/printf#0-im-not-going-anywhere-you-can-print-that-wherever-you-want-to-im-here-and-im-a-spur-for-life), [1](https://github.com/s-maarouf/printf#1-education-is-when-you-read-the-fine-print-experience-is-what-you-get-if-you-dont), [2](https://github.com/s-maarouf/printf#2-with-a-face-like-mine-i-do-better-in-print), [3](https://github.com/s-maarouf/printf#3-what-one-has-not-experienced-one-will-never-understand-in-print), [4](https://github.com/s-maarouf/printf#4-nothing-in-fine-print-is-ever-good-news), [5](https://github.com/s-maarouf/printf#5-my-weakness-is-wearing-too-much-leopard-print), [6](https://github.com/s-maarouf/printf#6-how-is-the-world-ruled-and-led-to-war-diplomats-lie-to-journalists-and-believe-these-lies-when-they-see-them-in-print), [13](https://github.com/s-maarouf/printf#13-print-is-the-sharpest-and-the-strongest-weapon-of-our-party), [14](https://github.com/s-maarouf/printf#14-the-flood-of-print-has-turned-reading-into-a-process-of-gulping-rather-than-savoring) **
