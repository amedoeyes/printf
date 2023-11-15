#include "main.h"

/**
 * printAddr - prints address of memory
 *
 * @address: memory address to print
 *
 * Return: number of bytes printed
 */

int printAddr(void *address)
{
	char *buf;
	int len;
	int pre_len = 0;
	int precision = getPrecision();
	int i;

	if (!address && getFlags()->dot)
	{
		buf = "(nil)";
		len = 5;
		while (*buf)
			writeBuf(*buf++);
		return (len);
	}
	if (!address)
		return (printStr("(nil)"));

	buf = convertBase((unsigned long)address, 16, false);
	len = strlen(buf);
	pre_len += 2;
	if (!getFlags()->minus &&
		((((int)strlen(buf) - precision) + precision) < precision))
		len += printWidth(pre_len + precision);
	else if (!getFlags()->minus)
		len += printWidth(pre_len + (strlen(buf) - precision) + precision);
	writeBuf('0');
	writeBuf('x');
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
