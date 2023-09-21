#include "simple_shell.h"
/* declare function */
void free_tokens2_f(char ***tokens_v, int cnt_v);

/**
 * _exit_f - Exits the program with a specified exit value.
 * @tokens_v: double pointer to a arguments array.
 * @cnt_v: number of tokens in the array.
*/
void _exit_f(char ***tokens_v, int cnt_v)
{
	char copy[256];
	int value;

	if (cnt_v == 2)
	{
		_strcpy_f(copy, (*tokens_v)[1]);
                value = _atoi_f(copy);
		free_tokens2_f(tokens_v, cnt_v);
		if (value == -1)
		{
			print_error_f(copy, 3);
			exit(EXIT_SUCCESS);
		}
		exit(value);
	}
	else if (cnt_v > 2)
	{
		_strcpy_f(copy, (*tokens_v)[1]);
		value = _atoi_f(copy);
		_puts_f("exit\n");
		if (value != -1)
			print_error_f("exit", 2);
		else if (value == -1)
		{
			free_tokens2_f(tokens_v, cnt_v);
			print_error_f(copy, 3);
			exit(EXIT_SUCCESS);
		}
	}
	else
	{
		free_tokens2_f(tokens_v, cnt_v);
		exit(EXIT_SUCCESS);
	}
}
/**
 * Description: free_tokens2_f - frees memory of 2d array
 * Input:
 *	@tokens_v (2d): 2d array called by reference
 *	@cnt_v: number of tokens inside the array
 * Return: NULL
 */
void free_tokens2_f(char ***tokens_v, int cnt_v)
{
	int i = 0;

        if (*tokens_v == NULL)
                free(*tokens_v);

        for (i = 0; i < cnt_v; i++)
	{
                free((*tokens_v)[i]);
        }
        free(*tokens_v);
}
