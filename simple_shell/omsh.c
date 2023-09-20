#include "main.h"
/**
 * main - program that prints all the command line arguments passed to it
 * without using ac
 * @ac: count of the command line arguments passed to the program
 * @av: NULL terminated array of strings
 *
 * Return: returns 0 for successful execution
 */
int main(__attribute__((unused)) int ac, char **av)
{

	/* ignore Ctrl+C interrupt */


	/* mode switching */
	if (isatty(STDIN_FILENO) == 0 && errno == ENOTTY)
	{
		/* Non-interactive mode */
		runNonInteractive(av[0]);
	}
	else
	{
		/* interactive mode */
		/* make a function name interactiveLoop */
		runInteractive(av[0]);
		putchar('\n');
	}

	return (0);
}
