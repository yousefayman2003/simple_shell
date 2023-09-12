#include "simple_shell.h"

/**
 * Description: _env_f - implementation of built-in command env
 * Input: NULL
 * Return: NULL
 */
void _env_f()
{
	int i = 0;

	while (env[i] != NULL)
	{
		_puts_f(env[i]);
		_putchar_f('\n');
		i++;
	}
}
