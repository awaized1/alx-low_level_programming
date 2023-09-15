#include "lists.h"

/**
 * delete_dnodeint_at_index - Code deletes node at index of
 * a doubly linked list
 *
 * @head: list's head
 * @index: new node's index
 * Return: 1 if success, -1 if failure
 */

int delete_dnodeint_at_index(dlistint_t **head, unsigned int index)
{
	dlistint_t *h1;
	dlistint_t *h2;
	unsigned int num;

	h1 = *head;

	if (h1 != NULL)
		while (h1->prev != NULL)
			h1 = h1->prev;

	num = 0;

	while (h1 != NULL)
	{
		if (num == index)
		{
			if (num == 0)
			{
				*head = h1->next;
				if (*head != NULL)
					(*head)->prev = NULL;
			}
			else
			{
				h2->next = h1->next;

				if (h1->next != NULL)
					h1->next->prev = h2;
			}

			free(h1);
			return (1);
		}
		h2 = h1;
		h1 = h1->next;
		num++;
	}

	return (-1);
}
