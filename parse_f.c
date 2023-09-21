#include "simple_shell.h"
#include <string.h>


/**
 * parse_f - tokenize a string with a specific delimiter
 * @buffer: a buffer to store parsed input in it
 * @input: the string what you want to parse it
 * @delim: given delimiter to split the input using it
 *
 * Return:
 *	number of strings in the array on success
 *	-1 on failure
*/
int parse_f(char ***buffer, char *input, const char *delim)
{
	char *token_v;
	int len = 0;

	/* Tokenize copied string */
	token_v = _strtok_f(input, delim);
	*buffer = NULL;

	while (token_v != NULL)
	{
		/* Rieallocate memory for tokens */
		*buffer = realloc(*buffer, (len + 1) * sizeof(char *));
		if (!*buffer)
		{
			free(*buffer);
			return (-1);
		}
		/* Allocate memory for token */
		(*buffer)[len] = token_v;

		/* Get the next token string */
		token_v = _strtok_f(NULL, delim);
		len++;
	}

	/* Reallocate memory for tokens to terminate array with null */
	if (len)
	{
		*buffer = realloc(*buffer, (len + 1) * sizeof(char *));
		if (!*buffer)
		{
			free(*buffer);
			return (-1);
		}

		(*buffer)[len] = token_v;
	}
	return (len);
}
