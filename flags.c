#include "main.h"

static struct Flags *flags;

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
