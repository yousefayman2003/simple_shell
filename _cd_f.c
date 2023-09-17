#include "simple_shell.h"

/**
 * _cd_f - Changes the current directory of the process.
 * @args: pointer to 2D array containing arguments
 * @size: size of the array
*/
void _cd_f(char ***args, int size)
{
	char *path_v, *buf_v;
	size_t buf_size_v = 512;
	if (size == 1)
		path_v = getenv("HOME");
	else if(size == 2)
	{
		path_v = (*args)[1];
		if (_strcmp_f(path_v, "-") == 0)
		{
			path_v = getenv("OLDPWD");
			if (!path_v)
			{
				print_error_f("cd", 4);
				return;
			}
		}
	}
	else
	{
		print_error_f("cd", 2);
		return;
	}
	do
	{	
        	buf_v = malloc(sizeof(char) * buf_size_v);
        	if (!buf_v)
                	print_error_f("cd", 1);
		buf_size_v += 100;
	} while (getcwd(buf_v, buf_size_v) == NULL);
	if (setenv("OLDPWD", buf_v, 1) == -1)
		perror("cant set OLDPWD");
	if (chdir(path_v) == -1)
	{
		print_error_f(path_v, 5);
		free(buf_v);
		return;
	}
	if (setenv("PWD", getcwd(buf_v, buf_size_v), 1) == -1)
		perror("cant set PWD");
	free(buf_v);
}
