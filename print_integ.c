#include "main.h"
#include <stdarg.h>
/**
 * print_integ - Prints an integer.
 * @arg: A list of argument pointing to the integer
 *
 * Return: 1 if success
*/
int print_integ(va_list arg)
{
	int num = va_arg(arg, int);
	int number_total_characters = 0;
	int chiffre_total_in_number = 1;
	unsigned int num_positif = num;

	if (num < 0)
	{
		number_total_characters += _putchar('-');
		num *= -1;
	}

	while ((num_positif / chiffre_total_in_number) > 9)
	{
		chiffre_total_in_number *= 10;
	}
	while (chiffre_total_in_number >= 1)
	{
		_putchar((num_positif / chiffre_total_in_number) + '0');
		num_positif %= chiffre_total_in_number;
		chiffre_total_in_number /= 10;
		number_total_characters++;
	}
	return (number_total_characters);
}
