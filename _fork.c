#include "main.h"
/**
 * processExecute - executes a program
 * @cmdPath: pathname of the programs binary file
 * @line_arr: arguments for the program
 *
 * Return: 0 on success
 */


int processExecute(char *cmdPath, char **line_arr)
{
	pid_t pid;
	int status;


	pid = fork();

	wait(&status);
	if (pid == -1)
	{
		perror("fork");
		/*printf("I'm the parent\n");*/
	}
	if (pid > 0)
	{
		/* printf("I'm the parent\n");*/
		freeArrayOfPtr(line_arr);
		/*_exit(status);*/
	}
	if (pid == 0)
	{
		if (execve(cmdPath, line_arr, environ) == -1)
		{
			perror("execve");
			_exit(2);
		}
		_exit(status);

	}

	return (0);
}
