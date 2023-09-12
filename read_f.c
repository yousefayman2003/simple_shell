#include "simple_shell.h"


int is_built_in_f(char *);
int find_run_file_f(char ***);

/**
 * tokenize_f - tokenize a string with a specific delimiter
 * @input: input string
 * @delimiter: given delimiter to split upon
 *
 * Return: a pointer to an array of strings
*/
char **tokenize_f(const char *input, const char *delimiter)
{
	char *token_v,  *copy_v;
	char **tokens_v = NULL;
	int cnt_v = 0;

	/* Allocate memory for copy */
	copy_v = malloc(sizeof(char) * (_strlen_f(input) + 1));
	if (!copy_v)
		print_error_f();
	/* Copying input string */
	_strcpy_f(copy_v, input);
	/* Tokenize copied string */
	token_v = strtok(copy_v, delimiter);

	while (token_v != NULL)
	{
		/* Reallocate memory for tokens */
		tokens_v = realloc(tokens_v, (cnt_v + 1) * sizeof(char *));
		/* Allocate memory for token */
		tokens_v[cnt_v] = malloc(sizeof(char) * (_strlen_f(token_v) + 1));
		if (!token_v || !tokens_v[cnt_v])
			print_error_f();
		/* Copying the token string */
		_strcpy_f(tokens_v[cnt_v], token_v);
		token_v = strtok(NULL, delimiter);
		cnt_v++;
	}
	/* Reallocate memory for tokens to terminate array with null */
	tokens_v = realloc(tokens_v, (cnt_v + 1) * sizeof(char *));
	if (!tokens_v)
		print_error_f();
	tokens_v[cnt_v] = NULL;
	/* Free allocated memory */
	free(copy_v);

	return (tokens_v);
}

/**
 * read_f - reads input from standard input.
 *
 * Return: input string.
*/
char **read_f(char **input)
{
	char **args_v = NULL;
	int num_chars_v;
	/* Ignoring size of buffer */
	size_t size_v = 2;
	/* get input from standard input*/
	num_chars_v = getline(input, &size_v, stdin);

	/* check if the user enters \n */
	if (size_v == 2)
	{
		*input = "\\n";
	}
	if (num_chars_v == -1)
	{
		free(*input);
		write(STDIN_FILENO, "exit\n", 6);
		exit(EXIT_FAILURE);
	}
	else
	{
		/* if string ends with `\n` replace it with null terminate. */
		if ((*input)[num_chars_v - 1] == '\n')
		{
			(*input)[num_chars_v - 1] = '\0';
		}
	}
	/* call the tokenize helper function to split */
	 /* string values by " " aand store them in an array */
	args_v = tokenize_f(*input, " ");
	return (args_v);
}


/*
	run the command if it's valid or print an error 
                file_stat_v = find_run_file_f(&args_v, &exe_file_v);
                if (file_stat_v == -1)
                        print_error2_f(args_v[0], 127);
*/
/*
 * Description: find_run_file_f - find absoluate path of an executable file
 *              and run it if it found
 * Input:
 *      @argv_v: (array of strings): arguments of the command
 *      @exe_files_v: (string): location of exeutable file of the command
 * Return:
 *      - 0 if the command empty, from our buil_in funcs, or its path is found
 *      - -1 if we don't find the file
 */
int find_run_file_f(char ***argv_v)
{
        char *str_v, *token_v, *exe_dirs_v, *exe_file_v;
        int pathname_len_v = _strlen_f(*argv_v[0]);
        struct stat sb_v;

        /* reprompt if the user enter an empty command */
        if (!*argv_v)
                return (0);
        /* run a file (command) if the user write its right absolute path */
        if (stat(*argv_v[0], &sb_v) == 0)
        {
                execute_f(*argv_v[0], argv_v);
                return (0);
        }
        else if (is_built_in_f(*argv_v[0]) == 0)
                return (0);
        else
        {
                /* get the locations of exeutable files as a string */
                str_v = getenv("PATH");
                exe_dirs_v = malloc(_strlen_f(str_v) + 1);
                if (!exe_dirs_v)
                        print_error_f();
                /* split directories locations for searching in each directory */
                exe_dirs_v = _strcpy_f(exe_dirs_v, str_v);
                token_v = strtok(exe_dirs_v, ":");
                while (token_v != NULL)
                {
                        exe_file_v = malloc(_strlen_f(token_v) + pathname_len_v + 2);
                        if (!exe_file_v)
                                print_error_f();
                        exe_file_v = _strcpy_f(exe_file_v, token_v);
                        exe_file_v = _strcat_f(_strcat_f(exe_file_v, "/"), *argv_v[0]);
                        /* run it if we found it in that directory */
                        if (stat(exe_file_v, &sb_v) == 0)
                        {
                                free(exe_dirs_v);
                                execute_f(exe_file_v, argv_v);
				free(exe_file_v);
                                return (0);
                        }
                        token_v = strtok(NULL, ":");
                        free(exe_file_v);
                }
        }
        free(exe_dirs_v);
        return (-1);
}



/**
 * Description: is_built_in_f - check if the given command is a built_in cm
 *              but we reimplemented it
 * Input:
 *      @cm_v: (string): given command from a user
 * Return:
 *      - 0 if it's a built_in command
 *      - -1 otherwise
 */
int is_built_in_f(char *cm_v)
{
        char *special_v[2] = {"exit", "env"};
        int i_v, not_ident_v;

        for (i_v = 0; i_v < 2; i_v++)
        {
                not_ident_v = _strcmp_f(cm_v, special_v[i_v]);
                if (!not_ident_v)
                {
                        switch (i_v)
                        {
                                case 0:
                                        exit(EXIT_SUCCESS);
                                case 1:
                                        _env_f();
                                        return (0);
                        }
                }
        }
        return (-1);
}
