#include "main.h"

/**
 * handleSpecifiers - handles specifiers
 *
 * @c: specifier
 * @ap: argument list
 *
 * Return: number of bytes printed
 */

int handleSpecifiers(char c, va_list ap)
{
	switch (c)
	{
		case 'c':
			return (printChar(va_arg(ap, int)));
		case 's':
			return (printStr(va_arg(ap, char *)));
		case '%':
			return (printChar('%'));
		case 'd':
		case 'i':
			return (printInt(va_arg(ap, int)));
		case 'b':
			return (printBin(va_arg(ap, unsigned int)));
		case 'o':
			return (printOct(va_arg(ap, unsigned int)));
		case 'u':
			return (printUInt(va_arg(ap, int)));
		case 'x':
			return (printHex(va_arg(ap, unsigned int), false));
		case 'X':
			return (printHex(va_arg(ap, unsigned int), true));
		case 'S':
			return (printStrNP(va_arg(ap, char *)));
		default:
			return (printInvalid(c));
	}
}

/**
 * _printf - prints a formatted string to standard output
 *
 * @format: format string
 *
 * Return: number of bytes printed
 */

int _printf(const char *format, ...)
{
	va_list ap;
	int len = 0;

	if (!format || (format[0] == '%' && !format[1]))
		return (-1);

	va_start(ap, format);

	while (*format)
	{
		if (*format == '%')
		{
			format++;

			len += handleSpecifiers(*format, ap);
		}
		else
		{
			len += printChar(*format);
		}

		format++;
	}

	va_end(ap);
	flushBuf();

	return (len);
}
