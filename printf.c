#include "main.h"

/**
 * _printf - main function
 * Description: 'prints what is passed to it.'
 *
 * Return: 0 (Success)
 */

int _printf(const char *format, ...)
{
	int i = 0, j;
	va_list arg;

	va_start(arg, format);
	while (format && format[i])
	{
		j = 0;
		if (format[i] == '%')
		{
			i++;
			if (format[i] == '%')
			{
				_putchar('%');
			}
			while (types[j].conv != NULL)
			{
				if (format[i] == types[j].conv[0])
				{
					types[j].fonc(arg);
					j = 4;
				}
				j++;
			}
			if (j != 2)
			{
				_putchar('%');
			}
		}
		if (j != 5)
		{
			_putchar(format[i]);
		}
		i++;
	}
	va_end(arg);
}
