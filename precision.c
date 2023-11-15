#include "main.h"

static int precision;

/**
 * handlePrecision - handles precision
 *
 * @format: format string
 * @ap: argument list
 */

void handlePrecision(const char **format, va_list *ap)
{
	if (**format != '.')
		return;

	precision = 0;
	getFlags()->dot = true;
	(*format)++;

	while (isdigit(**format))
	{
		precision = precision * 10 + (**format - '0');
		(*format)++;
	}

	if (**format == '*')
	{
		precision = va_arg(*ap, int);
		(*format)++;
	}
}

/**
 * getPrecision - gets precision
 *
 * Return: precision
 */

int getPrecision(void)
{
	return (precision);
}
