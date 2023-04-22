#include "main.h"

/**
 * _printf - produces output according to a format
 * @format: is a character string
 * Return: number of chars printed
 */

int _printf(const char *format, ...)
{
	va_list arg;
	int i, j, numOfChar = 0;
	char c, *str;

	va_start(arg, format);
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
	va_end(arg);
	return (numOfChar);
}
