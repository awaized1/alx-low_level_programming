#include "lists.h"

/**
 * get_dnodeint_at_index - Code returns nth node of 
 * doubly linked list.
 * @head: points to list's head
 * @index: index of node to search - from 0
 * Return: null or nth node
 */

dlistint_t *get_dnodeint_at_index(dlistint_t *head, unsigned int index)
{
	unsigned int num;
	dlistint_t *tmp;

	num = 0;
	if (head == NULL)
	return (NULL);

	tmp = head;
	while (tmp)
	{
	if (index == num)
	return (tmp);
	num++;
	tmp = tmp->next;
	}
	return (NULL);
}
