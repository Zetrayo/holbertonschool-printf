# _printf

_printf is a project for Holberton School which imitates the "printf()" function found in the "stdio.h" library.

_printf allows users to print a variety of characters and variables on their terminal.

## Project Tests

This project was tested using these compilation flags :
`gcc -Wall -Werror -Wextra -pedantic -std=gnu89 -Wno-format *.c`

This project was subjected to multiple tests using the main.c file which we included here:
```c
#include <limits.h>
#include <stdio.h>
#include "main.h"

/**
 * main - Entry point
 *
 * Return: Always 0
 */
int main(void)
{
	int len;
	int len2;
	unsigned int ui;
	void *addr;

	len = _printf("_printf : Let's try to printf a simple sentence.\n");
	len2 = printf("printf  : Let's try to printf a simple sentence.\n");
	ui = (unsigned int)INT_MAX + 1024;
	addr = (void *)0x7ffe637541f0;
	_printf("_printf : Length:[%d, %i]\n", len, len);
	printf("printf  : Length:[%d, %i]\n", len2, len2);
	_printf("_printf : Negative:[%d]\n", -762534);
	printf("printf  : Negative:[%d]\n", -762534);
	_printf("_printf : Unsigned:[%u]\n", ui);
	printf("printf  : Unsigned:[%u]\n", ui);
	_printf("_printf : Unsigned octal:[%o]\n", ui);
	printf("printf  : Unsigned octal:[%o]\n", ui);
	_printf("_printf : Unsigned hexadecimal:[%x, %X]\n", ui, ui);
	printf("printf  : Unsigned hexadecimal:[%x, %X]\n", ui, ui);
	_printf("_printf : Character:[%c]\n", 'H');
	printf("printf  : Character:[%c]\n", 'H');
	_printf("_printf : String:[%s]\n", "I am a string !");
	printf("printf  : String:[%s]\n", "I am a string !");
	_printf("_printf : Address:[%p]\n", addr);
	printf("printf  : Address:[%p]\n", addr);
	len = _printf("_printf : Percent:[%%]\n");
	len2 = printf("printf  : Percent:[%%]\n");
	_printf("_printf : Len:[%d]\n", len);
	printf("printf  : Len:[%d]\n", len2);
	_printf("_printf : Reverse string:[%r]\n", "Reverse string");
	_printf("_printf :  Unknown : [%z]\n");
	printf("printf  : Unknown:[%r]\n");

	return (0);
}
```

Output:
```c
_printf : Let's try to printf a simple sentence.
printf  : Let's try to printf a simple sentence.
_printf : Length:[49, 49]
printf  : Length:[49, 49]
_printf : Negative:[-762534]
printf  : Negative:[-762534]
_printf : Unsigned:[2147484671]
printf  : Unsigned:[2147484671]
_printf : Unsigned octal:[20000001777]
printf  : Unsigned octal:[20000001777]
_printf : Unsigned hexadecimal:[800003ff, 800003FF]
printf  : Unsigned hexadecimal:[800003ff, 800003FF]
_printf : Character:[H]
printf  : Character:[H]
_printf : String:[I am a string !]
printf  : String:[I am a string !]
_printf : Address:[0x7ffe637541f0]
printf  : Address:[0x7ffe637541f0]
_printf : Percent:[%]
printf  : Percent:[%]
_printf : Len:[22]
printf  : Len:[22]
_printf : Reverse string:[gnirts esreveR]
_printf :  Unknown : [%z]
printf  : Unknown:[%r]
```
## Man-page Installation

To install the man-page use the following commands :
```c
sudo mkdir /usr/local/man/man3
sudo install -g 0 -o 0 -m 0644 man_3_printf /usr/local/man/man3/_printf.3
sudo gzip /usr/local/man/man3/_printf.3
sudo mandb
```

Or if you dare to try : 
Simply execute `./compile_install.sh` which will compile all the c source files, install the man-page in your system and ask i you want to see it's content, if not, it will provide you the command to see it later.
(WARNING : you shall never execute a bash script from unkown sources, unless you've read the content of the bash script and know what it is meant to do !)

## Files

|File |Description |
|---------------------|------------------------------------------------------------------------------|
|main.h | Header file containing function prototypes and necessary includes |
|_printf.c | Main file containing functions to print regular characters and detect specifiers used |
|print_functions.c | File containing the different functions that allow _printf.c to print variables |
|more_print_functions.c | File containing additional functions that allow _printf.c to print variables |
|even_more_print_functions.c | File containing additional functions that allow _printf.c to print variables |
|man_3_printf | Text file containing information about _printf |
|Flowchart_printf.jpg | Image file containing a flowchart that showcases how _printf functions |


## Usage

For the function "_printf()" to work , the correct specifiers needs to be used.
The list of all current working specifiers is provided and updated here :

|Variable Type  |Specifier |
|---------------|----------|
|String |%s |
|Integer |%d |
|Character |%c |
|Integer base 10|%i |
|Percent symbol |%% |
|Rot13 |%R |
|unsigned int |%u |
|Integer base 8 |%o |
|integer base 16|%x & %X|
|Binary | %b|
|Reverse String | %r|
|Memory Address | %p|

When the function "_printf()" is succesful in printing the data sent to it, the return value is a count of all characters printed, else if it fails to print, the return value is -1.

## Examples

Basic single character example:
```c
char character = 'C';

_printf("I %c you", character);
```
Result :
`I C you`


Basic string example:
```c
char str_to_print[] = "world!";

_printf("Hello %s", str_to_print);
```
Result :
`Hello world!`


Basic integer example:
```c
int number = 404;

_printf("If you see %d, you are lost", number);
```
Result :
`If you see 404, you are lost`


Advanced example:
```c
int number = 0;
char str_to_print[] = "is a well rounded number";

_printf("The number %d %s", number, str_to_print);
```
Result :
`The number 0 is a well rounded number`


## Contributors

This project was made by : Fassih Belmokhtar and José Puertas

## Special Mention

# Holberton School

This project was made possible by Holberton School
