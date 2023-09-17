#include "simple_shell.h"

/* function declarations */
int fcheck_run_f();
int fsearch_run_f();
void tokenize_f();
void free_tokens_f();

/* global variables */
char *input_v, pathname_v[1024];
char **tokens_v;
int pathname_len_v, cnt_v, i = 0;


/**
 * read_f - reads input from standard input.
 *
*/
void read_f()
{
	int num_chars_v, file_stat_v;
	size_t size_v = 0;
	
	/* get input from standard input*/
	input_v = NULL;
	num_chars_v = _getline_f(&input_v, &size_v, STDIN_FILENO);

	if (num_chars_v == -1)
	{
		free(input_v);
		write(STDIN_FILENO, "exit\n", 6);
		exit(EXIT_FAILURE);
	}
	else if (num_chars_v > 1)
	{
		/* call the tokenize helper function to split 
	 	* string values by " " aand store them in an args_v */
		tokenize_f(" ");
		free(input_v);

		/* set the name of the command and its length */
		pathname_len_v = _strlen_f(tokens_v[0]);
		if (pathname_len_v > 1023)
		{
			free_tokens_f();
			print_error_f("was wrong", 127);
		}
		_strcpy_f(pathname_v, tokens_v[0]);

		/* run the command if it's valid or print an error */
		file_stat_v = fcheck_run_f();
		if (file_stat_v == -1)
			print_error_f(pathname_v, 127);

		free_tokens_f();
	}
	else
		free(input_v);
}



/**
 * tokenize_f - tokenize a string with a specific delimiter
 * @delimiter: given delimiter to split upon
 *
 * Return: number of string elements in the array
*/
void tokenize_f(const char *delimiter)
{
	char *token_v;
	cnt_v = 0;

	/* Tokenize copied string */
	token_v = strtok(input_v, delimiter);
	tokens_v = NULL;

	while (token_v != NULL)
	{
		/* Rieallocate memory for tokens */
		tokens_v = realloc(tokens_v, (cnt_v + 1) * sizeof(char *));
		if (!tokens_v)
		{
			free(input_v);
		       	free_tokens_f();
			print_error_f("", 1);
		}
		/* Allocate memory for token */
		tokens_v[cnt_v] = malloc(sizeof(char) * (_strlen_f(token_v) + 1));
		if (!tokens_v[cnt_v])
		{	free(input_v);
		       	free_tokens_f();
			print_error_f("", 1);
		}
		/* Copying the token string */
		_strcpy_f(tokens_v[cnt_v], token_v);
		token_v = strtok(NULL, delimiter);
		cnt_v++;
	}
	/* Reallocate memory for tokens to terminate array with null */
	tokens_v = realloc(tokens_v, (cnt_v + 1) * sizeof(char *));
	 if (!tokens_v)
	{
		free(input_v);
		free_tokens_f();
		print_error_f("", 1);
	}
	tokens_v[cnt_v] = NULL;
}



/*
 * Description: fcheck_run_f - run a command if its executable file is found
 * Input: NULL (use global variabels)
 * Return:
 *      - 0 if the command empty, from our buil_in funcs, or its path is found
 *      - -1 if we don't find the file
 */
int fcheck_run_f()
{
        struct stat sb_v;

	/* run a file (command) if the user write its right absolute path */
        if (stat(pathname_v, &sb_v) == 0)
        {
                execute_f(pathname_v, tokens_v);
                return (0);
        }
	/* when the user write exit, exit the shell */
        else if (_strcmp_f(pathname_v, "exit") == 0)
	{
                _exit_f(&tokens_v, cnt_v);
		return(0);
	}
	/* when the user write env, print the enviroment variables */
	else if (_strcmp_f(pathname_v, "env") == 0)
	{	
		_env_f();
		return (0);
	}
	else if (_strcmp_f(pathname_v, "cd") == 0)
	{
		_cd_f(&tokens_v, cnt_v);
		return (0);
	}
	else if ((cnt_v == 2) && (CHECK_DOLLAR_SIGN(tokens_v[1])))
	{
		handle_variable_f(&tokens_v);
		return (0);
	}
	/* search about the exe file of a command and run it if it's found */
	return (fsearch_run_f());
}



/**
 * Description: 
 *	fsearch_run_f - search about location of an exe file and run if it's found
 * Input: use first element of tokens (global var) to get the file name
 * Return:
 *	- 0 if it is found
 *	- -1 otherwise
 */
int fsearch_run_f()
{
	char *str_v, *token_v, *exe_dirs_v, *exe_file_v;
	struct stat sb_v;
	
	/* get the locations of exeutable files in the user system */
        str_v = getenv("PATH");
        exe_dirs_v = malloc(_strlen_f(str_v) + 1);
        if (!exe_dirs_v)
	{
		free_tokens_f();
		print_error_f("", 1);
	}

        /* split directories locations for searching in each directory */
        exe_dirs_v = _strcpy_f(exe_dirs_v, str_v);
        token_v = strtok(exe_dirs_v, ":");
	pathname_len_v = _strlen_f(pathname_v);

        while (token_v != NULL)
	{
        	exe_file_v = malloc(_strlen_f(token_v) + pathname_len_v + 2);
	        if (!exe_file_v)
		{
			free(exe_dirs_v); free_tokens_f();
                        print_error_f("", 1);
		}
                exe_file_v = _strcpy_f(exe_file_v, token_v);
                exe_file_v = _strcat_f(_strcat_f(exe_file_v, "/"), pathname_v);

		/* run it if we found it in the current directory */
                if (stat(exe_file_v, &sb_v) == 0)
      	        {
                	free(exe_dirs_v);
                        execute_f(exe_file_v, tokens_v);
			free(exe_file_v);
                        return (0);
                }
             	token_v = strtok(NULL, ":");
                free(exe_file_v);
	}
	free(exe_dirs_v);
	return (-1);
}
 


/**
 * Description: free_tokens_f - frees memory of 2d array
 * Input:
 *	@array: (2d): 2d array argument called by reference
 * Return: NULL
 */
void free_tokens_f()
{
	int i = 0;

        if (tokens_v == NULL)
                free(tokens_v);

        for (i = 0; i < cnt_v; i++)
	{
                free(tokens_v[i]);
        }
        free(tokens_v);
}
