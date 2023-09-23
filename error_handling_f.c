#include "simple_shell.h"

int pchar_err(char);
int pstr_err(char *);


/**
 * Description: error_handling_f - display the appropriate message
 *		for each error
 * Input:
 *	@str: (string): string to print
 *	@stat: (int): error status
 * Return: NULL
 */
void error_handling_f(char *str, int stat)
{
	switch (stat)
	{
		case -2:
			pstr_err("Error: can't open a new process\n");
			exit(EXIT_FAILURE);
		case -1:
			pstr_err("Error: can't allocate memory\n");
			exit(EXIT_FAILURE);
		case 0:
			_puts_f(str);
			_putchar_f('\n');
			break;
		case 1:
			exit(EXIT_FAILURE);
		case 2:
			pstr_err("simple_shell: ");
			pstr_err(str);
			pstr_err(": too many arguments\n");
			break;
		case 3:
			pstr_err("simple_shell: ");
			pstr_err("exit: ");
			pstr_err(str);
			pstr_err(": numeric argument required\n");
			break;
		case 5:
			pstr_err("simple_shell: 1: ");
			pstr_err("cd: ");
			pstr_err("can't cd to");
			pstr_err(str);
			pstr_err("\n");
			break;
		case 127:
			pstr_err("./hsh: 1: ");
			pstr_err(str);
			pstr_err(": not found\n");
			break;
	}
}


/**
 * Description: pchar_err - prints a char to stderr
 * Input:
 *	@c: (char): the printed char
 * Return: always 1
 */
int pchar_err(char c)
{
	write(2, &c, 1);
	return (1);
}


/**
 * Description: pstr_err - prints a string to stderr
 * Input:
 *	@str: (string): the printed string
 * Return: number of printed chars
 */
int pstr_err(char *str)
{
	int i = 0;

	while (str[i] != '\0')
	{
		pchar_err(str[i]);
		i++;
	}
	return (i + 1);
}
