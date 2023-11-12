#include "main.h"
#include <string.h>

/**
 * printStr - prints string to the standard output
 *
 * @str: the string to print
 *
 * Return: number of bytes printed
 */

int printStr(const char *str)
{
	int len = strlen(str);
	int i;

	if (!str)
		str = "(null)";

	for (i = 0; i < len; i++)
		_putchar(str[i]);

	return (len);
}
