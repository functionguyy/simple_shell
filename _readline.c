#include "main.h"
/**
 * _readLine - functionn reads command line input in the interactive shell
 *
 * Return: returns a pointer to the buffer containing the read input
 */
char *_readLine()
{
	/* declare variables */
	ssize_t n_read;
	char *line_ptr;
	size_t n;


	/* initialize variables */
	line_ptr = NULL;
	n = 0;
	errno = 0;


	/*signal(SIGINT, SIG_IGN)*/
	if (line_ptr != NULL)
		free(line_ptr);

	/* read input command line */
	n_read = getline(&line_ptr, &n, stdin);
	if (n_read == -1 && errno != 0)
	{
		perror("getline");
		free(line_ptr);
		return (NULL);
	}
	/* add condition to catch Ctrl+C signal */

	/* executes when Ctrl+D is used to signall end-of-file */
	if (n_read == -1 && errno == 0)
	{
		free(line_ptr);
		if (isatty(STDIN_FILENO))
			putchar('\n');
		exit(0);
	}


	return (line_ptr);
}
