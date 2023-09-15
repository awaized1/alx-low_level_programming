#include "lists.h"

/**
 * sum_dlistint - returns sum of all data
 * in doubly linked list
 *
 * @head: pointer to head of the list
 * Return: data sum
 */

int sum_dlistint(dlistint_t *head)
{
	int add = 0;

	if (head != NULL)
	{
		while (head->prev != NULL)
			head = head->prev;

		while (head != NULL)
		{
			add += head->n;
			head = head->next;
		}
	}

	return (add);
}
