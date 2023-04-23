#include "main.h"

/**
 * print0 - handles c, s and % specifiers
 * @format: format string
 * @args: arguments list
 * Return: number of characters printed
 */

int printf0(const char *format, va_list arg)
{
	int i, j, numOfChar = 0;
	char c, *str;

	if (!format)
		return (-1);
	for (i = 0; format[i] != '\0'; i++)
	{
		if (format[i] == '%')
		{
			i++;
			if (format[i] == 'c')
			{
				c = va_arg(arg, int);
				write(1, &c, 1);
				numOfChar++;
			}	
			else if (format[i] == 's')
			{
				str = va_arg(arg, char *);
				for (j = 0; str[j] != '\0'; j++)
				{
					write(1, &str[j], 1);
				 	numOfChar++;
				}
			}
			else if (format[i] == '%')
			{
				write(1, &format[i], 1);
				numOfChar++;
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
