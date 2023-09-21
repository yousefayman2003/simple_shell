#include "simple_shell.h"

/**
 * Description: _unsetenv_f - remove an envrionment variable
 * Input:
 *	@head: (pointer to linked list): points to the first node of environ
 *	@tail: (pointer to linked list): points to the last node of environ
 *	@name: (string): name of the envrionment variable
 * Return: NULL
 */
void _unsetenv_f(list **head, list **tail, char *name)
{
	list *curr = *head, *prev = NULL;

	/* loop over the linked list */
	while (curr)
	{
		/* compare name of the current node with target variable */
		if (_strcmp_f(curr->name, name) == 0)
		{
			/* check if the target var is the first var or not */
			if (prev)
			{
				/* check if the target var is the last var or not */
				if (!curr->next)
					*tail = prev;
				prev->next = curr->next;
			}
			else
				*head = curr->next;
			/* remove the target environment variable */
			free(curr->name);
			free(curr->value);
			free(curr);
			return;
		}
		prev = curr;
		curr = curr->next;
	}
	/* if program reaches here then it didn't find the traget var */
}
