#include "main.h"
#include <stdlib.h>
#include <stdarg.h>
/**
 *  _printf - printf a text on standard output
 * @format: pointer to a string containing format specifiers
 *
 * Return: the number of caractere
*/
int _printf(const char *format, ...)
{
	int (*f)(va_list);
	va_list arg;
	int number_total_characters = 0;
	int index = 0;

	va_start(arg, format);
	if (format == NULL || format[index + 1] == '\0')
	{
		return (-1);
	}
	for (index = 0; format[index] != '\0'; index++)
	{
		if (format[index] == '%')
		{
			if (format[index + 1] != '\0')
			{
				if (format[index + 1] != 'c' && format[index + 1] != 's'
				&& format[index + 1] != '%' && format[index + 1] != 'i'
				&& format[index + 1] != 'd')
				{
					number_total_characters += _putchar(format[index]);
					number_total_characters += _putchar(format[index + 1]);
					index++;
				}
				else
				{
					f = fund_function(&format[index + 1]);
					number_total_characters += f(arg);
					index++;
				}
			}
		}
		else
		{
			_putchar(format[index]);
			number_total_characters++;
		}
	}
	va_end(arg);
	return (number_total_characters);
}
