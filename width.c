#include "main.h"

static int width;

/**
 * handleWidth - handles width
 *
 * @format: format string
 * @ap: argument list
 */

void handleWidth(const char **format, va_list *ap)
{
	width = 0;

	while (isdigit(**format))
	{
		width = width * 10 + (**format - '0');
		(*format)++;
	}

	if (**format == '*')
	{
		width = va_arg(*ap, int);
		(*format)++;
	}
}

/**
 * printWidth - prints width to standard output
 *
 * @currentLen: current length
 *
 * Return: number of bytes printed
 */

int printWidth(int currentLen)
{
	int i;
	int len = 0;

	for (i = 0; i < width - currentLen; i++)
		len += writeBuf(' ');

	return (len);
}
