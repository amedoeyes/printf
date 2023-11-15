#include "main.h"

/**
 * printStrRev - prints reverse of a string to the standard output
 *
 * @str: the string to print
 *
 * Return: number of bytes printed
 */

int printStrRev(const char *str)
{
	int len = strlen(str);

	int i;

	if (!str)
		str = "(null)";

	for (i = len - 1; i >= 0; i--)
		writeBuf(str[i]);

	return (len);
}
