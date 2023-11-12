#include "main.h"

/**
 * convertBase - convert a number to a base
 *
 * @number: number to convert
 * @base: base to convert to
 * @upper: whether to use upper or lower case
 *
 * Return: converted number
 */

char *convertBase(unsigned long number, int base, bool upper)
{
	char *digits = upper ? "0123456789ABCDEF" : "0123456789abcdef";
	char *buf;
	int len = number ? 0 : 1;
	unsigned long i;

	for (i = number; i > 0; i /= base)
		len++;

	buf = calloc(len + 1, sizeof(char));
	if (buf == NULL)
		exit(1);

	i = len - 1;
	do {
		buf[i--] = digits[number % base];
		number /= base;
	} while (number > 0);

	buf[len] = '\0';

	return (buf);
}
