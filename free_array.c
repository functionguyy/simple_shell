#include "main.h"
/**
 * freeArrayOfPtr - frees a 2D array of malloc'ed allocations
 * @arr: pointer to an array of pointers
 *
 * Return: nothing
 */
void freeArrayOfPtr(char **arr)
{
	char **arrOfPtrs;
	size_t n;

	n = 0;
	arrOfPtrs = arr;

	while (arrOfPtrs[n] != NULL)
	{
		free(arrOfPtrs[n]);
		n++;
	}
	free(arrOfPtrs);

}
