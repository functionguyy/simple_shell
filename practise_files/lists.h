#ifndef _LISTS_H_
#define _LISTS_H_
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>

/**
* struct list_s - singly linked list
* @str: string - (malloc'ed string)
* @next: points to the next node
*
* Description: singly linked list node structure
*/

typedef struct list_s
{
	char *str;
	struct list_s *next;
} list_t;

char *_strdup(const char *str);
size_t list_len(const list_t *h);
list_t *add_node_end(list_t **head, const char *str);
void free_list(list_t *head);
char **word_arr(char *str);
char *_getline(void);

#endif
