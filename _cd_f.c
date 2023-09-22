#include "simple_shell.h"

/* declare helper function */
void print_path(char *path);

/**
 * _cd_f - Changes the current directory of the process.
 * @args: pointer to 2D array containing arguments
 * @size: size of the array
 * @head: pointer points to the first var in environ
 * @tail: pointer points to the last var in environ
*/
void _cd_f(char **args, int size, list **head, list **tail)
{
	char buf_v[BUFFER_SIZE];
	char *path_v = NULL, *curr_dir = getcwd(buf_v, BUFFER_SIZE);
	int ch_dir = 0, prev = 0;

	if (size == 1)
	{
		path_v = _getenv_f(*head, "HOME");
		if (!path_v)
			return;
	}
	else if (size == 2)
	{
		path_v = args[1];
		if (_strcmp_f(path_v, "-") == 0)
		{
			path_v = _getenv_f(*head, "OLDPWD");
			if (!path_v)
			{
				print_path(curr_dir);
				return;
			}
			prev = 1;
		}
	}
	else if (size > 2)
	{
		error_handling_f("cd", 2);
		return;
	}

	ch_dir = chdir(path_v);
	if (errno == EACCES)
		return;
	if (ch_dir == -1)
	{
		error_handling_f(path_v, 5);
		return;
	}
	_setenv_f(head, tail, "OLDPWD", buf_v);
	curr_dir = getcwd(buf_v, BUFFER_SIZE);
	_setenv_f(head, tail, "PWD", curr_dir);
	if (prev)
		print_path(curr_dir);
}

/**
 * print_path - prints path to stdout
 * @path: path to print
*/
void print_path(char *path)
{
	_puts_f(path);
	_putchar_f('\n');
}
