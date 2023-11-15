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
	int pre_len = 0;
	int precision = getPrecision();
	int i;

	if (getFlags()->dot && precision == 0 && number == 0)
		return (0);
	if (number >= 0 && (getFlags()->space && !getFlags()->plus))
		pre_len++;
	if (number >= 0 && getFlags()->plus)
		pre_len++;
	if (number < 0)
		pre_len++;
	if (!getFlags()->minus &&
		((((int)strlen(buf) - precision) + precision) < precision))
		len += printWidth(pre_len + precision);
	else if (!getFlags()->minus)
		len += printWidth(pre_len + (strlen(buf) - precision) + precision);
	if (number >= 0 && (getFlags()->space && !getFlags()->plus))
		writeBuf(' ');
	if (number >= 0 && getFlags()->plus)
		writeBuf('+');
	if (number < 0)
		writeBuf('-');
	if (precision > 0)
		len += printZeros(strlen(buf), precision);
	else
		len += printZeros(pre_len + strlen(buf), getZeros());
	for (i = 0; i < (int)strlen(buf); i++)
		len += writeBuf(buf[i]);
	len += pre_len;
	if (getFlags()->minus)
		len += printWidth(len);
	free(buf);
	return (len);
}
