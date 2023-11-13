#ifndef PRINTF_H
#define PRINTF_H

#include <ctype.h>
#include <stdarg.h>
#include <stdbool.h>
#include <stddef.h>
#include <stdlib.h>
#include <string.h>

int _printf(const char *format, ...);

int printChar(char c);
void flushBuf(void);
int printStr(const char *str);
int printInt(int number);
int printBin(unsigned int number);
int printUInt(unsigned int number);
int printOct(unsigned int number);
int printHex(unsigned int number, bool upper);
int printStrNP(const char *str);
int printAddr(void *address);
int printInvalid(char c);

char *convertBase(unsigned long number, int base, bool upper);

/**
 * struct Flags - struct to store flags state
 *
 * @hash: flag for hash
 * @plus: flag for plus
 * @space: flag for space
 */

struct Flags
{
	bool hash;
	bool plus;
	bool space;
};

struct Flags *initFlags(void);
struct Flags *getFlags(void);
void freeFlags(void);

#endif
