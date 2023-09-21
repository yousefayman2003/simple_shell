#include "simple_shell.h"

/**
 * _cd_f - Changes the current directory of the process.
 * @args: pointer to 2D array containing arguments
 * @size: size of the array
 * @head: pointer points to the first var in environ
 * @tail: pointer points to the last var in environ
*/
void _cd_f(char **args, int size, list **head, list **tail)
{
	char *path_v = NULL, *curr_dir = NULL, buf_v[BUFFER_SIZE];
	int ch_dir = 0;

	if (size == 1)
		path_v = _getenv_f(*head, "HOME");
	else if (size == 2)
	{
		path_v = args[1];
		if (_strcmp_f(path_v, "-") == 0)
		{
			path_v = _getenv_f(*head, "OLDPWD");
			if (!path_v)
			{
				error_handling_f("cd", 4);
				return;
			}
		}
	}
	else if (size > 2)
	{
		error_handling_f("cd", 2);
		return;
	}

	curr_dir = getcwd(buf_v, BUFFER_SIZE);
	ch_dir = chdir(path_v);
	if (ch_dir == -1)
	{
		error_handling_f(path_v, 5);
		return;
	}
	_setenv_f(head, tail, "OLDPWD", buf_v);
	curr_dir = getcwd(buf_v, BUFFER_SIZE);
	_setenv_f(head, tail, "PWD", curr_dir);
}
