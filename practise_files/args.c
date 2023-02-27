#include <stdio.h>
/**
* main - print all arguments
* @argc: number of arguments
* @argv: array of pointers to the arguments
*
* Return: Always 0.
*/
int main(int __attribute__((__unused__)) argc, char *argv[])
{
	while (*argv != NULL)
	{
		printf("%s\n", *argv);
		argv++;
	}

	return (0);
}
