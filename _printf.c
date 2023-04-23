#include "main.h"

/**
 * _printf - produces output according to a format
 * @format: is a character string
 * Return: number of chars printed
 */

int _printf(const char *format, ...)
{
	va_list arg;
	int numOfChar;

	va_start(arg, format);
	numOfChar = printf0(format, arg);
	va_end(arg);

	return (numOfChar);
}
