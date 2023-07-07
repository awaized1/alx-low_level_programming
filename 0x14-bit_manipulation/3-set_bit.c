#include "main.h"

/**
 * set_bit - Program sets a bit at an index to 1
 * n: a pointer to the num to change
 * index: index of 1
 *
 * Return: 1 if success, -1 if failure
 */

int set_bit(unsigned long int *n, unsigned int index)
{
	if (index > 63)
		return (-1);

	*n = ((1UL << index) | *n);
	return (1);
}
