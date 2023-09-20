#include "main.h"
/**
 * add_node_end - adds a new node at the end of a linked list
 * @head: pointer to pointer to the beginning of the list
 * @str: pointer to a string
 *
 * Return: the address of new element or NULL if it fails
 */
list_t *add_node_end(list_t **head, const char *str)
{
	/* declare variables */
	list_t *newNode, *tempNode;

	/* initialize variables */
	newNode = NULL;
	tempNode = NULL;

	/* request memory allocation on heap */
	newNode = malloc(sizeof(list_t));
	if (newNode == NULL)
		return (newNode);

	/* assign values to new node */
	if (str)
	{
		newNode->str = strdup(str);
		if (newNode->str == NULL && errno == ENOMEM)
			return (NULL);
		newNode->len = strlen(str);
	}
	newNode->next = NULL;
	if (*head == NULL)
		*head = newNode;
	else
	{
		tempNode = *head;
		while (tempNode->next != NULL)
			tempNode = tempNode->next;

		tempNode->next = newNode;
	}

	return (newNode);
}
