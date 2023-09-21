#include "main.h"
/**
 * list_len - function counts the number of nodes in a linked list
 * @h: pointer to list_t list
 *
 * Return: the number of nodes in list_t list
 */
size_t list_len(const list_t *h)
{
	/* declare variables */
	size_t elmCount;


	/* initialize variables */
	elmCount = 0;


	/* count element in the linked list */
	while (h != NULL)
	{
		elmCount++;
		h = h->next;
	}

	return (elmCount);
}
