#include "main.h"

/**
 * handleFlags - handles flags
 *
 * @format: format pointer
 */

void handleFlags(const char **format)
{
	struct Flags *flags = getFlags();

	while (**format)
	{
		switch (**format)
		{
			case '#':
				flags->hash = true;
				break;
			case '+':
				flags->plus = true;
				break;
			case ' ':
				flags->space = true;
				break;
			default:
				return;
		}

		(*format)++;
	}
}

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
		case 'p':
			return (printAddr(va_arg(ap, void *)));
		case 'r':
			return (printStrRev(va_arg(ap, char *)));
		case 'R':
			return (printStrRot13(va_arg(ap, char *)));
		case '\0':
			return (-1);
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

	if (!format)
		return (-1);

	va_start(ap, format);

	while (*format)
	{
		if (*format == '%')
		{
			int result;

			format++;
			initFlags();

			handleFlags(&format);
			result = handleSpecifiers(*format, ap);

			if (result == -1)
				return (-1);

			len += result;

			freeFlags();
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
