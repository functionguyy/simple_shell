#include "main.h"
/**
 * searchPath - searches the directories in the PATH enviroment variables for
 * the directory containing the binary file associated with a command
 * @commandName: the name of the command whose binary is to be searched for
 *
 * Return: returns a pointer to the directory containing the binary file or
 * NULL if the file is not found.
 */
char *searchPath(char *commandName)
{
	/* search the path directories for the command */
	/* declare variables */
	list_t *head;
	char *cmdDirPath;


	/* initialize variables */
	head = NULL;
	cmdDirPath = NULL;


	/* search for command file in PATH directories */
	head = createPathDirList();
	if (head == NULL)
		return (NULL);
	cmdDirPath = locateCmdDirPath(head, commandName);
	if (cmdDirPath == NULL)
	{
		free_list(head);
		return (NULL);
	}

	/* free the PATH directory list */
	free_list(head);

	return (cmdDirPath);
}
