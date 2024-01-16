#include "search_algos.h"

/**
 * recursive_search - Code searches for value in array of
 * integers using binary search algo
 *
 *
 * @array: an input array
 * @size: the size of array
 * @value: the value to search
 * Return: the index
 */

int recursive_search(int *array, size_t size, int value)
{
	size_t half = size / 2;
	size_t i;

	if (array == NULL || size == 0)
		return (-1);

	printf("Searching in array");

	for (i = 0; i < size; i++)
		printf("%s %d", (i == 0) ? ":" : ",", array[i]);

	printf("\n");

	if (half && size % 2 == 0)
		half--;

	if (value == array[half])
		return ((int)half);

	if (value < array[half])
		return (recursive_search(array, half, value));

	half++;

	return (recursive_search(array + half, size - half, value) + half);
}

/**
 * binary_search - Code calls binary_search to return
 * the index
 *
 * @array: an input array
 * @size: the size of array
 * @value: the value to search
 * Return: the index
 */

int binary_search(int *array, size_t size, int value)
{
	int ind;

	ind = recursive_search(array, size, value);

	if (ind >= 0 && array[ind] != value)
		return (-1);

	return (ind);
}
