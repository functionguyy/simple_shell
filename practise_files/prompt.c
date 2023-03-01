#include "lists.h"
/**
* main - prints user input to next line
*
* Return: Always 0 on success or exit when end of file is detected
*/

int main(void)
{
	ssize_t i;
	char *lineptr = NULL;
	size_t n = 0;
	char **arr;

	printf("$ ");
	i = getline(&lineptr, &n, stdin);
	if (i != -1)
	{
		write(STDOUT_FILENO, lineptr, n);
	}
	else
	{
		write(STDOUT_FILENO, "\n", 1);
		exit(i);
	}
	
	arr = word_arr(lineptr);

	while(*arr != NULL)
	{
		printf("%s", *arr);
		arr++;
		if (*arr != NULL)
		{
			printf("\n");
		}
	}

	free(lineptr);
	return (0);

}
