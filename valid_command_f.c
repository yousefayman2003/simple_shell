#include "simple_shell.h"

/* functions declarations */
int path_handling(char **, list *);


/**
 * Description: valid_command_f - checks the valdity of the given command
 * Input:
 *	@command: (array of strings): the command and its arguments, and options
 *	@head_env:(pointer to linked list): points to the environ linked list
 * Return:
 *	- 127 if the command is not found
 *	- 0 if it is a valid command and its abolute path was given
 *	- 1 if it is a valid command and its abolute path wan not given
 *	- -1 can't allocate memory for variables
 */
int valid_command_f(char **command, list *head_env)
{
	struct stat sb_v;

	/* see if the command with its abolute path is valid or not */
	if (stat(command[0], &sb_v) == 0 || built_in_cm(command) == 0)
		return (0);

	/* handle the command with relative path and check its validity */
	else
		return (path_handling(command, head_env));
}


/**
 * Description: path_handling - search about location of the exe file
 *		of the command and replace its absolute path with
 *		its name in the command array
 * Input:
 *	@name: (string): name of the command
 *	@head_env: (pointer to linked list): points environ linked list
 * Return:
 *	- 127 if the command not found
 *	- 1 if the command is found
 *	- -1 can't allocate memory for variables
 */
int path_handling(char **name, list *head_env)
{
	char *str_v, *token_v, *exe_dirs_v, *exe_file_v;
	int len;
	struct stat sb_v;

	str_v = _getenv_f(head_env, "PATH");
	if (!str_v || *str_v != '/')
	{
		error_handling_f(*name, 127);
		return (127);
	}
	exe_dirs_v = malloc(_strlen_f(str_v) + 1);
	if  (!exe_dirs_v)
		return (-1);
	exe_dirs_v = _strcpy_f(exe_dirs_v, str_v);
	token_v = _strtok_f(exe_dirs_v, ":");
	len = _strlen_f(*name);
	while (token_v != NULL)
	{
		exe_file_v = malloc(_strlen_f(token_v) + len + 2);
		if (!exe_file_v)
		{
			free(exe_dirs_v);
			return (-1);
		}
		_strcpy_f(exe_file_v, token_v);
		exe_file_v = _strcat_f(_strcat_f(exe_file_v, "/"), *name);
		if (stat(exe_file_v, &sb_v) == 0)
		{
			*name = malloc(_strlen_f(exe_file_v) + 1);
			if (!name)
			{
				free(exe_file_v);
				free(exe_dirs_v);
				return (-1);
			}
			_strcpy_f(*name, exe_file_v);
			free(exe_file_v);
			free(exe_dirs_v);
			return (1);
		}
		token_v = _strtok_f(NULL, ":");
		free(exe_file_v);
	}
	free(exe_dirs_v);
	error_handling_f(*name, 127);
	return (127);
}
