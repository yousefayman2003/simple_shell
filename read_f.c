#include "simple_shell.h"
#include <stdio.h>

/**
 * read_f - reads input from standard input.
 * @buffer: a buffer to store the user input in it
 * @head_env: the head pointer of environment variables linked list
 * @l_err: the last errno in the simple shell
 *
 * Return:
 *	num_chars_v on success
 *	-1 on failure
*/
int read_f(char **buffer, list **head_env, int l_err)
{
	int num_chars_v;
	size_t size_v = 0;

	/* get input from standard input*/
	*buffer = NULL;
	/* num_chars_v = _getline_f(buffer, &size_v, STDIN_FILENO); */
	num_chars_v = getline(buffer, &size_v, stdin);

	/* EOF detection*/
	if (num_chars_v == -1)
	{
		free(*buffer);
		free_list_f(head_env);
		write(0, "exit\n", 6);
		exit(l_err);
	}

	(*buffer)[num_chars_v - 1] = '\0';
	return (num_chars_v);
}
