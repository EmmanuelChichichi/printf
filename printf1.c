#include "main.h"

/**
 * printf1 - handles d and i conversion characters
 * @format: format string
 * @arg: arguments list
 * Return: number of characters printed
 */

int printf1(const char *format, va_list arg)
{
	int i, numOfChar = 0;

	if (!format)
		return (-1);
	for (i = 0; format[i] != '\0'; i++)
	{
		if (format[i] == '%')
		{
			i++;
			if (format[i] == 'i' || format[i] == 'd')
			{
				numOfChar += printNum(format[i], arg);
			}
		}
		else
		{
			write(1, &format[i], 1);
			numOfChar++;
		}
	}
	return (numOfChar);
}

/**
 * printNum - prints a number
 * @specifier: the conversion specifier ('d' or 'i')
 * @arg: is a variable list of arguments
 * Return: number of chars printed
 */

int printNum(char specifier, va_list arg)
{
	int num, numOfChar = 0;
	char c;

	va_list argCpy;

	va_copy(argCpy, arg);
	num = va_arg(argCpy, int);
	if (num < 0)
	{
		write(1, "-", 1);
		numOfChar++;
		num = -num;
	}
	if (num / 10)
		numOfChar += printNum(specifier, argCpy);
	c = (num % 10) + '0';
	write(1, &c, 1);
	numOfChar++;
	va_end(argCpy);

	return (numOfChar);
}
