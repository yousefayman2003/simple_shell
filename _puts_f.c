#include "simple_shell.h"

/**
 *  _puts_f - prints a string to stdout
 *
 *  @str: pointer to string
*/

void _puts_f(const char *str)
{
	while (*str != '\0')
	{
		_putchar_f(*str + 0);
		str++;
	}
}
