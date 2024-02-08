#include "main.h"

/**
 * get_bit - get the value of a bit at a given index
 * @n: number
 * @index: index
 * Return: value of the bit at index
 */

int get_bit(unsigned long int n, unsigned int index)
{
	unsigned long int ulin = 1;

	if (index > 63)
		return (-1);

	ulin <<= index;

	if (n & ulin)
		return (1);
	else
		return (0);
}
