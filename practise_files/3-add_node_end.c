#include "lists.h"
/**
* add_node_end - Function adds a new node at the beginning of a linked list
* @head: pointer to pointer to the last added node
* @str: pointer to str
*
* Return: the address of new element or NULL if its fails
*/
list_t *add_node_end(list_t **head, const char *str)
{
	list_t *new_node, *temp;

	new_node = malloc(sizeof(list_t));
	if (new_node == NULL)
	{
		return (NULL);
	}
	if (str)
	{
		new_node->str = _strdup(str);
	}
	new_node->next = NULL;
	if (*head == NULL)
	{
		*head = new_node;
	}
	else
	{
		temp = *head;
		while (temp->next != NULL)
		{
			temp = temp->next;
		}
		temp->next = new_node;
	}
	return (*head);
}
