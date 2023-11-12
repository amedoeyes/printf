#include "main.h"

/**
 * printHex - prints a hex number
 *
 * @number: number to print
 * @upper: whether to use upper or lower case
 *
 * Return: number of bytes printed
 */

int printHex(unsigned int number, bool upper)
{
	char *buf = convertBase(number, 16, upper);
	int len = strlen(buf);

	printStr(buf);

	free(buf);

	return (len);
}
