#include "main.h"

/**
 * printUInt - prints an unsigned integer
 *
 * @number: the integer to print
 *
 * Return: number of bytes printed
 */

int printUInt(unsigned int number)
{
	char *buf = convertBase(number, 10, false);
	int len = strlen(buf);

	printStr(buf);

	free(buf);

	return (len);
}
