#include "simple_shell.h"

/**
 * Description: free_list_f - free memory of a linked list that includes a str
 * Input:
 *	@head: (pointer to linked list): the head pointer of a linked list
 * Return: NULL
 */
void free_list_f(list **head)
{
	list *temp;

	while (*head)
	{
		temp = *head;
		*head = (*head)->next;
		free(temp->name);
		free(temp->value);
		free(temp);
	}
}
