#include "lists.h"

/**
 * dlistint_len - Code returns number of elements in
 * the given list
 *
 * @h: list head
 * Return: no of nodes
 */

size_t dlistint_len(const dlistint_t *h)
{
	int num;

	num = 0;

	if (h == NULL)
		return (num);

	while (h->prev != NULL)
		h = h->prev;

	while (h != NULL)
	{
		num++;
		h = h->next;
	}

	return (num);
}
