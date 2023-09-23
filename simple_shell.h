#ifndef SIMPLE_SHELL_H
#define SIMPLE_SHELL_H


/* include needed header files*/
#include <stdlib.h>
#include <unistd.h>
#include <errno.h>
#include <sys/wait.h>
#include <sys/types.h>
#include <sys/stat.h>


/* define macros */
#define env environ
#define BUFFER_SIZE 1024
#define CHECK_DOLLAR_SIGN(s) ((s[0] == '$') ? 1 : 0)


/**
 * Description: list - a linked list of environment variables
 * @name: name of the variable
 * @value: value of the variable
 * @next: pointer to next node
 */
typedef struct list
{
	char *name;
	char *value;
	struct list *next;
} list;



/* global vaiables */
extern char **environ;


/* declaring functions prototype*/
int execute_f(char **args_v, int len, list **head_env, list **tail_env);
int run_built_in(char **args, int len, list **head_env, list **tail_env);
int _setenv_f(list **head, list **tail, char *name, char *value);
int parse_f(char ***buffer, char *input, const char *delim);
int valid_command_f(char **command, list *head_env);
int _strcmp_f(const char *s1, const char *s2);
int read_f(char **buffer, list **head_env, int l_err);
int _exit_f(char **tokens_v, int cnt_v);
int _env_f(int args_n, list *head);
int built_in_cm(char **command);
int _strlen_f(const char *s);
int _putchar_f(char c);
int _atoi_f(char *s);


char *_strtok_f(char *str, const char *delim);
char *_strcpy_f(char *dest, const char *src);
char *_strcat_f(char *dest, const char *src);
char *_getenv_f(list *var, char *str);
char *_atoa_f(int num);


void add_env_f(char **command, int len, list **head, list **tail);
void _cd_f(char **args, int size, list **head, list **tail);
void _unsetenv_f(list **head, list **tail, char *name);
void error_handling_f(char *str, int stat);
void cpy_env_f(list **head, list **tail);
void free_list_f(list **head);
void _puts_f(const char *str);
void simple_shell(void);
void _echo_f(char **args);
void prompt_f(void);


ssize_t _getline_f(char **lineptr, size_t *n, int stream);

#endif /* SIMPLE_SHELL_H */
