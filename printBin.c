#include "main.h"
#include <stdlib.h>
#include <string.h>

#include "main.h"

/**
 * printBin - prints an binary number
 *
 * @number: number to print
 *
 * Return: number of bytes printed
 */

int printBin(unsigned int number)
{
	char *buf = convertBase(number, 2, false);
	int len = strlen(buf);

	printStr(buf);

	free(buf);

	return (len);
}
