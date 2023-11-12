#include "main.h"

/**
 * printStr - prints string to the standard output
 *
 * @str: the string to print
 *
 * Return: number of bytes printed
 */

int printStr(const char *str)
{
	int len;
	int i;

	if (!str)
		str = "(null)";

	len = strlen(str);

	for (i = 0; i < len; i++)
		_putchar(str[i]);

	return (len);
}
