#include "main.h"

static int zeros;

/**
 * handleZeros - handles zeros
 *
 * @format: format string
 */

void handleZeros(const char **format)
{
	char *tmp = strchr(*format, '.');

	zeros = 0;

	if (tmp)
	{
		tmp++;
		while (isdigit(*tmp) || *tmp == '*')
			tmp++;

		if (strchr("dibouxXplh", *tmp))
		{
			(*format)++;
			return;
		}
	}

	if (getFlags()->minus)
	{
		(*format)++;
		return;
	}

	while (isdigit(**format))
	{
		zeros = zeros * 10 + (**format - '0');
		(*format)++;
	}
}

/**
 * getZeros - gets zeros
 *
 * Return: zeros
 */

int getZeros(void)
{
	return (zeros);
}

/**
 * printZeros - prints zeros to standard output
 *
 * @currentLen: current length
 * @zeros: zeros to print
 *
 * Return: number of bytes printed
 */

int printZeros(int currentLen, int zeros)
{
	int i;
	int len = 0;

	for (i = 0; i < zeros - currentLen; i++)
		len += writeBuf('0');

	return (len);
}
