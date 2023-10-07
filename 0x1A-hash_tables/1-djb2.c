#include "hash_tables.h"

/**
 * hash_djb2 - This hash function is implementing the djb2 algorithm.
 * @str: string to be hashed.
 *
 * Return: The new hash.
 */

unsigned long int hash_djb2(const unsigned char *str)
{
	unsigned long int hash;
	int n;

	hash = 5381;
	while ((n = *str++))
		hash = ((hash << 5) + hash) + n; /* hash * 33 + n */

	return (hash);
}
