#include "simple_shell.h"
#include <stdio.h>

/**
 * execute_f - Executes a command with the given arguments.
 * @args_v: array of arguments for the command.
 * @len: number of strings in args_v array
 * @head_env: (pointer to linked list): points to the first var in env list
 * @tail_env: (pointer to linked list): points to the last var in env list
 *
 * This function creates a new process using fork()
 * and replaces the child process with the specified command
 *  and arguments using execve(). The parent process waits
 * for the child process to complete. Error handling is performed
 * for fork() and execve() failures.
 *
 * Return:
 *	- exit status
 *	- -2 on failure
 */
int execute_f(char **args_v, int len, list **head_env, list **tail_env)
{
	char *exit_st = NULL;
	int st;
	pid_t id_v;

	/*
	 * if the command is a built-in command but we have a custom
	 * implementaion for it run our implementation
	 */
	if (built_in_cm(args_v) == 0)
		return (run_built_in(args_v, len, head_env, tail_env));

	/* run commands what we didn't implement them */
	id_v = fork();

	if (id_v == 0)
	{
		/* ececute the command */
		execve(args_v[0], args_v, env);
	}
	else if (id_v == -1)
	{
		/* Error while forking */
		return (-2);
	}

	/* Inside parent process*/
	wait(&st);
	exit_st = _atoa_f(WEXITSTATUS(st));
	_setenv_f(head_env, tail_env, "EXIT_STATUS", exit_st);
	free(exit_st);
	return (WEXITSTATUS(st));
}
