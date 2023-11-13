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
	int len = 0;
	struct Flags *flags = getFlags();

	if (flags->hash && buf[0] != '0')
		len += printStr(upper ? "0X" : "0x");

	len += printStr(buf);

	free(buf);

	return (len);
}
