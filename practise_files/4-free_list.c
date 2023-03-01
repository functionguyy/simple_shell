#include "lists.h"
/**
* free_list - Function frees allocated memory in a linked list
* @head: pointer to the linked list
*
* Return: Nothing
*/
void free_list(list_t *head)
{
	list_t *cnode;

	if (head)
	{
		while (head->next != NULL)
		{
			cnode = head;
			head = head->next;
			free(cnode->str);
			free(cnode);
		}
		free(head->str);
		free(head);
	}
}
