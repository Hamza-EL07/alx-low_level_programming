#include <stdlib.h>
#include "function_pointers.h"

/**
 * array_iterator - Executes a given function on each element of an array.
 * @array: Pointer to the array.
 * @size: Number of elements in the array.
 * @action: Pointer to the function to be executed on each element.
 */

void array_iterator(int *array, size_t size, void (*action)(int))
{
	if (array == NULL || action == NULL)
		return;
	for (size_t i = 0; i < size; i++)
	{
		action(array[i]); /* Call the provided function on each element */
	}
}
