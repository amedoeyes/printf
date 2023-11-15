#include "main.h"

static char buf[1024];
static int i;

/**
 * flushBuf - prints the buffer to stdout
 */

void flushBuf(void)
{
	write(1, buf, i);
	i = 0;
}

/**
 * writeBuf - writes the character to buffer
 *
 * @c: the character to write
 *
 * Return: 1 byte
 */

int writeBuf(char c)
{
	if (i == 1024)
		flushBuf();

	buf[i++] = c;

	return (1);
}
