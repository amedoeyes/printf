#include "main.h"

/**
 * printStrNP - prints string and print non-printable characters in hex to the
 * standard output
 *
 * @str: the string to print
 *
 * Return: number of bytes printed
 */

int printStrNP(const char *str)
{
	int len = 0;
	int i;

	if (!str)
		str = "(null)";

	for (i = 0; i < (int)strlen(str); i++)
	{
		if (!isprint(str[i]))
		{
			char *buf = convertBase(str[i], 16, true);

			len += printStr("\\x");

			if (strlen(buf) == 1)
				len += writeBuf('0');

			len += printStr(buf);
			free(buf);
		}
		else
		{
			len += writeBuf(str[i]);
		}
	}

	return (len);
}
