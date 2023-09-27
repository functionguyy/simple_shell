#include "main.h"
/**
 * createDirPath - creareturns the directory path for a command
 * @h: pointer to the head of a singly linked list containing the directory
 * pathnames in PATH environment variables
 * @mem: malloc'ed memory array where the created pathname is stored
 * @cmdName: name of the command
 * @size: byte size of mem array
 *
 * Description: the function generates the directory pathname of a command by
 * appending the cmdName to the directory string in h. The directory string in
 * h are the directory paths in PATH enviroment variable.
 * Return: returns a pointer to the string of the directory path for a command
 */
char *createDirPath(list_t *h, char **mem, char *cmdName, size_t size)
{
	size_t tempBufSize, lenCmdName;
	char *cmdDirPath, *pathnameMem, *slash;
	list_t *temp;

	lenCmdName = strlen(cmdName);
	pathnameMem = *mem;
	temp = h;
	slash = "/";

	tempBufSize = temp->len + lenCmdName + 1;
	if (tempBufSize > size)
	{
		size = tempBufSize;
		pathnameMem = realloc(pathnameMem, sizeof(char) * size);
		if (pathnameMem == NULL)
			return (NULL);
	}

	cmdDirPath = strcpy(pathnameMem, temp->str);
	if (cmdDirPath[(temp->len) - 1] != '/')
		cmdDirPath = strcat(pathnameMem, slash);
	cmdDirPath = strcat(pathnameMem, cmdName);

	return (cmdDirPath);
}
/**
 * alignMemoryAllocation - removes the unused memory spaces still available in
 * a malloc'ed buffer
 * @src: pointer to the malloc'ed buffer
 *
 * Description: alignMemoryAllocation allocates buffer with just the amount
 * of bytes needed to store the string(including the null-byte) that is in
 * src, copies the string from src into the new buffer and frees src
 * Return: returns a pointer to new buffer
 */
char *alignMemoryAllocation(char *src)
{
	/* declare variables */
	size_t bufSize;
	char *newBuf;

	/* initialize variables */
	bufSize = strlen(src) + 1;
	newBuf = malloc(sizeof(char) * bufSize);


	if (newBuf == NULL)
		return (NULL);

	newBuf = strcpy(newBuf, src);
	free(src);

	return (newBuf);
}
/**
 * locateCmdDirPath - returns pathname for the binary file of a command
 * of a command.
 * @h: linked list of the PATH directories
 * @cmdName: name of the command
 *
 * Return: returns the pointer to a directory pathname containing the binary
 * for a command or NULL if not found.
 */
char *locateCmdDirPath(list_t *h, char *cmdName)
{
	/* declare variables */
	list_t *temp;
	size_t bufSize, foundSig;
	char *cmdFilePath, *buffer, *filePath;
	struct stat st;

	/* initialize variables */
	bufSize = 512;
	cmdFilePath = NULL;
	filePath = NULL;
	buffer = NULL;
	foundSig = 0;
	temp = h;

	buffer = malloc(sizeof(char) * bufSize);
	if (buffer == NULL)
		return (NULL);

	while (temp != NULL && foundSig == 0)
	{
		filePath = createDirPath(temp, &buffer, cmdName, bufSize);
		if (filePath == NULL)
			return (NULL);

		 /* check if command file exist in the directory pointed to by filePath */
		if (stat(filePath, &st) == 0)
		{
			foundSig = 1;
			cmdFilePath = alignMemoryAllocation(filePath);
			return (cmdFilePath);
		}
		temp = temp->next;
	}

	if (filePath != NULL && foundSig == 0)
		free(filePath);

	return (NULL);
}
/**
 * createPathDirList - builds a linked list of of the PATH directories
 *
 * Return: returns pointer to linked list if successful or NULL otherwise.
 */
list_t *createPathDirList(void)
{
	/* declare variables */
	char *pathDirToken, *envValue, *envValueDup;
	list_t *head;

	/* initialize variables */
	head = NULL;
	envValue = _getenv("PATH");
	if (envValue == NULL)
		return (NULL);

	envValueDup = strdup(envValue);
	if (envValueDup == NULL)
		return (NULL);

	pathDirToken = strtok(envValueDup, ":");

	/* build singly linked list of PATH directory pathnames */
	while (pathDirToken != NULL)
	{
		add_node_end(&head, pathDirToken);
		pathDirToken = strtok(NULL, ":");
	}

	free(envValueDup);
	return (head);
}
