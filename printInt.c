#include "main.h"

/**
 * printInt - prints an integer
 *
 * @number: the integer to print
 *
 * Return: number of bytes printed
 */

int printInt(int number)
{
	unsigned int absNum = number < 0 ? -number : number;
	char *buf = convertBase(absNum, 10, false);
	int len = 0;

	if (number < 0)
		len += printChar('-');

	len += printStr(buf);

	free(buf);

	return (len);
}
