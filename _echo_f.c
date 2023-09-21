#include "simple_shell.h"

/* declare helper functions */
int dollar_sign_found(void);
int isalphanum_f(int c);
void char_cat_f(char **s, char c);

/* global variables */
char *command = NULL, *value = NULL, *buff = NULL, *pid = NULL;
unsigned int j = 0, size = 0, flag = 0;

/**
 * _echo_f - prints argument to stdout
 * @args: 2D array of strings
*/
void _echo_f(char **args)
{
	int is_break = -3;
	unsigned int i = 1;

	while (args[i])
	{
		command = args[i];
		size = _strlen_f(command);
		j = 0;
		while (command[j])
		{
			flag = 0;
			if (command[j] == '$')
				is_break = dollar_sign_found();
			if (is_break == -1)
				break;
			else if (is_break >= 0)
			{
				while (command[j])
				{
					if (command[j] == '$')
					{
						is_break = -3;
						break;
					}
					else if (isalphanum_f(command[j]))
						break;
					_putchar_f(command[j]);
					j++;
				}
				if (is_break == -3)
					continue;
				flag = 1;
			}
			if (!flag)
				_putchar_f(command[j]);
			j++;
		}
		if (args[i++])
			_putchar_f(' ');
	}
	_putchar_f('\n');
}


/**
 * dollar_sign_found - handle varialbe replacement
 *
 * Return: k OR -1 to break out of the loop and
 * to check for non alphanum, -2 to continue
*/
int dollar_sign_found(void)
{
	if ((size - j) >= 2)
	{
		if (command[j + 1] == '?')
		{
			value = getenv("EXIT_STATUS");
			if (!value)
				_putchar_f('0');
			else
				_puts_f(value);
			j++;
			flag = 1;
		}
		else if (command[j + 1] == '$')
		{
			pid = _atoa_f(getpid());
			_puts_f(pid);
			free(pid);
			j++;
			flag = 1;
		}
		else
		{
			int k = j + 1, no_var = -1;

			buff = malloc(sizeof(char) * 2);
			buff[0] = '\0';
			while (command[k])
			{
				char_cat_f(&buff, command[k]);
				value = getenv(buff);
				if (value && (!isalphanum_f(command[k + 1])))
				{
					_puts_f(value);
					no_var = k;
					j = k + 1;
					break;
				}
				k++;
			}
			free(buff);
			return (no_var);
		}
	}
	return (-2);
}
/**
 * isalphanum_f - checks if a character is an alphabet or a number
 * @c: character
 * Return: 1 if the character is an alphabet, else 0
*/
int isalphanum_f(int c)
{
	if ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z'))
		return (1);
	else if ((c >= '0' && c <= '9'))
		return (1);

	return (0);
}

/**
 * char_cat_f - concat a character to the end of a string
 * @s: pointer of pointer of string
 * @c: character to append
*/
void char_cat_f(char **s, char c)
{
	int len = _strlen_f(*s);
	*s = realloc(*s, len + 2);
	(*s)[len] = c;
	(*s)[len + 1] = '\0';
}
