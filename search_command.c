#include "main.h"
/**
 * searchCmd - determines the location of the command
 * @commandName: name of the command
 *
 * Return: return a data structure containing info of a commands locations or
 * null otherwise
 */
cmd_t *searchCmd(char *commandName)
{
	/* declare variables */
	cmd_t *commandData;
	struct stat st;
	char *cmdPath;

	/* initialize variables */
	commandData = malloc(sizeof(cmd_t));
	if (commandData == NULL)
		return (NULL);
	cmdPath = NULL;

	/* check if commandName contain a forward slash */
	if (strchr(commandName, '/'))
	{
		if (stat(commandName, &st) == 0)
		{
			commandData->cmd = commandName;
			commandData->locationFlag = 2;
			return (commandData);
		}
		free(commandData);
		return (NULL);
	}
	/*check the builtin functions for a command name match */
	if (isBuiltInCmd(commandName))
	{
		commandData->cmd = commandName;
		commandData->locationFlag = 0;
		return (commandData);
	}
	/* search for command in PATH */
	cmdPath = searchPath(commandName);
	if (cmdPath != NULL)
	{
		commandData->cmd = cmdPath;
		commandData->locationFlag = 1;
		return (commandData);
	}
	free(commandData);
	return (NULL);
}
