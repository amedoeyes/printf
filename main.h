#ifndef PRINTF_H
#define PRINTF_H

#include <stdarg.h>
#include <stdbool.h>
#include <stddef.h>
#include <stdio.h>
#include <string.h>

int _printf(const char *format, ...);

int _putchar(char c);
int printStr(const char *str);
int printInvalid(char c);
int printInt(int number);

#endif
