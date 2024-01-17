#include "search_algos.h"
#include <math.h>

/**
 * jump_search - Code searches for value in array of
 * ints using jump search algo
 *
 * @array: an input array
 * @size: the size of array
 * @value: the value to search
 * Return: index
 */

int jump_search(int *array, size_t size, int value)
{
	int ind;
	int m;
	int k;
	int prev;

	if (array == NULL || size == 0)
		return (-1);

	m = (int)sqrt((double)size);
	k = 0;
	prev = ind = 0;

	do {
		printf("Value checked array[%d] = [%d]\n", ind, array[ind]);

		if (array[ind] == value)
			return (ind);
		k++;
		prev = ind;
		ind = k * m;
	} while (ind < (int)size && array[ind] < value);

	printf("Value found between indexes [%d] and [%d]\n", prev, ind);

	for (; prev <= ind && prev < (int)size; prev++)
	{
		printf("Value checked array[%d] = [%d]\n", prev, array[prev]);
		if (array[prev] == value)
			return (prev);
	}

	return (-1);
}
