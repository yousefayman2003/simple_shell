#include "simple_shell.h"

/**
 * tokenize_f - tokenize a string with a specific delimiter
 * @input: input string
 * @delimiter: given delimiter to split upon
 *
 * Return: a pointer to an array of strings
*/
char **tokenize_f(const char *input, const char *delimiter)
{
	char *token_v,  *copy_v;
	char **tokens_v = NULL;
	int cnt_v = 0;

	/* Allocate memory for copy */
	copy_v = malloc(sizeof(char) * (_strlen_f(input) + 1));
	if (!copy_v)
		print_error_f();
	/* Copying input string */
	_strcpy_f(copy_v, input);
	/* Tokenize copied string */
	token_v = strtok(copy_v, delimiter);

	while (token_v != NULL)
	{
		/* Reallocate memory for tokens */
		tokens_v = realloc(tokens_v, (cnt_v + 1) * sizeof(char *));
		/* Allocate memory for token */
		tokens_v[cnt_v] = malloc(sizeof(char) * (_strlen_f(token_v) + 1));
		if (!token_v || !tokens_v[cnt_v])
			print_error_f();
		/* Copying the token string */
		_strcpy_f(tokens_v[cnt_v], token_v);
		token_v = strtok(NULL, delimiter);
		cnt_v++;
	}
	/* Reallocate memory for tokens to terminate array with null */
	tokens_v = realloc(tokens_v, (cnt_v + 1) * sizeof(char *));
	if (!tokens_v)
		print_error_f();
	tokens_v[cnt_v] = NULL;
	/* Free allocated memory */
	free(copy_v);

	return (tokens_v);
}

/**
 * read_f - reads input from standard input.
 *
 * Return: input string.
*/
char **read_f(char **input)
{
	char **args_v = NULL;
	int num_chars_v;
	/* Ignoring size of buffer */
	size_t size_v = 2;
	/* get input from standard input*/
	num_chars_v = getline(input, &size_v, stdin);

	/* check if the user enters \n */
	if (size_v == 2)
	{
		*input = "\\n";
	}
	if (num_chars_v == -1)
	{
		free(*input);
		write(STDIN_FILENO, "exit\n", 6);
		exit(EXIT_FAILURE);
	}
	else
	{
		/* if string ends with `\n` replace it with null terminate. */
		if ((*input)[num_chars_v - 1] == '\n')
		{
			(*input)[num_chars_v - 1] = '\0';
		}
	}
	/* call the tokenize helper function to split */
	 /* string values by " " aand store them in an array */
	args_v = tokenize_f(*input, " ");
	return (args_v);
}
