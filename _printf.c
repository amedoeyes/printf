#include "main.h"

/**
 * handleSpecifier - handles specifiers
 *
 * @c: specifier
 * @ap: argument list
 *
 * Return: number of bytes printed
 */

int handleSpecifier(char c, va_list ap)
{
	switch (c)
	{
		case 'c':
			return (_putchar(va_arg(ap, int)));
		case 's':
			return (printStr(va_arg(ap, char *)));
		case '%':
			return (_putchar('%'));
		case 'd':
		case 'i':
			return (printInt(va_arg(ap, int)));
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

			if (!*format)
				break;

			len += handleSpecifier(*format, ap);
		}
		else
		{
			len += _putchar(*format);
		}

		format++;
	}

	va_end(ap);

	return (len);
}
