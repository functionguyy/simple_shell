#include "main.h"
/**
 * isBuiltInCmd - returns a function pointer to a builtin cmd's function
 * @commandName: name of the command
 *
 * Return: returns a function pointer for a function
 */
int (*isBuiltInCmd(char *commandName))(void)
{
	builtInCmd_t func[] = {
		{"env", print_env},
		{"exit", exit_prog},
		{NULL, NULL}
	};

	size_t idx;

	idx = 0;

	while (func[idx].cmdName)
	{
		if (strcmp(commandName, func[idx].cmdName) == 0)
			return (func[idx].builtInCmd);
		idx++;
	}

	return (NULL);
}
