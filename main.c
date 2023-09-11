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
	int terminal_v = 1;
	(void)argc;
	(void)argv;
	
	while (terminal_v)
	{
		/* Checks if input didnt come from terminal */
                if (isatty(STDIN_FILENO) == 0)
			terminal_v = 0;
                if (terminal_v)
			prompt_f();
		args_v = read_f();
		if (!args_v || _strcmp_f(args_v[0], "\\n") == 0)
		{
			continue;
		}
		if (_strcmp_f(args_v[0], "exit") == 0)
			exit(EXIT_SUCCESS);
		execute_f(args_v[0], args_v, env);
	}
	return (0);
}
