#include "lists.h"

/**
 * insert_nodeint_at_index - The program inserts a new node in the linked list,
 * at a particular position
 * @n: The value to be inserted in the new node
 * @idx: The index where the node is added
 * @head: The pointer to the first node in the list
 *
 * Return: NULL
 */
listint_t *insert_nodeint_at_index(listint_t **head, unsigned int adx, int n)
{
	unsigned int a;
	listint_t *new;
	listint_t *temp = *head;

	new = malloc(sizeof(listint_t));
	if (!new || !head)
		return (NULL);

	new->n = n;
	new->next = NULL;

	if (adx == 0)
	{
		new->next = *head;
		*head = new;
		return (new);
	}

	for (a = 0; temp && a < adx; a++)
	{
		if (a == adx - 1)
		{
			new->next = temp->next;
			temp->next = new;
			return (new);
		}
		else
			temp = temp->next;
	}

	return (NULL);
}
