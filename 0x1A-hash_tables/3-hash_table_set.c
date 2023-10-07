#include "hash_tables.h"

/**
 * hash_table_set - Code adds or updates element in hash table.
 * @ht: A pointer to hash table.
 * @key: A key to add
 * @value: value associated with key.
 *
 * Return: if failure - 0.
 *         O/W - 1.
 */

int hash_table_set(hash_table_t *ht, const char *key, const char *value)
{
	hash_node_t *new;
	char *value_copy;
	unsigned long int num, n;

	if (ht == NULL || key == NULL || *key == '\0' || value == NULL)
		return (0);

	value_copy = strdup(value);
	if (value_copy == NULL)
		return (0);

	num = key_index((const unsigned char *)key, ht->size);
	for (n = num; ht->array[n]; n++)
	{
		if (strcmp(ht->array[n]->key, key) == 0)
		{
			free(ht->array[n]->value);
			ht->array[n]->value = value_copy;
			return (1);
		}
	}

	new = malloc(sizeof(hash_node_t));
	if (new == NULL)
	{
		free(value_copy);
		return (0);
	}
	new->key = strdup(key);
	if (new->key == NULL)
	{
		free(new);
		return (0);
	}
	new->value = value_copy;
	new->next = ht->array[num];
	ht->array[num] = new;

	return (1);
}
