#include "simple_shell.h"

/**
 * _getline_f - reads an entire line from stream
 * @lineptr: pointer to the buffer that will store the string
 * @n: pointer to the buffer size
 * @stream: stream to read from
 *
 * Return: On success, the num of char read,
 *      On error or EOF -1
*/
ssize_t _getline_f(char **lineptr, size_t *n, int stream)
{
	static char buffer_v[BUFFER_SIZE];
	int bytes_read_v = 0, i = 0, j = 0;

	if (*n == 0 || !(*lineptr))
	{
		*n = BUFFER_SIZE;
		*lineptr = malloc(sizeof(char) * (*n));
		if (!(*lineptr))
			return (-1);
	}
	while (1)
	{
		if (j >= bytes_read_v)
		{
			bytes_read_v = read(stream, buffer_v, BUFFER_SIZE);
			j = 0;
		}
		if (bytes_read_v == 0 ||  bytes_read_v == -1)
			return (-1);
		if ((size_t)i > *n)
		{
			*n += BUFFER_SIZE;
			*lineptr = realloc(*lineptr, *n);
			if (!(*lineptr))
				return (-1);
		}
		if (buffer_v[j] == '\n')
		{
			buffer_v[j] = '\0';
			i++;
			j++;
			break;
		}
		(*lineptr)[i] = buffer_v[j];
		i++;
		j++;
	}
	if (i == 0 || bytes_read_v == 0)
		return (-1);
	return (i);
}
