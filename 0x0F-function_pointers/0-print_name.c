#include "function_pointers.h"
#include <stdio.h>
#include <stdlib.h>

/**
 * print_name function - prints a name
 * @name: name of the person
 * @(*f) apointer to a function taking a single argument
 * of type char * and return nothing
 * Return:Nothing.
 */

void print_name(char *name, void (*f)(char *))
{
	if (name == NULL || f == NULL)
		return;
	return (name);
}
