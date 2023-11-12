#include "main.h"

/**
 * printOct - prints an octal number
 *
 * @number: number to print
 *
 * Return: number of bytes printed
 */

int printOct(unsigned int number)
{
	char *buf = convertBase(number, 8, false);
	int len = strlen(buf);

	printStr(buf);

	free(buf);

	return (len);
}
