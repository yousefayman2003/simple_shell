#include "simple_shell.h"

int find_run_file(const char *, char **, char **, char **);

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
	char *exe_file, *exe_dirs, *input = NULL, **args_v;
	int terminal_v = 1;
	struct stat st;

	while (terminal_v)
	{
		/* Checks if input didnt come from terminal */
                if (isatty(STDIN_FILENO) == 0)
			terminal_v = 0;
                if (terminal_v)
			prompt_f();
		args_v = read_f(&input);

		if (!args_v || _strcmp_f(args_v[0], "\\n") == 0)
			continue;

		if (_strcmp_f(args_v[0], "exit") == 0)
			exit(EXIT_SUCCESS);

		/* Run an executable file (command) if we have its absolute path */
		if (stat(args_v[0], &st) == 0)
			execute_f(args_v[0], args_v, env);
		/* Search about an execution file (command) and run it */
		if (find_run_file(args_v[0], args_v, &exe_file, &exe_dirs) == -1)
			print_error2_f(args_v[0], 127);
		
		free(input);
		free(exe_file);
		free(exe_dirs);
		free_grid_f(args_v);
	}
	return (0);
}



/*
 * Description: find_run_file - find absoluate path of an executable file
 *              and run it if it found
 * Input:
 *      @pathname: (string): name of the executable file (the command)
 *      @args: (array of strings): arguments of the command
 *      @env: (array of strings): environment variables
 *      @exe_dirs: (string): directory locations of exeutable files
 *      @exe_files: (string): location of exeutable file of the command
 * Return:
 *	- 0 if we find the file
 *	- -1 if we don't find the file
 */
int find_run_file(const char *pathname, char **argv,  char **exe_file, char **exe_dirs)
{
        char *str, *token;
        int pathname_len = _strlen_f(pathname);
	struct stat st;

        /* Get the locations of exeutable files as a string */
        str = getenv("PATH");
        *exe_dirs = malloc(_strlen_f(str) + 1);

        /* memory check */
        if (!*exe_dirs)
                print_error_f();

        /* Split string of all location to search in each location */
        *exe_dirs = _strcpy_f(*exe_dirs, str);
        token = strtok(*exe_dirs, ":");

        /* Try to find the file in each location. if found run it */
        while (token != NULL)
        {
                *exe_file = malloc(_strlen_f(token) + pathname_len + 2);

                if (!*exe_file)
                        print_error_f();

                *exe_file = _strcpy_f(*exe_file, token);
                *exe_file = _strcat_f(*exe_file, "/");
                *exe_file = _strcat_f(*exe_file, pathname);
                
		if (stat(*exe_file, &st) == 0)
		{
			execute_f(*exe_file, argv, env);
			return (0);
		}

                token = strtok(NULL, ":");
        }
	/* return -1 because we didn't find the executable file */
	return (-1);
}
