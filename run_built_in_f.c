#include "simple_shell.h"


/**
 * Description: run_built_in - run our implementation of a built-in command
 *		if the given arguments are true
 * Input:
 *	@command: (array of strings): the command and its arguments
 *	@len: (int): number of strings in command array
 *	@head_env: (pointer to linked list): points to first var in env list
 *	@tail_env: (pointer to linked list): points to last var in env list
 * Return:
 *	- 0 on success
 *	- errno on failure
 */
int run_built_in(char **command, int len, list **head_env, list **tail_env)
{
	/* env command */
	if (_strcmp_f(*command, "env") == 0)
		return (_env_f(len, *head_env));

	/* setenv command */
	else if (_strcmp_f(*command, "setenv") == 0 && len == 3)
		add_env_f(command, len, head_env, tail_env);

	/* unsetenv command */
	else if (_strcmp_f(*command, "unsetenv") == 0 && len == 2)
		_unsetenv_f(head_env, tail_env, command[1]);

	/* cd command */
	else if (_strcmp_f(*command, "cd") == 0)
		_cd_f(command, len, head_env, tail_env);

	/* echo command */
	else if (_strcmp_f(*command, "echo") == 0)
		_echo_f(command);

	return (0);
}
