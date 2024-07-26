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
	unsigned int n = va_arg(args, unsigned int);
	unsigned int mask = 1U << 31;
	int started = 0;
	int count = 0;

	if (n == 0)
	{
		buffer[(*buffer_index)++] = '0';
		return (1);
	}

	while (mask > 0)
	{
		if (n & mask)
		{
			buffer[(*buffer_index)++] = '1';
			started = 1;
			count++;
		}
		else if (started)
		{
			buffer[(*buffer_index)++] = '0';
			count++;
		}

		if (*buffer_index == BUFFER_SIZE)
			count += flush_buffer(buffer, buffer_index);

		mask >>= 1;
	}

	return (count);
}

/**
 * print_address - Prints a memory address
 * @args: List of arguments
 * @buffer: Buffer array to handle print
 * @buffer_index: Index at which to add next char, represents the length
 *
 * Return: Number of characters printed
 */
int print_address(va_list args, char *buffer, int *buffer_index)
{
	void *addr = va_arg(args, void*);
	unsigned long int n = (unsigned long int)addr;
	int count = 0;

	if (addr == NULL)
		return (print_nil(buffer, buffer_index));

	buffer[(*buffer_index)++] = '0';
	buffer[(*buffer_index)++] = 'x';
	count = 2;

	if (n == 0)
	{
		buffer[(*buffer_index)++] = '0';
		return (3);
	}

	count += print_hex_address(n, buffer, buffer_index);

	return (count);
}

/**
 * print_nil - Prints "(nil)" for NULL address
 * @buffer: Buffer array to handle print
 * @buffer_index: Index at which to add next char, represents the length
 *
 * Return: Number of characters printed
 */
int print_nil(char *buffer, int *buffer_index)
{
	char *nil_str = "(nil)";
	int count = 0;

	while (nil_str[count])
	{
		buffer[(*buffer_index)++] = nil_str[count];
		count++;
		if (*buffer_index == BUFFER_SIZE)
			count += flush_buffer(buffer, buffer_index);
	}
	return (count);
}

/**
 * print_hex_address - Prints hexadecimal representation of an address
 * @n: The address to print
 * @buffer: Buffer array to handle print
 * @buffer_index: Index at which to add next char, represents the length
 *
 * Return: Number of characters printed
 */
int print_hex_address(unsigned long int n, char *buffer, int *buffer_index)
{
	int count = 0, i = 0, j;
	char num_tab[BUFFER_SIZE];
	char *hex_digits = "0123456789abcdef";

	while (n > 0)
	{
		num_tab[i++] = hex_digits[n % 16];
		n /= 16;
	}

	for (j = i - 1; j >= 0; j--)
	{
		buffer[(*buffer_index)++] = num_tab[j];
		count++;
		if (*buffer_index == BUFFER_SIZE)
			count += flush_buffer(buffer, buffer_index);
	}

	return (count);
}
