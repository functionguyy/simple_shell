#include "lists.h"
/**
* _getline - read the entire line entered by user in standard input
*
* Return: pointer to the buffer on successful execute or -1 on failure
*/
 char *_getline(void)
{
	ssize_t readbytes;
	char *lineptr = NULL;
	size_t linebytes = 0;

	readbytes = getline(&lineptr, &linebytes, stdin);
	if (readbytes != -1)
	{
		write(STDOUT_FILENO, lineptr, readbytes);
	}
	else
	{
		write(STDOUT_FILENO, "\n", 1);
		exit(readbytes);
	}

	return (lineptr);
}
