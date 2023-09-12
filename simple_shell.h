#ifndef SIMPLE_SHELL_H
#define SIMPLE_SHELL_H

/* include needed header files*/
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include<sys/wait.h>
#include  <sys/types.h>
#include <string.h>
#include <sys/stat.h>

/* define macros */
#define env environ

/* export global vaiables */
extern char **environ;

/* declaring functions prototype*/
int _putchar_f(char c);
int _strcmp_f(const char *s1, const char *s2);
int _strlen_f(const char *s);
char *_strcpy_f(char *dest, const char *src);
char *_strcat_f(char *dest, const char *src);
char **read_f(void);
char **tokenize_f(const char *input, const char *delimiter);
void prompt_f(void);
void execute_f(const char *pathname, char ***args);
void print_error_f(void);
void _puts_f(const char *str);
void print_error2_f(char *str, int stat);
void _env_f();

#endif /* SIMPLE_SHELL_H */
