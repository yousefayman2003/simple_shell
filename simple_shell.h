#ifndef SIMPLE_SHELL_H
#define SIMPLE_SHELL_H

/* include needed header files*/
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include<sys/wait.h>
#include  <sys/types.h>
#include <string.h>

/* declaring functions prototype*/
int _putchar_f(char c);
void _puts_f(const char *str);
int _strcmp_f(const char *s1, const char *s2);
int _strlen_f(const char *s);
char *_strcpy_f(char *dest, const char *src);
void prompt_f(void);
char **read_f(void);
char **tokenize_f(const char *input, const char *delimiter);
void execute_f(const char *command, char **args, char **env);

#endif /* SIMPLE_SHELL_H */
