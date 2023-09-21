#include "simple_shell.h"
#include <stdio.h>

/**
 * execute_f - Executes a command with the given arguments.
 * @pathname_v: The command to execute.
 * @args_v: array of arguments for the command.
 *
 * This function creates a new process using fork()
 * and replaces the child process with the specified command
 *  and arguments using execve(). The parent process waits
 * for the child process to complete. Error handling is performed
 * for fork() and execve() failures.
 */
void execute_f(const char *pathname_v, char **args_v)
{	
	pid_t id_v = fork();

	if (id_v == 0)
	{
		/* Try to execute with given path name */
		execve(pathname_v, args_v, env);
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
		int status_v;
		char *exit_status_v = NULL;
		wait(&status_v);
		exit_status_v = _atoa_f(WEXITSTATUS(status_v));
		printf("EXIT STATUS = %s\n ,: %d\n", exit_status_v, WEXITSTATUS(status_v));
		setenv("EXIT_STATUS", exit_status_v, 1);
		free(exit_status_v);
	}
}
