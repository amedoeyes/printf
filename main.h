#ifndef PRINTF_H
#define PRINTF_H

#include <stdarg.h>
#include <stdbool.h>
#include <stddef.h>
#include <stdlib.h>
#include <string.h>

int _printf(const char *format, ...);

int _putchar(char c);
int printStr(const char *str);
int printInt(int number);
int printInvalid(char c);

char *convertBase(unsigned long number, int base, bool upper);
int printBin(unsigned int number);

#endif
