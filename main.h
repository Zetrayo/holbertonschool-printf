#include <stdarg.h>
#include <stdio.h>
#include <unistd.h>

#ifndef MAIN_H_
#define MAIN_H_

int _strlen(char *a);
int _putchar(char c);
void print_int(va_list arg);
void print_intbase10(va_list arg);
void print_char(va_list arg);
void print_percent(va_list arg);
void print_str(va_list arg);
int _printf(const char *format, ...);

typedef struct pter
{
	char *conv;
	void (*fonc)();
} pt;

#endif