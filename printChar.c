#include "main.h"

/**
 * printChar - prints a character
 *
 * @c: the character to print
 *
 * Return: number of bytes printed
 */

int printChar(char c)
{
	int len = 0;

	if (!getFlags()->minus)
		len += printWidth(1);

	len += writeBuf(c);

	if (getFlags()->minus)
		len += printWidth(1);

	return (len);
}
