#include "simple_shell.h"


/**
 * Description: _strtok_f -  breaks string str into a series of tokens
 *		using the delimiter delim.
 *
 * when the first charcter of delim is detected in the buffer
 * loop over the remaining charaters of delim if it's found
 * in same sequence change the first char of delim in buffer
 * to be a null character and return a char pointer points to
 * the start of the buffer to that null charactr (token)
 *
 * Input:
 *	@str: (string): The contents of this string are modified
 *		and broken into smaller strings (tokens).
 *	@delim: (string): This is the C string containing the delimiters.
 *		These may vary from one call to another.
 * Return:
 *	This function returns a pointer to the first token found in the string.
 *	A null pointer is returned if there are no tokens left to retrieve.
 */
char *_strtok_f(char *str, const char *delim)
{
	int i = 0, j, temp, ident;
	static char *buffer;
	char *token, *start_buffer, *end_token;

	if (str != NULL)
		buffer = str;
	if (!buffer || *buffer == '\0')
		return (NULL);
	token = buffer;
	while (buffer[i] != '\0')
	{
		j = 0;
		if (buffer[i] == delim[j++])
		{
			ident = 0;
			temp = i;
			end_token = &buffer[temp++];
			start_buffer = &buffer[temp];
			while (delim[j] != '\0')
			{
				if (*start_buffer != delim[j])
				{
					ident = -1;
					break;
				}
				temp++;
				j++;
				start_buffer++;
			}
			if (ident == 0)
			{
				buffer = start_buffer;
				*end_token = '\0';
				return ((*token != '\0') ? token : _strtok_f(NULL, delim));
			}
		}
		i++;
	}
	buffer = NULL;
	return (token);
}
