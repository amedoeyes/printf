#include "main.h"

/**
 * printAddr - prints address of memory
 *
 * @address: memory address to print
 *
 * Return: number of bytes printed
 */

int printAddr(void *address)
{
	char *buf = convertBase((unsigned long)address, 16, false);
	int len = 0;

	if (!address)
		return (printStr("(nil)"));

	len += printStr("0x");
	len += printStr(buf);

	free(buf);

	return (len);
}
