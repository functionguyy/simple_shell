#include "main.h"
/**
 * free_list - frees allocated memory in a linked list
 * @head: pointer to the linked list
 *
 * Return: Nothing
 */
void free_list(list_t *head)
{
	/* declare variables */
	list_t *currentNode;


	/* initialize variable */
	currentNode = NULL;


	if (head)
	{
		while (head->next != NULL)
		{
			currentNode = head;
			head = head->next;
			free(currentNode->str);
			free(currentNode);
		}
		free(head->str);
		free(head);
	}
}
