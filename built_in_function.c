#include "main.h"
/**
 * check_built - check if the user input is built in function
 * @command: the input of user
 * Return: 1 if true and 0 if false
 */

int check_built(char *command)
{
	char *built_fun[] = {"exit", "env", "cd", NULL};
	int i;

	for (i = 0; built_fun[i]; i++)
	{
		if (_strcmp(command, built_fun[i]) == 0)
			return (1);
	}

	return (0);
}

/**
 * handle_built - handle the built in function
 * @args: the array of spilted command
 * @status: the status of operation
 * @command: the user input
 */

void handle_built(char **args, int *status, char *command)
{
	int i;

	if (_strcmp(args[0], "exit") == 0)
	{
		if (args[1])
			*status = _atoi_(args[1]);
		free(command);
		free(args);
		exit(*status);
	}
	else if (_strcmp(args[0], "env") == 0)
	{
		for (i = 0; environ[i]; i++)
		{
			write(STDOUT_FILENO, environ[i], _strlen(environ[i]));
			write(STDOUT_FILENO, "\n", 1);
		}
		free(command);
		free(args);
	}
}

