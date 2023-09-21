#include "simple_shell.h"

/**
 * _strcmp_f - compared two given strings
 * @s1: first string
 * @s2: second string
 *
 * Return: positive number if s1 > s2
 *		negative number if s1 < s2
 *		zero if s1 = s2
*/
int _strcmp_f(const char *s1, const char *s2)
{
	unsigned int diff_v;

	while (*s1)
	{
		if (*s1 != *s2)
		{
			break;
		}
		s1++;
		s2++;
	}
	diff_v = *(const unsigned char *)s1 - *(const unsigned char *)s2;
	return (diff_v);
}
