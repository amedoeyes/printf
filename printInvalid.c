#include "main.h"

/**
 * printInvalid - prints invalid specifiers
 *
 * @c: specifier
 *
 * Return: number of bytes printed
 */

int printInvalid(char c)
{
	int len = 0;

	len += writeBuf('%');
	len += writeBuf(c);

	return (len);
}
