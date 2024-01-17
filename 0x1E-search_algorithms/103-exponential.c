#include "search_algos.h"

/**
  * _binary_search - Code Searches for a value in a sorted array
  *
  * @array: Pointer to first element of array to search.
  * @left: starting index of [sub]array to search.
  * @right: ending index of [sub]array to search.
  * @value: The value to search
  *
  * Return: If value not present or  array is NULL, -1.
  *         O/W, the index where value is.
  */

int _binary_search(int *array, size_t left, size_t right, int value)
{
	size_t i;

	if (array == NULL)
		return (-1);

	while (right >= left)
	{
		printf("Searching in array: ");
		for (i = left; i < right; i++)
			printf("%d, ", array[i]);
		printf("%d\n", array[i]);

		i = left + (right - left) / 2;
		if (array[i] == value)
			return (i);
		if (array[i] > value)
			right = i - 1;
		else
			left = i + 1;
	}

	return (-1);
}

/**
  * exponential_search - Code Searches for a value in a sorted array
  *
  * @array: points to first element of array to search.
  * @size: no of elements in array.
  * @value: value to search for.
  *
  * Return: If value not present or array is NULL, -1.
  *         O/W, the index where value is.
  *
  */

int exponential_search(int *array, size_t size, int value)
{
	size_t i = 0, new;

	if (array == NULL)
		return (-1);

	if (array[0] != value)
	{
		for (i = 1; i < size && array[i] <= value; i = i * 2)
			printf("Value checked array[%ld] = [%d]\n", i, array[i]);
	}

	new = i < size ? i : size - 1;
	printf("Value found between indexes [%ld] and [%ld]\n", i / 2, new);
	return (_binary_search(array, i / 2, new, value));
}