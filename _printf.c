#include "main.h"

/**
 * _printf - produces output according to a format
 * @format: is a character string
 * Return: number of chars printed
 */

int _printf(const char *format, ...)
{
	va_list arg1, arg2;
	int numOfChar;

	va_start(arg1, format);
	numOfChar = printf0(format, arg1);
	va_end(arg1);

	va_start(arg2, format);
	numOfChar += printf1(format, arg2);
	va_end(arg2);

	return (numOfChar);
}
