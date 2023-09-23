#include "simple_shell.h"


int valid_name(char *name);

/**
 * Description: add_env_f - add an environment var into environ linked list
 * Input:
 *	@command: (array of strings): setenv command with its arguments
 *	@len: (int): number of arguments
 *	@head: (pointer to linked list): the head pointer of environ list
 *	@tail: (pointer to linked list): the tail pointer of environ list
 * Return: NULL
 */
void add_env_f(char **command, int len, list **head, list **tail)
{
	/* set a new environment variable if the arguments are valid */
	if (valid_name(command[1]) == 0 && len == 3)
			_setenv_f(head, tail, command[1], command[2]);
}


/**
 * Description: valid_name - cheack if the name of the variable is valid or not
 * Input:
 *	@name: (string): name of the varible
 * Return:
 *	- 0 if it's valid
 *	- -1 otherwise
 */
int valid_name(char *name)
{
	int i = 0;

	while (name[i] != '\0')
	{
		if (name[i] == '=' || name[i] == ' ')
			return (-1);
		i++;
	}
	return (0);
}
