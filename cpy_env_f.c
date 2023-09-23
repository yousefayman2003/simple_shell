#include "simple_shell.h"

/**
 * Description: cpy_env_f - copies user's env variables into a linked list
 * Input:
 *	@head: (pointer to a linked list): points to the first node of the list
 *	@tail: (pointer to a linked list): points to the last node of the list
 * Return: NULL
 */
void cpy_env_f(list **head, list **tail)
{
	int i = 0;
	char *name, *value;

	while (environ[i] != NULL)
	{
		name = malloc(_strlen_f(environ[i]) + 1);
		if (!name)
			return;

		_strcpy_f(name, environ[i]);

		name = _strtok_f(name, "=");
		value = _strtok_f(NULL, "");
		_setenv_f(head, tail, name, value);
		free(name);

		i++;
	}
}
