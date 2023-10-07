#include "hash_tables.h"

shash_table_t *shash_table_create(unsigned long int size);
int shash_table_set(shash_table_t *ht, const char *key, const char *value);
char *shash_table_get(const shash_table_t *ht, const char *key);
void shash_table_print(const shash_table_t *ht);
void shash_table_print_rev(const shash_table_t *ht);
void shash_table_delete(shash_table_t *ht);

/**
 * shash_table_create - Code creates sorted hash table.
 * @size: Size of new sorted hash table.
 *
 * Return: If an error - NULL.
 *         O/W - pointer to a newly sorted hash table.
 */

shash_table_t *shash_table_create(unsigned long int size)
{
	shash_table_t *hash;
	unsigned long int n;

	hash = malloc(sizeof(shash_table_t));
	if (hash == NULL)
		return (NULL);

	hash->size = size;
	hash->array = malloc(sizeof(shash_node_t *) * size);
	if (hash->array == NULL)
		return (NULL);
	for (n = 0; n < size; n++)
		hash->array[n] = NULL;
	hash->shead = NULL;
	hash->stail = NULL;

	return (hash);
}

/**
 * shash_table_set - Code adds element to sorted hash table.
 * @ht: The pointer to a sorted hash table.
 * @key: key to add.
 * @value: Value associated with key.
 *
 * Return: if failure - 0.
 *         O/W - 1.
 */

int shash_table_set(shash_table_t *ht, const char *key, const char *value)
{
	shash_node_t *new, *tmp;
	char *value_copy;
	unsigned long int num;

	if (ht == NULL || key == NULL || *key == '\0' || value == NULL)
		return (0);

	value_copy = strdup(value);
	if (value_copy == NULL)
		return (0);

	num = key_index((const unsigned char *)key, ht->size);
	tmp = ht->shead;
	while (tmp)
	{
		if (strcmp(tmp->key, key) == 0)
		{
			free(tmp->value);
			tmp->value = value_copy;
			return (1);
		}
		tmp = tmp->snext;
	}

	new = malloc(sizeof(shash_node_t));
	if (new == NULL)
	{
		free(value_copy);
		return (0);
	}
	new->key = strdup(key);
	if (new->key == NULL)
	{
		free(value_copy);
		free(new);
		return (0);
	}
	new->value = value_copy;
	new->next = ht->array[num];
	ht->array[num] = new;

	if (ht->shead == NULL)
	{
		new->sprev = NULL;
		new->snext = NULL;
		ht->shead = new;
		ht->stail = new;
	}
	else if (strcmp(ht->shead->key, key) > 0)
	{
		new->sprev = NULL;
		new->snext = ht->shead;
		ht->shead->sprev = new;
		ht->shead = new;
	}
	else
	{
		tmp = ht->shead;
		while (tmp->snext != NULL && strcmp(tmp->snext->key, key) < 0)
			tmp = tmp->snext;
		new->sprev = tmp;
		new->snext = tmp->snext;
		if (tmp->snext == NULL)
			ht->stail = new;
		else
			tmp->snext->sprev = new;
		tmp->snext = new;
	}

	return (1);
}

/**
 * shash_table_get - Code retrieve value associated with
 *                   key in sorted hash table.
 * @ht: The pointer to sorted hash table.
 * @key: key to get a value.
 *
 * Return: If the key can't be matched - NULL.
 *         O/W - value associated with key in ht.
 */

char *shash_table_get(const shash_table_t *ht, const char *key)
{
	shash_node_t *node;
	unsigned long int num;

	if (ht == NULL || key == NULL || *key == '\0')
		return (NULL);

	num = key_index((const unsigned char *)key, ht->size);
	if (num >= ht->size)
		return (NULL);

	node = ht->shead;
	while (node != NULL && strcmp(node->key, key) != 0)
		node = node->snext;

	return ((node == NULL) ? NULL : node->value);
}

/**
 * shash_table_print - Code prints sorted hash table in order.
 * @ht: pointer to a sorted hash table.
 */

void shash_table_print(const shash_table_t *ht)
{
	shash_node_t *node;

	if (ht == NULL)
		return;

	node = ht->shead;
	printf("{");
	while (node != NULL)
	{
		printf("'%s': '%s'", node->key, node->value);
		node = node->snext;
		if (node != NULL)
			printf(", ");
	}
	printf("}\n");
}

/**
 * shash_table_print_rev - Code prints sorted hash table in reverse.
 * @ht: Pointer to sorted hash table to print.
 */

void shash_table_print_rev(const shash_table_t *ht)
{
	shash_node_t *node;

	if (ht == NULL)
		return;

	node = ht->stail;
	printf("{");
	while (node != NULL)
	{
		printf("'%s': '%s'", node->key, node->value);
		node = node->sprev;
		if (node != NULL)
			printf(", ");
	}
	printf("}\n");
}

/**
 * shash_table_delete - Code deletes sorted hash table.
 * @ht: pointer to sorted hash table.
 */

void shash_table_delete(shash_table_t *ht)
{
	shash_table_t *head = ht;
	shash_node_t *node, *tmp;

	if (ht == NULL)
		return;

	node = ht->shead;
	while (node)
	{
		tmp = node->snext;
		free(node->key);
		free(node->value);
		free(node);
		node = tmp;
	}

	free(head->array);
	free(head);
}
