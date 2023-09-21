#include "simple_shell.h"

/**
 * _exit_f - Exits the program with a specified exit value.
 * @tokens_v: double pointer to a arguments array.
 * @cnt_v: number of tokens in the array.
 *
 * Return: exit status
*/
int _exit_f(char **tokens_v, int cnt_v)
{
	int value;

	if (cnt_v == 2)
	{
		value = _atoi_f(tokens_v[1]);
		if (value == -1)
		{
			error_handling_f(tokens_v[1], 3);
			return (0);
		}
		return (value);
	}
	else if (cnt_v > 2)
	{
		value = _atoi_f(tokens_v[1]);
		_puts_f("exit\n");
		if (value != -1)
			error_handling_f("exit", 2);
		else if (value == -1)
		{
			error_handling_f(tokens_v[1], 3);
			return (0);
		}
	}
	return (0);
}
