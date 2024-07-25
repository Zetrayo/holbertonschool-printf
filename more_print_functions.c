#include "main.h"

/**
 * print_octal - Prints an integer
 * @args: List of arguments
 * @buffer: Buffer array to handle print
 * @buffer_index: Index at which to add next char, represents the length
 *
 * Return: Number of chars printed
 */
int print_octal(va_list args, char *buffer, int *buffer_index)
{
	unsigned int n = va_arg(args, int);
	int count = 0, i = 0, num = 0;
	char octal[BUFFER_SIZE];

	while (n > 0)
	{
		num = n % 8;
		n = n / 8;
		octal[i] = num + '0';
		i++;
	}
	while (i > 0)
	{
		i--;
		buffer[(*buffer_index)++] = octal[i];
		count++;
		if (*buffer_index == BUFFER_SIZE)
		{
			flush_buffer(buffer, buffer_index);
		}
	}
	return (count);
}

/**
 * %o print a number in octal (base 8)
 * %u print an unsigned decimal (base 10) number
 * %x print a number in hexidecimal (base 16) , letters in lowercase
 * %X print a number in hexidecimal (base 16) , letters in uppercase
 */
