#include "main.h"
#include <stdlib.h>
#include <string.h>

/**
 * printInt - prints an integer
 *
 * @number: the integer to print
 *
 * Return: number of bytes printed
 */

int printInt(int number)
{
	int absNum = number < 0 ? -number : number;
	char *buf = convertBase(absNum, 10, false);
	int bufLen = strlen(buf);
	int len = 0;
	int i;

	if (number < 0)
		len += _putchar('-');

	for (i = 0; i <= bufLen; i++)
		len += _putchar(buf[i]);

	free(buf);

	return (len);
}
