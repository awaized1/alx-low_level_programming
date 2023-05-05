#include "main.h"
#include <unistd.h>
/**
 * _putchar - Program writes the char c to standard output
 * @c: Char to print
 *
 * Return: On success 1.
 * On error, return -1 and errno is set.
 */
int _putchar(char c)
{

	return (write(1, &c, 1));

}
