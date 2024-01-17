#include "search_algos.h"
#include <math.h>

/**
 * jump_list - Code searches for value in array of
 * ints using jump search algorithm
 *
 * @list: an input list
 * @size: the size of array
 * @value: the value to search
 * Return: index of number
 */

listint_t *jump_list(listint_t *list, size_t size, int value)
{
	size_t index, k, l;
	listint_t *prev;

	if (list == NULL || size == 0)
		return (NULL);

	l = (size_t)sqrt((double)size);
	index = 0;
	k = 0;

	do {
		prev = list;
		k++;
		index = k * l;

		while (list->next && list->index < index)
			list = list->next;

		if (list->next == NULL && index != list->index)
			index = list->index;

		printf("Value checked at index [%d] = [%d]\n", (int)index, list->n);

	} while (index < size && list->next && list->n < value);

	printf("Value found between indexes ");
	printf("[%d] and [%d]\n", (int)prev->index, (int)list->index);

	for (; prev && prev->index <= list->index; prev = prev->next)
	{
		printf("Value checked at index [%d] = [%d]\n", (int)prev->index, prev->n);
		if (prev->n == value)
			return (prev);
	}

	return (NULL);
}
