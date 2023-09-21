#include "simple_shell.h"

/* declare functions */
int numberlen_f(int num);
void rev_string_f(char *s, int l);

/**
 * _atoa_f - converts a number to a string
 * @num: number
 *
 * Return: Pointer to string
*/
char *_atoa_f(int num)
{
	char *str_v = malloc(sizeof(char) * (numberlen_f(num) + 1));
	int is_neg_v = 0, i_v = 0;

	if (num == 0)
	{
		str_v[i_v] = '0';
		str_v[i_v + 1] = '\0';
		return (str_v);
	}
	if (num < 0)
	{
		is_neg_v = 1;
		num = -num;
	}

	/* convert digits to chars in rev order */
	while (num)
	{
		str_v[i_v] = num % 10 + '0';
		num /= 10;
		i_v++;
	}

	if (is_neg_v)
		str_v[i_v++] = '-';

	/* reverse the string */
	rev_string_f(str_v, i_v);
	str_v[i_v] = '\0';
	return (str_v);
}

/**
 * numberlen_f - gets the length of a given number
 * @num: number
 *
 * Return: length of num
*/
int numberlen_f(int num)
{
	int i_v = 0;

	if (num == 0)
		return (1);

	while (num)
	{
		num /= 10;
		i_v++;
	}

	return (i_v);
}

/**
 * rev_string_f - reverse a given string
 * @s: pointer to string
 * @l: length of the string
*/
void rev_string_f(char *s, int l)
{
	int i;
	char tmp;

	for (i = 0; i < l / 2; i++)
	{
		tmp = s[i];
		s[i] = s[l - i - 1];
		s[l - i - 1] = tmp;
	}
}
