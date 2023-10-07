#include "hash_tables.h"

/**
 * hash_table_get - Code retrievs value associated with
 *                  key in hash table.
 * @ht: pointer to a hash table.
 * @key: key to get value of.
 *
 * Return: If key cannot be matched - NULL.
 *         O/W - the value associated with the key in ht.
 */

char *hash_table_get(const hash_table_t *ht, const char *key)
{
	hash_node_t *node;
	unsigned long int num;

	if (ht == NULL || key == NULL || *key == '\0')
		return (NULL);

	num = key_index((const unsigned char *)key, ht->size);
	if (num >= ht->size)
		return (NULL);

	node = ht->array[num];
	while (node && strcmp(node->key, key) != 0)
		node = node->next;

	return ((node == NULL) ? NULL : node->value);
}
