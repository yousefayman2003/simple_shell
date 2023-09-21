#include "simple_shell.h"

/**
 * _putchar_f - writes the character c to stdout
 * @c: the character to print
 *
 * Return: On success 1.
 *              On error, -1 is returned, and errno is set appropriately
*/
int _putchar_f(char c)
{
	return (write(1, &c, 1));
}
