#include <stdarg.h>
#include <stdio.h>
#include <unistd.h>

#ifndef MAIN_H_
#define MAIN_H_

int _strlen(char *a);
int _putchar(char c);
void print_d(va_list arg);
void print_i(va_list arg);
void print_c(va_list arg);
void print_pour(va_list arg);
void print_s(va_list arg);
int _printf(const char *format, ...);

typedef struct format
{
	char *conv;
	void (*fonc)();
} format_t;

format_t types[] = {
	{"c", print_c},
	{"d", print_d},
	{"%", print_pour},
	{"s", print_s},
	{"i", print_i},
	{NULL, NULL}
};

#endif
