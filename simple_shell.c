#include "simple_shell.h"

int find_run_file_f(char ***, char **);
int is_built_in_f(char *);

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
	char **args_v, *exe_file_v;
	int terminal_v = 1, file_stat_v;
	
	while (terminal_v)
	{
		/* run the program once when user send the command using
		 * pipe symbol "|"
		 */
                terminal_v = isatty(STDIN_FILENO);

		/* prompt for user command */
		prompt_f();

		/* read and parse the user command */
		args_v = read_f();

		/* run the command if it's valid or print an error */
		file_stat_v = find_run_file_f(&args_v, &exe_file_v);
		if (file_stat_v == -1)
			print_error2_f(args_v[0], 127);
		else if (file_stat_v == 0)
			continue;
		else
			free(exe_file_v);
	}
	return (0);
}



/*
 * Description: find_run_file_f - find absoluate path of an executable file
 *              and run it if it found
 * Input:
 *      @pathname: (string): name of the executable file (the command)
 *      @args: (array of strings): arguments of the command
 *      @env: (array of strings): environment variables
 *      @exe_dirs: (string): directory locations of exeutable files
 *      @exe_files: (string): location of exeutable file of the command
 * Return:
 * 	- 1 if we find the file and run it
 *	- 0 if the command empty, from our buil_in funcs, or the user send its path
 *	- -1 if we don't find the file
 */
int find_run_file_f(char ***argv_v, char **exe_file_v)
{
        char *str_v, *token_v, *exe_dirs_v;
        int pathname_len_v = _strlen_f(*argv_v[0]);
	struct stat sb_v;

	/* reprompt if the user enter an empty command */
	if (!*argv_v || _strcmp_f(*argv_v[0], "\\n") == 0)
		return (0);
	/* run a file (command) if the user write its right absolute path */
	if (stat(*argv_v[0], &sb_v) == 0)
	{
		execute_f(*argv_v[0], argv_v);
		return (0);
	}
	else if (is_built_in_f(*argv_v[0]) == 0)
		return (0);
	else
	{
        	/* get the locations of exeutable files as a string */
        	str_v = getenv("PATH");
        	exe_dirs_v = malloc(_strlen_f(str_v) + 1);
        	if (!exe_dirs_v)
                	print_error_f();
        	/* split directories locations for searching in each directory */
        	exe_dirs_v = _strcpy_f(exe_dirs_v, str_v);
        	token_v = strtok(exe_dirs_v, ":");
        	while (token_v != NULL)
        	{
                	*exe_file_v = malloc(_strlen_f(token_v) + pathname_len_v + 2);
                	if (!*exe_file_v)
                        	print_error_f();
                	*exe_file_v = _strcpy_f(*exe_file_v, token_v);
                	*exe_file_v = _strcat_f(_strcat_f(*exe_file_v, "/"), *argv_v[0]);
                	/* run it if we found it in that directory */
			if (stat(*exe_file_v, &sb_v) == 0)
			{
				free(exe_dirs_v);
				execute_f(*exe_file_v, argv_v);
				return (1);
			}
                	token_v = strtok(NULL, ":");
			free(*exe_file_v);
		}
        }
	free(exe_dirs_v);
	return (-1);
}



/**
 * Description: is_built_in_f - check if the given command is a built_in cm
 * 		but we reimplemented it
 * Input:
 *	@cm_v: (string): given command from a user
 * Return:
 *	- 0 if it's a built_in command
 *	- -1 otherwise
 */
int is_built_in_f(char *cm_v)
{
	char *special_v[2] = {"exit", "env"};
	int i_v, not_ident_v;

	for (i_v = 0; i_v < 2; i_v++)
	{
		not_ident_v = _strcmp_f(cm_v, special_v[i_v]);
		if (!not_ident_v)
		{
			switch (i_v)
			{
				case 0:
					exit(EXIT_SUCCESS);
				case 1:
					_env_f();
					return (0);
			}
		}
	}
	return (-1);
}
