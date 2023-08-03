#include "main.h"

/**
 * set_bit - Code sets bit at index to 1
 * @n: Pointer to num to change
 * @index: index 1
 *
 * Return: 1 if success, -1 on failure
 */

int set_bit(unsigned long int *n, unsigned int index)
{
	if (index >= sizeof(n) * 8)
		return (-1);

	return (!!(*n |= 1L << index));
}
