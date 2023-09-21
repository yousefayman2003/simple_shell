#include "simple_shell.h"

/**
 * _cd_f - Changes the current directory of the process.
 * @args: pointer to 2D array containing arguments
 * @size: size of the array
*/
int _cd_f(char **args, int size)
{
	char *path_v = NULL, *curr_dir = NULL, buf_v[BUFFER_SIZE];
	int ch_dir = 0;

	if (size == 1)
		path_v = getenv("HOME");
	else if (size == 2)
	{
		path_v = args[1];
		if (_strcmp_f(path_v, "-") == 0)
		{
			path_v = getenv("OLDPWD");
			_puts_f(path_v);
			if (!path_v)
			{
				print_error_f("cd", 4);
				return (-1);
			}
		}
	}
	else if (size > 2)
	{
		print_error_f("cd", 2);
		return (-1);
	}	
	curr_dir = getcwd(buf_v, BUFFER_SIZE);
	setenv("OLDPWD", buf_v, 1);
	ch_dir = chdir(path_v);
	if (ch_dir == -1)
	{
		print_error_f(path_v, 5);
		return (-1);
	}
	curr_dir = getcwd(buf_v, BUFFER_SIZE);
	setenv("PWD", curr_dir, 1);
	return (0);
}
