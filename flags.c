#include "main.h"

static struct Flags *flags;

/**
 * handleFlags - handles flags
 *
 * @format: format pointer
 */

void handleFlags(const char **format)
{
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
			case '-':
				flags->minus = true;
				break;
			case '0':
			{
				handleZeros(format);
				continue;
			}
			default:
				return;
		}
		(*format)++;
	}
}

/**
 * initFlags - initialize flags
 *
 * Return: pointer to flags
 */

struct Flags *initFlags(void)
{
	flags = (struct Flags *)malloc(sizeof(struct Flags));
	if (!flags)
		exit(1);

	flags->hash = false;
	flags->plus = false;
	flags->space = false;
	flags->minus = false;
	flags->dot = false;

	return (flags);
}

/**
 * getFlags - get flags instance
 *
 * Return: pointer to flags instance
 */

struct Flags *getFlags(void)
{
	if (!flags)
		flags = initFlags();

	return (flags);
}

/**
 * freeFlags - free flags
 */

void freeFlags(void)
{
	if (!flags)
		return;

	free(flags);
	flags = NULL;
}
