#include "lists.h"
/**
* main - prints user input to next line
*
* Return: Always 0 on success or exit when end of file is detected
*/

int main(void)
{
	char **arr;
	char *line;

	printf("$ ");
	line = _getline();

	arr = word_arr(line);

	while(*arr != NULL)
	{
		printf("%s", *arr);
		arr++;
		if (*arr != NULL)
		{
			printf("\n");
		}
	}

	free(line);
	return (0);

}
