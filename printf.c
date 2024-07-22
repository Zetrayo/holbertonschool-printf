#include "main.h"

/**
 * _printf - main function
 * Description: 'prints what is passed to it.'
 *
 * Return: 0 (Success)
 */

int _printf(const char *format, ...)
{
	int i, j;
	va_list a;

	pt types[] = {
		{"c", print_c},
		{"d", print_d},
		{"%", print_pour},
		{"s", print_s},
		{NULL, NULL}
	};

	va_start(a, format);
	i = 0;
	while (format && format[i])
	{
		j = 0;
		while (types[j].conv != NULL)
		{
			if (format[i] == types[j].conv[0])
			{
				types[j].fonc(a);
			}
			j++;
		}
		i++;
	}
	va_end(a);
}
