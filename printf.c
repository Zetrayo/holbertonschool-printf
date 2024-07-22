#include <stdarg.h>
#include <stdio.h>
#include <unistd.h>
#include "main.h"

/**
 * _printf - main function
 * Description: 'prints what is passed to it.'
 *
 * Return: 0 (Success)
 */

int _printf(const unsigned int n, ...)
{
	unsigned int i = 0;
	char *chara;
	va_list a;

	va_start (a, n);
	chara = va_arg(a, char *);
	while (chara != '\0')
	{
		_putchar (chara[i]);
		i++;
	}
}
