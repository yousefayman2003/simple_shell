#include "simple_shell.h"

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
void execute_f(const char *command, char **args, char **env)
{
	pid_t id_v = fork();

	if (id_v == 0)
	{
		/* Inside child process */
		execve(command, args, env);

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
	}
}
