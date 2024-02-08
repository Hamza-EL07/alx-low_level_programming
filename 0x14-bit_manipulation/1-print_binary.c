#include "main.h"

/**
 * print_binary - print the binary format of a number
 * @n: number to print
 * Return: void
 */

void print_binary(unsigned long int n)
{
	unsigned long int ulin = 1;
	int len = 0;

	ulin <<= 63;

	while ((n & ulin) == 0 && ulin != 0)
	{
		ulin >>= 1;
	}
	if (ulin != 0)
	{
		while (ulin != 0)
		{
			if (n & ulin)
			{
				_putchar('1');
				len++;
			}
			else if (len)
			{
				_putchar('0');
			}
			ulin >>= 1;
		}
	}
	else
	{
		_putchar('0');
	}
}
