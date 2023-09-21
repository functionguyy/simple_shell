#include "main.h"
/**
 * _prompt - print the shell's prompt and reads the input
 *
 * Return: returns pointer to the input string or NULL
 */
char *_prompt()
{
	char *line_ptr;
	char *prompt;

	prompt = "$ ";

	write(STDOUT_FILENO, prompt, strlen(prompt));
	/*fflush(stdout)*/

	/* build a readline function */
	line_ptr = _readLine();


	return (line_ptr);
}
/**
 * runNonInteractive - interface to execute commands passed to redirections
 * @prog: the name of the program
 *
 * Return:  always 0 on success. Always successful.
 */
int runNonInteractive(char *prog)
{
	char *inputLine, **cmdLineArr, *cmdName = NULL;
	cmd_t *cmdData;
	int cmdCount = 1;

	while (1)
	{
		inputLine = _readLine();
		if (inputLine == NULL)
			break;
		/* split input line and create array of words */
		cmdLineArr = parseLine(inputLine, " ");
		if (cmdLineArr == NULL)
		{
			free(inputLine);
			continue;
		}
		/* execute the command */
		cmdData = searchCmd(cmdLineArr[0]);
		if (cmdData == NULL)
		{
			cmdName = cmdLineArr[0];
			dprintf(STDERR_FILENO, "%s: %d: %s: not found\n", prog, cmdCount, cmdName);
			free(cmdData);
			freeArrayOfPtr(cmdLineArr);
			exit(127);
		}
		executeCmd(cmdData, cmdLineArr);
	}

	return (0);
}
/**
 * runInteractive - interface to start up the terminal to input command after a
 * prompt
 * @prog: the name of the program
 *
 * Return: always 0 on success. Alway successful.
 */
int runInteractive(char *prog)
{
	char *inputLine, **cmdLineArr, *cmdName = NULL;
	cmd_t *cmdData;
	size_t cmdCount;

	cmdCount = 0;

	/*signal(SIGINT, SIG_IGN);*/

	while (1)
	{
		cmdCount++;
		inputLine = _prompt();
		if (inputLine == NULL)
			break;
		cmdLineArr = parseLine(inputLine, " ");
		if (cmdLineArr == NULL)
		{
			free(inputLine);
			continue;
		}
		cmdData = searchCmd(cmdLineArr[0]);
		if (cmdData == NULL)
		{
			cmdName = cmdLineArr[0];
			dprintf(STDERR_FILENO, "%s: %lu: %s: not found\n", prog, cmdCount, cmdName);
			free(cmdData);
			freeArrayOfPtr(cmdLineArr);
			continue;
		}

		executeCmd(cmdData, cmdLineArr);
	}
	free(inputLine);
	exit(EXIT_SUCCESS);
}
