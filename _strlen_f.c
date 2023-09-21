#include "simple_shell.h"

/**
 * _strlen_f - Gets length of a string
 *  @s : Given string
 *  Return: Length of the string
*/
int _strlen_f(const char *s)
{
	int i_v = 0;

	if (!s)
		return (0);

	for (i_v = 0; s[i_v];)
		i_v++;

	return (i_v);
}
