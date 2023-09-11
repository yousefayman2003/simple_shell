#include "simple_shell.h"

/**
 * Description: _strcat - append n character from src string to dest string
 *
 * Input:
 *	@dest: [char pointer] --> points to the first char of dest string
 *	@src: [const char pointer] --> points to the first char of src string
 *      @n: [int] The number of character that will be appended from src
 *
 * Return: pointer to the destination string
 */

char *_strcat_f(char *dest, const char *src)
{
	int lchar, i = 0;

	lchar = _strlen_f(dest);

	while (src[i] != '\0')
	{
		dest[lchar] = src[i];
		i++;
		lchar++;
	}

	return (dest);
}
