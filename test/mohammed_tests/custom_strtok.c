#include <stdio.h>
#include <string.h>
#include <stdlib.h>

/* function declaration */
char *_strtok_f(char *str, const char *delim);
void test(char *str, const char *delim);


/**
 * Description: main - entry point
 * Input: NULL
 * Return: NULL
 */
int main()
{
	char test1[] = "ls -a -l -r";
	char test2[] = "Hello, World! This is a test.";
	char test3[] = "";
	char test4[] = "        ";
	char test5[] = "/bin/ls who/ s am i";
	
	/* result = [ls, -a, -l, -r] */
	test(test1, " "); 
	/* result = [Hello, World!,  This is a test.] */
	test(test2, "! ");
	/* result = [""] */
	test(test3, " ");
	/* result = ["        "] */
	test(test4, "");
	/* result = [/bin/ls who, s am, i] */
	test(test5, "/ ");

	return (0);
}



/**
 * Description: _strtok_f -  breaks string str into a series of tokens 
 *		using the delimiter delim.
 * Input:
 *	@str: (string): The contents of this string are modified
 *	 		and broken into smaller strings (tokens).
 *	@delim: (string): This is the C string containing the delimiters.
 *			These may vary from one call to another.
 * Return:
 * 	This function returns a pointer to the first token found in the string.
 *	A null pointer is returned if there are no tokens left to retrieve.
 */
char *_strtok_f(char *str, const char *delim)
{
	static char *buffer = NULL;
	char *token, *start_buffer, *end_token;
	unsigned int i, j, temp;
	int ident;

	if (str != NULL)
		buffer = str;

	if (buffer == NULL)
		return (NULL);

	token = buffer;
	i = 0;

	while (buffer[i] != '\0')
	{
		j = 0;
		
		/* when the first charcter of delim is detected in the buffer
		 * loop over the remaining charaters of delim if it's found
		 * in same sequence change the first char of delim in buffer
		 * to be a null character and return a char pointer points to
		 * the start of the buffer to that null charactr (token)
		 */
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
				return ((*token != '\0') ? token:_strtok_f(NULL, delim));
			}
		}
		i++;
	}
	buffer = NULL;
	return (token);
}



/**
 * Description: test - display the output (tokens) of _strtok_f.
 * Input:
 * 	@str: (string): string of the test
 * 	@delim: (string): delim of the test
 * Return:
 */
void test(char *str, const char *delim)
{
	char *token1;
	static int count = 1;
	int i = 1;

	printf("Test-%d\n######\n", count);
	printf("string = \"%s\"\n", str);
	printf("delimeter = \"%s\"\n\n", delim);

	token1 = _strtok_f(str, delim);
	
	while (token1 != NULL)
	{
		printf("strtok token-%i = \"%s\"\n", i++, token1);
		token1 = _strtok_f(NULL, delim);
	}
	printf("\n");
	count++;
}
