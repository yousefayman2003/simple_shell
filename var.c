#include "simple_shell.h"

void slice_f(const char *string, char *buff, unsigned int start, unsigned int end);

/**
 * handle_variable_f - Handles variables replacement
 * @command - pointer to string of given variable
*/
void handle_variable_f(char ***args)
{
	char *command = (*args)[1], *buff, *pid, *value;
	unsigned int size = _strlen_f(command);

	if (_strcmp_f(*args[0], "echo") != 0)
			return;
	
	buff = malloc(sizeof(char) * (size + 1));
	if (size == 2)
	{
		if (command[1] == '?')
		{
			value = getenv("EXIT_STATUS");
			if (!value)
				_putchar_f('\n');
			else
			{
				_puts_f(value);
				_putchar_f('\n');
			}
		}
		else if (command[1] == '$')
		{
			pid = _atoa_f(getpid());
			_puts_f(pid);
			_putchar_f('\n');
			free(pid);
		}
	}
	else
	{
		slice_f(command, buff, 1, size + 1);
		value = getenv(buff);
		 if (!value)
                 	_putchar_f('\n');
		 else
		{
                	_puts_f(value);
                 	_putchar_f('\n');
		}
	}
	free(buff);
}

/**
 * slice_f - slices a given string
 * @string : pointer to string
 * @buff : pointer to string
 * @start: start index
 * @end: end index
*/
void slice_f(const char *string, char *buff, unsigned int start, unsigned int end)
{
	unsigned int i_v = 0, j_v = 0;

	for (i_v = start; i_v <= end; i_v++)
	{
		buff[j_v] = string[i_v];
		j_v++;
	}
	buff[j_v] = 0;
}
