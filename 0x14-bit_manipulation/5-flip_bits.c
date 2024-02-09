#include "main.h"

/**
 * flip_bits - returns the number of bits you would need to flip
 * to get from one number to another
 * @n: number
 * @m: number
 * Return: number of bits
 */

unsigned int flip_bits(unsigned long int n, unsigned long int m)
{
	unsigned long int ulin = 1;
	unsigned int count = 0;

	ulin <<= 63;

	while (ulin != 0)
	{
		if ((n & ulin) != (m & ulin))
			count++;
		ulin >>= 1;
	}

	return (count);
}
