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
	int mode;

	errno = 0;

	/* ignore Ctrl+C interrupt */

	mode = isatty(STDIN_FILENO);

	/* mode switching */
	if (mode == 0 && errno == ENOTTY)
	{
		/* Non-interactive mode */
		runNonInteractive(av[0]);
	}
	else
	{
		/* interactive mode */
		/* make a function name interactiveLoop */
		runInteractive(av[0]);

		_putchar('\n');
	}

	return (0);
}
