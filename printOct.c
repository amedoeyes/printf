#include "main.h"

/**
 * printOct - prints an octal number
 *
 * @number: number to print
 *
 * Return: number of bytes printed
 */

int printOct(unsigned int number)
{
	char *buf = convertBase(number, 8, false);
	int len = 0;
	struct Flags *flags = getFlags();

	if (flags->hash && buf[0] != '0')
		len += printChar('0');

	len += printStr(buf);

	free(buf);

	return (len);
}
