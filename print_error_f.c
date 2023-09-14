#include "simple_shell.h"

int pchar_err(char);
int pstr_err(char *);

void print_error_f(char *str, int stat)
{
	switch (stat)
	{
		case 1:
			pstr_err("Error: Couldn't allocate memory\n");
			exit(EXIT_FAILURE);
			break;
		case 127:
			pstr_err("simple_shell: ");
			pstr_err(str);
			pstr_err(": command not found\n");
			break;
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

	}
	
}

int pchar_err(char c)
{
	write(2, &c, 1);
	return (1);
}


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
