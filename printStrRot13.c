#include "main.h"

/**
* printStrRot13 - prints string rot13 to the standard output
*
* @str: the string to print
*
* Return: number of bytes printed
*/

int printStrRot13(const char *str)
{
	int len = 0;

	if (!str)
		str = "(null)";

	while (*str)
	{
		int base;

		if (!isalpha(*str))
		{
			len += printChar(*str);
			str++;
			continue;
		}

		if (isupper(*str))
			base = 'A';
		else
			base = 'a';

		len += printChar((*str - base + 13) % 26 + base);
		str++;
	}

	return (len);
}
