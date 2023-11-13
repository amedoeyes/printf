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
int printInvalid(char c);

char *convertBase(unsigned long number, int base, bool upper);

#endif
