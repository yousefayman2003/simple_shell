#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/**
 * Description: list - struct for creating a linked list
 * @str: (string): the string value of each node
 * @next: (pointer to list node): pointer points to next node
 */
typedef struct list
{
	char *str;
	struct list *next;
} list;

/* global variables */
extern char **environ;
list *head = NULL, *tail = NULL;


/* functions declarations */
void _environ_f();
void _setenv_f(char *);
void free_list();
void _unsetenv_f(char *);
char *_getenv_f(char *);
/**
 * Description: main - entry point
 * Input: NULL
 * Return: NULL
 */
int main()
{
	_environ_f();
	free_list();
	return (0);
}



void _environ_f()
{
	int i = 0;
	list *temp;
	
	while (environ[i] != NULL)
	{
		_setenv_f(environ[i]);
		i++;
	}
	
	_unsetenv_f("PATH");
	
	temp = head;
	while (temp)
	{
		printf("%s\n", temp->str);
		temp = temp->next;
	}

	printf("\n\nHOSTNAME = %s\n", _getenv_f("HOSTNAME"));
}



/**
 * Description: _setenv_f - insert a new node in a linked list
 * Input:
 *	@data: the string value of the node
 * Return: NULL
 */
void _setenv_f(char *data)
{
	/* allocate memory for a new node */
	list *node = malloc(sizeof(list));
	if (!node)
		perror("can't allocate memory");

	/* allocate memory for the string value of the node */
	node->str = malloc(strlen(data) + 1);
	node->next = NULL;
	if (!node->str)
	{
		free(node);
		perror("can't allocate memory");
	}
	strcpy(node->str, data);
	
	/* insert the new node into a linked list */
	if (head)
	{
		tail->next = node;
		tail = node;
	}
	else
	{
		head = node;
		tail = node;
	}
}



/**
 * Description: _unsetenv_f - remove an envrionment variable
 * Input:
 *	@name: (string): name of the envrionment variable
 * Return: NULL
 */
void _unsetenv_f(char *str)
{
	int i;
	list *curr = head, *prev = NULL;
	
	while (curr)
	{ 
		i = 0;
		while ((curr->str)[i] == str[i])
		{
			i++;
			continue;
		}
		if ((curr->str)[i] == '=' && str[i] == '\0')
		{
			if (prev)
			{
				prev->next = curr->next;
				free(curr->str);
				free(curr);
				return;
			}
			else
			{
				free(curr->str);
				free(curr);
				return;
			}
		}
		prev = curr;
		curr = curr->next;
	}
}



/**
 * Description: free_environ - free memory of a linked list that includes a str
 * Input: NULL
 * Return: NULL
 */
void free_list()
{
	list *temp;
	
	while (head)
	{
		temp = head;
		head = head->next;
		free(temp->str);
		free(temp);
	}
}



/**
 * Description: _getenv_f - get the value of an environment variable
 * Input:
 *	@name: (string): name of the environment variable
 * Return:
 *	value of the varible if it's found
 *	NULL otherwise
 */
char *_getenv_f(char *str)
{
	int i;
	list *var = head;
	
	while (var)
	{ 
		i = 0;
		while ((var->str)[i] == str[i])
		{
			i++;
			continue;
		}
		if ((var->str)[i] == '=' && str[i] == '\0')
			return (&(var->str)[i + 1]);
		var = var->next;
	}
}
