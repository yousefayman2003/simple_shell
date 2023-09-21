#include "simple_shell.h"

/**
 * Description: _getenv_f - get the value of an environment variable
 * Input:
 *	@var: (pointer to linked list): use it to points to each node
 *      @str: (string): name of the environment variable
 * Return:
 *      - value of the varible if it's found
 *      - NULL otherwise
 */
char *_getenv_f(list *var, char *str)
{
	while (var)
	{
		if (_strcmp_f(var->name, str) == 0)
			return (var->value);
		var = var->next;
	}
	return (NULL);
}
