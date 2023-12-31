#include "main.h"
#include <stdlib.h>
#include <string.h>

#include "main.h"

/**
 * printBin - prints an binary number
 *
 * @number: number to print
 *
 * Return: number of bytes printed
 */

int printBin(unsigned int number)
{
	char *buf = convertBase(number, 2, false);
	int len = strlen(buf);
	int precision = getPrecision();
	int i;

	if (getFlags()->dot && precision == 0 && number == 0)
		return (0);
	if (!getFlags()->minus &&
		((((int)strlen(buf) - precision) + precision) < precision))
		len += printWidth(precision);
	else if (!getFlags()->minus)
		len += printWidth((strlen(buf) - precision) + precision);

	if (precision > 0)
		len += printZeros(strlen(buf), precision);
	else
		len += printZeros(strlen(buf), getZeros());

	for (i = 0; i < (int)strlen(buf); i++)
		writeBuf(buf[i]);

	if (getFlags()->minus)
		len += printWidth(len);

	free(buf);

	return (len);
}
