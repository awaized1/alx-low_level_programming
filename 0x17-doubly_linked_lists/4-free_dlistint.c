#include "lists.h"

/**
 * free_dlistint - Code frees doubly linked list.
 * @head: points to list's head
 * Return: void
 **/

void free_dlistint(dlistint_t *head)
{
	if (head == NULL)
	return;

	while (head->next)
	{
	head = head->next;
	free(head->prev);
	}
	free(head);
}
