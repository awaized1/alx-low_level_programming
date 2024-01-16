#include "search_algos.h"

/**
 * linear_search - Code searches for value in array of
 * integers using the search algorithm
 *
 * @array: an input array
 * @size: the size of array
 * @value: the value to search
 * Return: Always EXIT_SUCCESS
 */

int linear_search(int *array, size_t size, int value)
{
	int num;

	if (array == NULL)
		return (-1);

	for (num = 0; num < (int)size; num++)
	{
		printf("Value checked array[%u] = [%d]\n", num, array[num]);
		if (value == array[num])
			return (num);
	}
	return (-1);
}
