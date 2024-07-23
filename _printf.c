#include "main.h"

/**
 * _printf - main function
 * Description: 'prints what is passed to it.'
 *@format: string to be processed
 * Return: 0 (Success)
 */

int _printf(const char *format, ...)
{
	int buffer_count = 0, specifier_count = 0, count = 0;
	char buffer[BUFFER_SIZE];
	va_list arg;

	va_start(arg, format);
	while (format[buffer_count])
	{
		if (format[buffer_count] != '%')
		{
			buffer[buffer_count] = format[buffer_count];
		}
		else if (format[buffer_count] == '%')
		{
			buffer_count++;
			if (format[buffer_count] != '%')
			{
				while (specifier[specifier_count].conv != NULL)
				{
					if (format[buffer_count] == specifier[specifier_count].conv[0])
					{
						buffer_count--;
						specifier[specifier_count].fonc(arg, buffer, buffer_count);
						buffer_count++;
					}
					specifier_count++;
				}
				specifier_count = 0; /* gerer error for %m */
			}
			else if (format[buffer_count] == '%')
			{
				buffer_count--;
				buffer[buffer_count] = '%';
				buffer_count++;
			}
			count = count + buffer_count;
		}
		buffer_count++;
	}
	va_end(arg);
}
