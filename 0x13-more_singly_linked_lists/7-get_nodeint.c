#include "lists.h"

/**
 * get_nodeint_at_index - Program returns the node at a certain index in a given linked list
 * @head: Is the first node in the linked list
 * @index: The index of the node to be returned
 *
 * Return: NULL
 */
listint_t *get_nodeint_at_index(listint_t *head, unsigned int index)
{
	unsigned int a = 0;
	listint_t *temp = head;

	while (temp && a < index)
	{
		temp = temp->next;
		a++;
	}

	return (temp ? temp : NULL);
}
