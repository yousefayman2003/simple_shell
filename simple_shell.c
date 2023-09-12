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
	char **args_v, *exe_file_v, *input = NULL;
	int terminal_v = 1, file_stat_v;
	
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
		args_v = read_f(&input);

		/* run the command if it's valid or print an error */
		file_stat_v = find_run_file_f(&args_v, &exe_file_v);
		if (file_stat_v == -1)
			print_error2_f(args_v[0], 127);
		else if (file_stat_v == 0)
			continue;
		else
			free(exe_file_v);
		free_grid_f(args_v);
		free(input);
	}
	return (0);
}
