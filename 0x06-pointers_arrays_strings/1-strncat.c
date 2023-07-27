#include "main.h"

/**
 * _strncat function that concatenates two strings
 * @dest: string with concatenation
 * @src: string to be concatenated
 * @n: size of second string
 * Return: Always 0.
 */

char *_strncat(char *dest, char *src, int n)
{
	int lenD, lenS;

	lenD = 0;
	lenS = 0;

	while (*(dest + lenD) != '\0')
		lenD++

	while (*(src + lenS) != '\0' && lenS < n)
	{
		*(dest + lenD) = (src + lenS);
		lenD++
		lenS++
	}
	*(dest + lenD) = '\0';
	return (dest);
}
