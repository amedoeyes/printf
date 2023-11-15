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
	int len = strlen(buf);
	int pre_len = 0;
	int precision = getPrecision();
	int i;

	if (getFlags()->dot && precision == 0 && number == 0)
		return (0);
	if (getFlags()->hash && buf[0] != '0')
		pre_len++;
	if (!getFlags()->minus &&
		((((int)strlen(buf) - precision) + precision) < precision))
		len += printWidth(pre_len + precision);
	else if (!getFlags()->minus)
		len += printWidth(pre_len + (strlen(buf) - precision) + precision);
	if (getFlags()->hash && buf[0] != '0')
		writeBuf('0');
	if (precision > 0)
		len += printZeros(strlen(buf), precision);
	else
		len += printZeros(pre_len + strlen(buf), getZeros());
	for (i = 0; i < (int)strlen(buf); i++)
		writeBuf(buf[i]);
	len += pre_len;
	if (getFlags()->minus)
		len += printWidth(len);
	free(buf);
	return (len);
}
