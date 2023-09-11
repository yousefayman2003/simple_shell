#include "simple_shell.h"
#include <stdio.h>

void find_run_file(const char *, char **, char **, char **, char **);

/**
 * execute_f - Executes a command with the given arguments.
 * @command: The command to execute.
 * @args: array of arguments for the command.
 * @env: array of environment variables
 *
 * This function creates a new process using fork()
 * and replaces the child process with the specified command
 *  and arguments using execve(). The parent process waits
 * for the child process to complete. Error handling is performed
 * for fork() and execve() failures.
 */
void execute_f(const char *pathname, char **args, char **env)
{	
	char *exe_file, *exe_dirs;

	pid_t id_v = fork();

	if (id_v == 0)
	{
		/* Try to execute with given path name */
		execve(pathname, args, env);

		/* Handle the relative path of the command */
		find_run_file(pathname, args, env, &exe_dirs, &exe_file);

		/* execve had an issue */
		perror("Error: Can't execute.");
		exit(EXIT_FAILURE);
	}
	else if (id_v == -1)
	{
		/* Error while forking */
		perror("Error: Can't fork.");
		exit(EXIT_FAILURE);
	}
	else
	{
		/* Inside parent process*/
		wait(NULL);
		free(exe_file);
		free(exe_dirs);
	}
}



/*
 * Description: find_run_file - find absoluate path of an executable file
 * 		and run it
 * Input:
 *	@pathname: (string): name of the executable file (the command)
 *	@args: (array of strings): arguments of the command
 *	@env: (array of strings): environment variables
 *	@exe_dirs: (string): directory locations of exeutable files
 *	@exe_files: (string): location of exeutable file of the command
 * Return: NULL
 */
void find_run_file(const char *pathname, char **args, char **env, char **exe_dirs, char **exe_file)
{
	char *str, *token;
	int pathname_len = _strlen_f(pathname);

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
		execve(*exe_file, args, env);
		token = strtok(NULL, ":");
		free(*exe_file);
        }
}
