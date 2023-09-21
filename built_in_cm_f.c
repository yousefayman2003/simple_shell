#include "simple_shell.h"


/**
 * Description: built_in_cm - check if the user command is a built-in command
 *		but we reimplement it or not
 * Input:
 *	@command: (array of strings): the command name and its arguments
 * Return:
 *	- 0 if it is built-in
 *	- -1 otherwise
 */
int built_in_cm(char **command)
{
	int cmp;
	char *name = command[0];

	/* env command */
	cmp = (_strcmp_f(name, "env") != 0) ? -1 : 0;

	/* cd command */
	cmp = (_strcmp_f(name, "cd") != 0) ? cmp : 0;

	/* setenv command */
	cmp = (_strcmp_f(name, "setenv") != 0) ? cmp : 0;

	/* unsetenv command */
	cmp = (_strcmp_f(name, "unsetenv") != 0) ? cmp : 0;

	/* echo $$ || echo $? commands */
	cmp = (_strcmp_f(name, "echo") != 0) ? cmp : 0;

	return (cmp);
}
