#include "main.h"
/**
 * overwriteNewlineByte - search for the newline character in a string and
 * replaces it with a null byte character
 * @str: pointer to the string
 *
 * Return: returns Nothing
 */
void overwriteNewlineByte(char *str)
{
	/* declare variables */
	char *newlineStrPtr;
	size_t idx;

	/* initialize variables */
	newlineStrPtr = str;
	idx = 0;

	/* get index of new line character */
	while (newlineStrPtr[idx] != '\n')
		idx++;

	/* overwrite the newline character with a null-byte */
	newlineStrPtr[idx] = '\0';
}
/**
 * parseLine - generates a NULL terminated array containing the words in a
 * string
 * @str: pointer to the string
 * @delimiter: pointer to the character that separates words in the string
 *
 * Return: returns pointer to an array of pointers or exits the program
 */
char **parseLine(char *str, char *delimiter)
{
	/* declare variables */
	char *fullStr, **ptrArr;
	list_t *head;


	/* initialize variables */
	fullStr = str;
	head = NULL;

	/* confirm argument passed is not empty */
	if (fullStr == NULL || *fullStr == '\0')
		return (NULL);

	/*remove new line character from line */
	if (strchr(fullStr, '\n') != NULL)
		overwriteNewlineByte(fullStr);

	/* check that string contains atleast one non-delimiter character */
	if (isEmptyString(fullStr, delimiter) == -1)
		return (NULL);

	head = createListOfLineTokens(fullStr, delimiter);
	if (head == NULL)
	{
		free(fullStr);
		exit(98);
	}
	ptrArr = createArrayOfLineTokens(head);
	if (ptrArr == NULL)
	{
		free(fullStr);
		exit(98);
	}

	/* free input buffer */
	free(fullStr);


	return (ptrArr);
}
