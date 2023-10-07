#include "hash_tables.h"

/**
 * hash_table_print - Code prints hash table.
 * @ht: The pointer to a hash table to be printed.
 *
 * Description: The Key pairs are printed in order
 *              as they appear in array of the hash table.
 */

void hash_table_print(const hash_table_t *ht)
{
	hash_node_t *node;
	unsigned long int n;
	unsigned char comma_flag = 0;

	if (ht == NULL)
		return;

	printf("{");
	for (n = 0; n < ht->size; n++)
	{
		if (ht->array[n] != NULL)
		{
			if (comma_flag == 1)
				printf(", ");

			node = ht->array[i];
			while (node != NULL)
			{
				printf("'%s': '%s'", node->key, node->value);
				node = node->next;
				if (node != NULL)
					printf(", ");
			}
			comma_flag = 1;
		}
	}
	printf("}\n");
}
