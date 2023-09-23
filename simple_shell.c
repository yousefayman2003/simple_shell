#include "simple_shell.h"


/* functions declarations */
void handle_exit(void);
void free_shell(void);


/* global variables */
char **parsed_input, *input;
int st = 0, arr_len, cm_st;
list *head_env, *tail_env;


/**
 * Description: simple_shell - a container of all needed
 *		functions and instructions to run the shell
 * Input: NULL
 * Return: NULL
 */
void simple_shell(void)
{
	char *err_mess = "";
	int terminal_v = 1;

	cpy_env_f(&head_env, &tail_env);
	/* run the shell */
	while (1)
	{
		/* skip prompt stage if the user send the command using "|" operator */
		terminal_v = isatty(STDIN_FILENO);
		if (terminal_v)
			prompt_f();
		/* read and parse the command with EOF handling */
		read_f(&input, &head_env, st);
		/* handle command comments */
		_strtok_f(input, " #");

		/* validity, and execution stages for empty commands */
		arr_len = parse_f(&parsed_input, input, " ");
		if (arr_len > 0)
		{
			/* handle the exit command */
			handle_exit();
			/* check the validity of the command */
			cm_st = valid_command_f(parsed_input, head_env);
			st = cm_st;
			/* if the command is valid run it */
			if (cm_st == 0 || cm_st == 1)
				st = execute_f(parsed_input, arr_len, &head_env, &tail_env);
			free_shell();
		}
		else
		{
			st = arr_len;
			free(input);
		}
	}
	free_list_f(&head_env);
	if (terminal_v)
		error_handling_f(err_mess, st);
}


/**
 * Description: free_shell - free all alocated memory in the shell
 * Input: user global variables
 * Return: NULL
 */
void free_shell(void)
{
	if (cm_st == 1)
		free(parsed_input[0]);
	free(parsed_input);
	free(input);
}


/**
 * Description: handle_exit - exit the shell when the exit command is requested
 * Input: use global variables
 * Return: NULL
 */
void handle_exit(void)
{
	int exit_st;

	if (_strcmp_f(parsed_input[0], "exit") == 0)
	{
		exit_st = _exit_f(parsed_input, arr_len);
		free_list_f(&head_env);
		cm_st = 0;
		free_shell();
		if (exit_st == EXIT_SUCCESS)
			exit(st);
		exit(exit_st);
	}
}
