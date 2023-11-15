#include "main.h"

/**
 * handleLong - handles long specifier
 *
 * @c: specifier
 * @ap: argument list
 *
 * Return: number of bytes printed
 */

int handleLong(char c, va_list ap)
{
	switch (c)
	{
		case 'd':
		case 'i':
			return (printIntLong(va_arg(ap, long)));
		case 'u':
			return (printUIntLong(va_arg(ap, long)));
		case 'o':
			return (printOctLong(va_arg(ap, long)));
		case 'x':
			return (printHexLong(va_arg(ap, long), false));
		case 'X':
			return (printHexLong(va_arg(ap, long), true));
		default:
			return (printInvalid(c));
	}
}

/**
 * handleShort - handles short specifier
 *
 * @c: specifier
 * @ap: argument list
 *
 * Return: number of bytes printed
 */

int handleShort(char c, va_list ap)
{
	switch (c)
	{
		case 'd':
		case 'i':
			return (printIntShort(va_arg(ap, int)));
		case 'u':
			return (printUIntShort(va_arg(ap, int)));
		case 'o':
			return (printOctShort(va_arg(ap, int)));
		case 'x':
			return (printHexShort(va_arg(ap, int), false));
		case 'X':
			return (printHexShort(va_arg(ap, int), true));
		default:
			return (printInvalid(c));
	}
}

/**
 * handleSpecifiers - handles specifiers
 *
 * @format: format pointer
 * @ap: argument list
 *
 * Return: number of bytes printed
 */

int handleSpecifiers(const char **format, va_list ap)
{
	switch (**format)
	{
		case 'c':
			return (printChar(va_arg(ap, int)));
		case 's':
			return (printStr(va_arg(ap, char *)));
		case '%':
			return (writeBuf('%'));
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
		case 'l':
			return (handleLong(*(++(*format)), ap));
		case 'h':
			return (handleShort(*(++(*format)), ap));
		case '\0':
			return (-1);
		default:
			return (printInvalid(**format));
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
			handleWidth(&format, &ap);
			handlePrecision(&format, &ap);
			result = handleSpecifiers(&format, ap);

			if (result == -1)
				return (-1);

			len += result;

			freeFlags();
		}
		else
			len += writeBuf(*format);

		format++;
	}

	va_end(ap);
	flushBuf();

	return (len);
}
