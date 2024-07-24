#include "main.h"
/**
 * print_rot13string - Print a string in ROT13
 * @args: List of arguments
 * @buffer: Buffer array to handle print
 * @buffer_index: Index at which to add next char, represents the length
 *
 * Return: Number of chars printed
 */
int print_rot13string(va_list args, char *buffer, int *buffer_index)
{
	char *str;
	unsigned int i, j;
	int count = 0;
	char in[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz";
	char out[] = "NOPQRSTUVWXYZABCDEFGHIJKLMnopqrstuvwxyzabcdefghijklm";

	str = va_arg(args, char *);
	if (str == NULL)
		str = "(AHYY)";

	for (i = 0; str[i]; i++)
	{
		for (j = 0; in[j]; j++)
		{
			if (in[j] == str[i])
			{
				buffer[*buffer_index] = out[j];
				(*buffer_index)++;
				count++;
				if (*buffer_index == BUFFER_SIZE)
					count += flush_buffer(buffer, buffer_index);
				break;
			}
		}
		if (!in[j])
		{
			buffer[*buffer_index] = str[i];
			(*buffer_index)++;
			count++;
			if (*buffer_index == BUFFER_SIZE)
				count += flush_buffer(buffer, buffer_index);
		}
	}

	return (count);
}
