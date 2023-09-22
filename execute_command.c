#include "main.h"
/**
 * executeCmd - executes a command
 * @commandData: pointer to data structure containing info about a command
 * @cmdLineArr: arguments passed in input for the command
 *
 * Return: returns 0 on success. Always successful
 */
int executeCmd(cmd_t *commandData, char **cmdLineArr)
{
	char *cmdPath;
	int (*builtIn)(void);
	int ext;

	cmdPath = NULL;
	builtIn = NULL;
	ext = 0;

	/* command path was passed as direct input*/
	if (commandData->locationFlag == 2)
		/* call processExecute function */
		ext = processExecute(cmdLineArr[0], cmdLineArr);

	/* the command path was found in PATH */
	if (commandData->locationFlag == 1)
	{
		/* assign the found path */
		cmdPath = commandData->cmd;
		processExecute(cmdPath, cmdLineArr);
		free(cmdPath);
	}

	/* call to builtin command */
	if (commandData->locationFlag == 0)
	{
		builtIn = isBuiltInCmd(commandData->cmd);
		ext = builtIn();
		/* perform cleanup */
		if (ext == 1)
			cleanExit(commandData, cmdLineArr);
		freeArrayOfPtr(cmdLineArr);
	}

	/* free struct data */
	free(commandData);
	/* command execution error */
	if (ext == 2)
		return (2);

	return (0);
}

