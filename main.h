#ifndef MAIN_H_
#define MAIN_H_
#include <stdarg.h>
#include <stdio.h>
#include <unistd.h>

#define BUFFER_SIZE 1024

int _putchar(char c);
int print_int(va_list arg, char *buffer, int *buffer_count);
int print_number(va_list arg, char *buffer, int *buffer_count);
int print_char(va_list arg, char *buffer, int *buffer_count);
int print_str(va_list arg, char *buffer, int *buffer_count);
int _printf(const char *format, ...);

typedef struct format
{
	char *conv;
	void (*fonc)(va_list, char *buffer, int *buffer_count);
} format_t;

format_t specifier[] = {
	{"c", print_char},
	{"d", print_int},
	{"s", print_str},
	{"i", print_number},
	{NULL, NULL}
};

#endif
