#include "main.h"

/**
 * clear_bit - clear the value of a bit at a given index
 * @n: number pointer unsigned long int
 * @index: index unsigned int
 * Return: 1 if it worked, -1 if an error occurred
 */

int clear_bit(unsigned long int *n, unsigned int index)
{
	unsigned long int ulin = 0;

	if (index > 63)
		return (-1);

	ulin <<= index;
	*n = (*n & ulin);

	return (1);
}
