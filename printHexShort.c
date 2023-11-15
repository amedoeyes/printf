#include "main.h"

/**
 * printHexShort - prints a short hex number
 *
 * @number: number to print
 * @upper: whether to use upper or lower case
 *
 * Return: number of bytes printed
 */

int printHexShort(unsigned short number, bool upper)
{
	char *buf = convertBase(number, 16, upper);
	int len = 0;
	int pre_len = 0;
	int precision = getPrecision();
	int i;

	if (getFlags()->dot && precision == 0 && number == 0)
		return (0);
	if (getFlags()->hash && buf[0] != '0')
		pre_len += 2;

	if (!getFlags()->minus &&
		((((int)strlen(buf) - precision) + precision) < precision))
		len += printWidth(pre_len + precision);
	else if (!getFlags()->minus)
		len += printWidth(pre_len + (strlen(buf) - precision) + precision);

	if (getFlags()->hash && buf[0] != '0')
	{
		writeBuf('0');
		writeBuf(upper ? 'X' : 'x');
	}

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
