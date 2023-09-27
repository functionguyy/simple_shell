#include "main.h"
/**
 * cleanExit - free malloc'ed allocations and exits the program
 * @cmdData: malloc'ed allocation
 * @cmdArr: malloc'ed allocation
 *
 * Return: nothing
 */
void cleanExit(cmd_t *cmdData, char **cmdArr)
{
	freeArrayOfPtr(cmdArr);
	free(cmdData);

	exit(EXIT_SUCCESS);
}
/**
 * isEmptyString - checks if a string has any non delimiter character
 * @str: pointer to the string
 * @delimiter: pointer to the delimiter character
 *
 * Return: returns 0 if the strings contains non-delimiter characters or -1
 * otherwise
 */
ssize_t isEmptyString(char *str, char *delimiter)
{
	/* declare variables */
	char *stringPtr;


	/* initialize variables */
	stringPtr = str;

	/* scan the string */
	while (*stringPtr == *delimiter)
		stringPtr++;

	if (*stringPtr == '\0')
		return (-1);

	return (0);
}
/**
 * _getenv - returns the value of an enviroment variable
 * @envVar: name of the enviroment variable
 *
 * Return: returns a pointer to the value of the enviroment variable or NULL
 */
char *_getenv(char *envVar)
{
	char **ep, *value, *line;
	size_t n;

	if (envVar == NULL)
		return (NULL);

	ep = environ;
	if (*ep == NULL)
		return (NULL);
	value = NULL;
	n = strlen(envVar);



	while (*ep != NULL)
	{
		if (strncmp(*ep, envVar, n) == 0)
		{
			/* enviroment variables are of the nature name=var */
			line = *ep;
			value = (line + (n + 1));
			break;
		}
		ep++;
	}

	return (value);
}
/**
 * createArrayOfLineTokens - creates an array of pointers from a values in a
 * linked list
 * @h: pointer to the head of a linked list
 *
 * Return: return an array of pointer or NULL otherwise
 */
char **createArrayOfLineTokens(list_t *h)
{
	/* declare variables */
	list_t *temp;
	char **ptrArr;
	size_t arraySize, arrIdx;


	/* initialize variables */
	temp = h;
	arrIdx = 0;
	arraySize = list_len(h) + 1;

	ptrArr = malloc(sizeof(char *) * arraySize);
	if (ptrArr == NULL)
		return (NULL);

	while (temp != NULL)
	{
		ptrArr[arrIdx] = strdup(temp->str);
		if (ptrArr[arrIdx] == NULL && errno == ENOMEM)
		{
			free_list(h);
			return (NULL);
		}
		arrIdx++;
		temp = temp->next;
	}
	/* null-terminate the array */
	ptrArr[arrIdx] = NULL;

	free_list(h);

	return (ptrArr);
}
/**
 * createListOfLineTokens - builds a linked list of words in a strings
 * @str: pointer to the string
 * @delim: pointer to the delimiter character
 *
 * Return: returns a pointer to the linked list or NULL otherwise
 */
list_t *createListOfLineTokens(char *str, char *delim)
{
	/* declare variables */
	char *line, *token;
	list_t *head, *node;

	/* initialize variables */
	line = str;
	head = NULL;
	node = NULL;


	/* tokenize string */
	token = strtok(line, delim);
	while (token != NULL)
	{
		node = add_node_end(&head, token);
		if (node == NULL)
			return (NULL);
		token = strtok(NULL, delim);
	}

	return (head);
}
