#include "lists.h"

char **word_arr(char *str)
{
	char *token;
	list_t *head, *temp;
	char **av;
	size_t tok_len, i;



	token = strtok(str, " ");
	head = NULL;
	while (token != NULL)
	{
		add_node_end(&head, token);
		token = strtok(NULL, " ");
	}

	tok_len = list_len(head);

	av = malloc(sizeof(char *) * tok_len);
	if (av == NULL)
	{
		return (NULL);
	}
	
	i = 0;
	while (head != NULL)
	{
		temp = head;
		av[i++] = temp->str;
		head = temp->next;
	}
	av[i] = NULL;
	
	free_list(head);
	return (av);
}

