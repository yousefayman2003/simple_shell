#include "simple_shell.h"


/* functions declarations */
void overwrite(char *name, char *value, list *head);


/**
 * Description: _setenv_f - insert a new environment variable
 *		into environ linked list
 * Input:
 *	@head: (pointer to a linked list): head of the environ linked list
 *	@tail: (pointer to a linked list): tail of the environ linked list
 *	@name: (string): name of the variable
 *	@value: (string): value of the variable
 * Return:
 *	- 0 on success
 *	- -1 on failure
 */
int _setenv_f(list **head, list **tail, char *name, char *value)
{
	list *node;

	/* overwrite a value of an environment variable */
	if (_getenv_f(*head, name))
	{
		overwrite(name, value, *head);
		return (0);
	}

	/* allocate memory for a new node */
	node = malloc(sizeof(list));
	if (!node)
		return (-1);

	/* allocate memory for the name and value of the variable */
	node->name = malloc(_strlen_f(name) + 1);
	node->value = malloc(_strlen_f(value) + 1);
	node->next = NULL;

	if (!node->name || !node->value)
	{
		free(node);
		return (-1);
	}

	_strcpy_f(node->name, name);
	_strcpy_f(node->value, value);

	/* insert the new node into a linked list */
	if (*head)
	{
		(*tail)->next = node;
		*tail = node;
	}
	else
	{
		*head = node;
		*tail = node;
	}

	return (0);
}


/**
 * Description: overwrite - overwrites the old value of an environment variable
 * Input:
 *	@name: (string): name of the variable
 *	@value: (string): value of the variable
 *	@head: (pointer to linked list): the head pointer of environ list
 */
void overwrite(char *name, char *value, list *head)
{
	int size;

	size = _strlen_f(value) + 1;

	while (head)
	{
		if (_strcmp_f(head->name, name) == 0)
		{
			head->value = realloc(head->value, size);
			if (!head->value)
				return;
			_strcpy_f(head->value, value);
			return;
		}
		head = head->next;
	}
}
