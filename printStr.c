#include "main.h"

/**
 * printStr - prints string to the standard output
 *
 * @str: the string to print
 *
 * Return: number of bytes printed
 */

int printStr(const char *str)
{
	int len = 0;
	int precision = getPrecision();
	int i = 0;

	if (!str)
		str = "(null)";

	len = 0;

	if (!getFlags()->minus)
		len += printWidth(strlen(str));

	while (*str)
	{
		if (getFlags()->dot && i == precision)
			break;

		len += writeBuf(*str);
		str++;
		i++;
	}

	if (getFlags()->minus)
		len += printWidth(len);

	return (len);
}
