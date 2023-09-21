#include "simple_shell.h"

/**
* _atoi_f - convert a string to an integer
* @s: input
* Return: integer
*/
int _atoi_f(char *s)
{
	unsigned int num_v = 0;
	int sign_v = 1;
	int non_numeric_flag_v = 0;

	while (*s)
	{
		if (*s == '-')
			sign_v *= -1;
		else if (*s >= '0' && *s <= '9')
			num_v = (num_v * 10) + (*s - '0');
		else
		{
			non_numeric_flag_v = 1;
			break;
		}
		s++;
	}
	if (non_numeric_flag_v)
		return (-1);

	return (num_v * sign_v);
}
