#include "simple_shell.h"

/**
 * Description: _env_f - prints all envrionment variables
 * Input:
 *	@args_n: number of the array that includes the command and its arguments
 *	@head: (pointer to linked list): points to the first node in the list
 * Return:
 *	- 0 always success
 */
int _env_f(int args_n, list *head)
{
	if (args_n != 1)
	{
		error_handling_f("env", 2);
		return (0);
	}
	while (head)
	{
		_puts_f(head->name);
		_putchar_f('=');
		_puts_f(head->value);
		_putchar_f('\n');
		head = head->next;
	}
	return (0);
}
