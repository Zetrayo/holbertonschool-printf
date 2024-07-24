#include "main.h"

/**
 * flush_buffer - Writes the buffer contents using _putchar
 * @buffer: The buffer to flush
 * @buffer_index: Pointer to the buffer index
 * Return: Number of characters written
 */
int flush_buffer(char *buffer, int *buffer_index)
{
	int count;

	write(1, buffer, *buffer_index);
	count = *buffer_index;
	*buffer_index = 0;
	return (count);
}

/**
 * _printf - Produces output according to a format
 * @format: Character string containing zero or more directives
 * Return: Number of characters printed (excluding null byte)
 */
int _printf(const char *format, ...)
{
	va_list args;
	int i = 0, count = 0, buffer_index = 0;
	char buffer[BUFFER_SIZE];
	format_t formats[] = {
		{'c', print_char},
		{'s', print_string},
		{'d', print_int},
		{'i', print_int},
		{'R', print_rot13string},
		{0, NULL}
	};

	if (!format)
		return (-1);
	va_start(args, format);
	while (format[i])
	{
		if (format[i] != '%')
		{
			buffer[buffer_index++] = format[i];
			count++;
			if (buffer_index == BUFFER_SIZE)
				flush_buffer(buffer, &buffer_index);
		}
		else if (format[++i])
			count += handle_format(format[i], formats, args, buffer, &buffer_index);
		i++;
	}
	if (buffer_index > 0)
		flush_buffer(buffer, &buffer_index);
	va_end(args);
	return (count);
}

/**
 * handle_format - Handles formatting for _printf
 * @spec: Format specifier
 * @formats: Array of format structs
 * @args: List of arguments
 * @buffer: Buffer for output
 * @buffer_index: Current index in buffer
 * Return: Number of characters handled
 */
int handle_format(char spec, format_t *formats, va_list args,
				char *buffer, int *buffer_index)
{
	int j;

	if (spec == '%')
	{
		buffer[(*buffer_index)++] = '%';
		return (1);
	}

	for (j = 0; formats[j].spec != 0; j++)
		if (spec == formats[j].spec)
			return (formats[j].f(args, buffer, buffer_index));

	buffer[(*buffer_index)++] = '%';
	buffer[(*buffer_index)++] = spec;
	return (2);
}

#include "main.h"

/**
* _putchar - Entry point
*
* @c: character to print
* Return: Always 0 (Success)
*/
int _putchar(char c)
{
	write(1, &c, 1);
	return (0);
}
