#ifndef PRINTF_H
#define PRINTF_H

#include <ctype.h>
#include <stdarg.h>
#include <stdbool.h>
#include <stddef.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

int _printf(const char *format, ...);

int printChar(char c);
int printStr(const char *str);
int printInt(int number);
int printIntLong(long number);
int printIntShort(short number);
int printBin(unsigned int number);
int printUInt(unsigned int number);
int printUIntLong(unsigned long number);
int printUIntShort(unsigned short number);
int printOct(unsigned int number);
int printOctLong(unsigned long number);
int printOctShort(unsigned short number);
int printHex(unsigned int number, bool upper);
int printHexLong(unsigned long number, bool upper);
int printHexShort(unsigned short number, bool upper);
int printStrNP(const char *str);
int printAddr(void *address);
int printStrRev(const char *str);
int printStrRot13(const char *str);
int printInvalid(char c);

int writeBuf(char c);
void flushBuf(void);
char *convertBase(unsigned long number, int base, bool upper);

/**
 * struct Flags - struct to store flags state
 *
 * @hash: flag for hash
 * @plus: flag for plus
 * @space: flag for space
 * @minus: flag for minus
 * @dot: flag for dot
 */

struct Flags
{
	bool hash;
	bool plus;
	bool space;
	bool minus;
	bool dot;
};

void handleFlags(const char **format);
struct Flags *initFlags(void);
struct Flags *getFlags(void);
void freeFlags(void);

void handleWidth(const char **format, va_list *ap);
int printWidth(int currentLen);

void handlePrecision(const char **format, va_list *ap);
int getPrecision(void);

void handleZeros(const char **format);
int getZeros(void);
int printZeros(int currentLen, int zeros);

#endif
