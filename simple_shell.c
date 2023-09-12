#include "simple_shell.h"

/**
 * main - basic shell program
 * @argc: argument count
 * @argv: array contains arguments values
 * @env: array contains environment values
 *
 * Return: 0 if success else faliure
*/
int main()
{
	char **args_v, *input;
	int terminal_v = 1;
	
	while (terminal_v)
	{
		/* run the program once when user send the command using
		 * pipe symbol "|"
		 */
                terminal_v = isatty(STDIN_FILENO);

		/* prompt for user command */
		if (terminal_v)
			prompt_f();

		/* read and parse the user command */
		input = NULL;
		args_v = read_f(&input);

		free_grid_f(args_v);
		free(input);
	}
	return (0);
}
