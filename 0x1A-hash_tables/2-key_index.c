#include "hash_tables.h"

/**
 * key_index - Code gets index at which key/value
 *      pair should be stored in an array of hash table.
 * @key: A key to get index of.
 * @size: hash table's size of array.
 *
 * Return: index of key.
 * Description: Uses the djb2 algorithm.
 */

unsigned long int key_index(const unsigned char *key, unsigned long int size)
{
	return (hash_djb2(key) % size);
}
