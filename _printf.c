#include "main.h"
#include <stdarg.h>
#include <stddef.h>

/**
 * handleInvalidSpecifier - handles invalid specifiers
 *
 * @c: specifier
 *
 * Return: number of bytes printed
 */

int handleInvalidSpecifier(char c)
{
	int len = 0;

	len += _putchar('%');
	len += _putchar(c);

	return (len);
}

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
		default:
			return (handleInvalidSpecifier(c));
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
	size_t len = 0;

	va_start(ap, format);

	while (format && *format)
	{
		if (*format == '%')
		{
			format++;

			if (!*format)
				break;

			len += handleSpecifier(*format, ap);

			format++;
		}
		else
		{
			len += _putchar(*format);
			format++;
		}
	}

	va_end(ap);

	return (len);
}
