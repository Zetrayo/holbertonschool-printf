#include "main.h"
#include <unistd.h>

/**
 * _strlen - Entry point
 * Description: 'counts string lenght'
 *
 * @a: pointer pointing to string
 * Return: 0 (Success)
 */

int _strlen(char *a)
{
	int c = 0;

	while (*a != '\0')
	{
		c++;
		a++;
	}
	return (c);
}

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
