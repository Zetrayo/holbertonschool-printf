#include "main.h"

/**
 * print_int - Prints an integer
 * @args: List of arguments
 * @buffer: Buffer array to handle print
 * @buffer_index: Index at which to add next char, represents the length
 *
 * Return: Number of chars printed
 */
int print_int(va_list args, char *buffer, int *buffer_index)
{
	int n = va_arg(args, int);
	int count = 0;
	unsigned int num = (n < 0) ? -n : n;

	if (n < 0)
		buffer[(*buffer_index)++] = '-', count++;

	count += print_number(num, buffer, buffer_index);
	return (count);
}

/**
 * print_number - Recursively prints an unsigned integer
 * @n: Number to print
 * @buffer: Buffer array to handle print
 * @buffer_index: Index at which to add next char, represents the length
 *
 * Return: Number of digits printed
 */
int print_number(unsigned int n, char *buffer, int *buffer_index)
{
	int count = 0;

	if (n / 10)
		count += print_number(n / 10, buffer, buffer_index);

	buffer[(*buffer_index)++] = (n % 10) + '0';
	count++;
	if (*buffer_index == BUFFER_SIZE)
		flush_buffer(buffer, buffer_index);

	return (count);
}

/**
 * print_char - function to print chars
 * @arg: va_list type
 */
int print_char(va_list arg, char *buffer, int *buffer_index)
{
	buffer[(*buffer_index)++] = va_arg(arg, char*);
	return (1);
}

/**
 * print_str - function to print strings
 * @arg: va_list type
 */
int print_string(va_list arg,  char *buffer, int *buffer_index)
{
	int count = 0;
	char *str;

	str = va_arg(arg, char*);
	while (str[count] != '\0')
	{
	buffer[(*buffer_index)++] = str[count];
	count++;
	}
	return (count);
}
