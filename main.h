#include <stdarg.h>
#include <stdio.h>
#include <unistd.h>

#ifndef MAIN_H_
#define MAIN_H_

#define BUFFER_SIZE 1024

int _strlen(char *a);
int _putchar(char c);
void print_int(va_list arg);
void print_intbase10(va_list arg);
void print_char(va_list arg);
void print_str(va_list arg);
int _printf(const char *format, ...);

typedef struct format
{
	char *conv;
	void (*fonc)(va_list, char buffer, int buffer_count);
} format_t;

format_t specifier[] = {
	{"c", print_char},
	{"d", print_int},
	{"s", print_str},
	{"i", print_intbase10},
	{NULL, NULL}
};

#endif
