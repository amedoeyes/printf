#include <unistd.h>

static char buf[1024];
static int i;

/**
 * flushBuf - prints the buffer
 */

void flushBuf(void)
{
	write(1, buf, i);
	i = 0;
}

/**
 * printChar - writes the character c to stdout
 *
 * @c: the character to print
 *
 * Return: 1 byte
 */

int printChar(char c)
{
	if (i == 1024)
		flushBuf();

	buf[i++] = c;

	return (1);
}
