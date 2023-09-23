#include "simple_shell.h"

/**
 *  _strcpy_f - copys a string
 *
 *  @dest: destination string to copy to
 *  @src: source string to copy from
 *
 *  Return: pointer to copied string
*/
char *_strcpy_f(char *dest, const char *src)
{
	int i_v = -1;

	if (src == NULL)
	{
		dest = NULL;
		return (dest);
	}
	do {
		i_v++;
		dest[i_v] = src[i_v];
	} while (src[i_v] != '\0');

	return (dest);
}
