#include "lists.h"
/**
* list_len - function counts the number of nodes in a linked list
* @h: pointer to list_t list
*
* Return: the number of nodes in list_t list
*/
size_t list_len(const list_t *h)
{
	unsigned int n;

	n = 0;
	while (h != NULL)
	{
		n++;
		h = h->next;
	}
	return (n);
}
