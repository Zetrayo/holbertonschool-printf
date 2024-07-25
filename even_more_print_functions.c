#include "main.h"

/**
 * print_binary - Prints an unsigned integer in binary format
 * @args: List of arguments
 * @buffer: Buffer array to handle print
 * @buffer_index: Index at which to add next char, represents the length
 *
 * Return: Number of chars printed
 */
int print_binary(va_list args, char *buffer, int *buffer_index)
{
	unsigned int n, m, i, sum;
	unsigned int a[32];
	int count = 0;

	n = va_arg(args, unsigned int);
	m = 2147483648; /* (2 ^ 31) */
	a[0] = n / m;
	for (i = 1; i < 32; i++)
	{
		m /= 2;
		a[i] = (n / m) % 2;
	}
	for (i = 0, sum = 0; i < 32; i++)
	{
		sum += a[i];
		if (sum || i == 31)
		{
			buffer[(*buffer_index)++] = '0' + a[i];
			count++;
			if (*buffer_index == BUFFER_SIZE)
			{
				count += flush_buffer(buffer, buffer_index);
			}
		}
	}
	return (count);
}
