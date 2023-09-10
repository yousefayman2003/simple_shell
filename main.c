#include "simple_shell.h"


/**
 * main - basic shell program
 * @argc: argument count
 * @argv: array contains arguments values
 * @env: array contains environment values
 *
 * Return: 0 if success else faliure
*/
int main(int argc, char **argv, char **env)
{
	char **args_v;
	(void)argc;
	(void)argv;
	while (1)
	{
		prompt_f();
		args_v = read_f();
		if (!args_v || _strcmp_f(args_v[0], "\\n") == 0)
		{
			free(args_v);
			continue;
		}
		if (_strcmp_f(args_v[0], "exit") == 0)
			break;
		execute_f(args_v[0], args_v, env);
	}

	return (0);
}
