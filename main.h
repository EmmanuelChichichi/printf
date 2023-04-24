#ifndef MAIN_H
#define MAIN_H

#include <stdarg.h>
#include <unistd.h>
#include <stdlib.h>

int _printf(const char *format, ...);
int printf0(const char *format, va_list arg);
int printNum(char specifier, va_list arg);
int printf1(const char *format, va_list arg);

#endif
