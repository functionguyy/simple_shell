#include "main.h"
/**
 * exit_prog - exit the program
 *
 * Return: returns 1
 */
int exit_prog(void)
{
	/* so the program can perform some cleanup before exiting */
	return (1);
}
/**
 * print_env - prints the environment variables and values
 *
 * Return: 0 on success.Always successful.
 */
int print_env(void)
{
	/* declare variables */
	char **ep;

	/* initialize variable */
	ep = environ;

	while (*ep != NULL)
	{
		/* bring your printf function to use here */
		printf("%s\n", *ep);
		ep++;
	}

	return (0);
}
