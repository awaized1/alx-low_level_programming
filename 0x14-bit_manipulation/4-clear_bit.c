#include "main.h"

/**
 * clear_bit - Program sets the value of bit to 0
 * @n: Points to the number to be changed.
 * @index: The index of the bit to be cleared
 *
 * Return: 1 on success, -1 on failure
 */

int clear_bit(unsigned long int *n, unsigned int index)
{
	if (index > 63)
		return (-1);

	*n = (~(1UL << index) & *n);
	return (1);
}
