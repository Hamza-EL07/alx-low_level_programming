#include "main.h"

/**
 * set_bit - set the value of a bit at a given index
 * @n: number
 * @index: index
 * Return: 1 if it worked, -1 if an error occurred
 */

int set_bit(unsigned long int *n, unsigned int index)
{
	unsigned long int ulin = 1;

	if (index > 63)
		return (-1);

	ulin <<= index;
	*n = (*n | ulin);

	return (1);
}
