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
 * @ind: the index of process
 * @argv: - the argument of main function
 */

void handle_built(char **args, int status, char *command, int ind, char **argv, char **tokenizer)
{
	int i = 0;
	char *id = NULL;

	if (_strcmp(args[0], "exit") == 0)
	{
		if (args[1])
			status = _atoi_(args[1]);
		else
		{
			free(tokenizer);
			_free(command, args);
			exit(status);
		}
		if (args[1][0] == '-')
		{
			id = _itoa(ind);
			write(STDERR_FILENO, argv[0], _strlen(argv[0]));
			write(STDERR_FILENO, ": ", 2);
			write(STDERR_FILENO, id, _strlen(id));
			write(STDERR_FILENO, ": exit", 6);
			write(STDERR_FILENO, ": ", 2);
			write(STDERR_FILENO, "Illegal number: ", 16);
			write(STDERR_FILENO, args[1], _strlen(args[1]));
			write(STDERR_FILENO, "\n", 1);
			_free(command, args);
			free(id);
			exit(2);

		}
		_free(command, args);
		free(tokenizer);
		free(id);
		exit(status);
	}
	else if (_strcmp(args[0], "env") == 0)
	{
		for (i = 0; environ[i]; i++)
		{
			write(STDOUT_FILENO, environ[i], _strlen(environ[i]));
			write(STDOUT_FILENO, "\n", 1);
		}
		free(args);
		/*_free(command, args);*/
	}
}
/**
 * _free - free two element
 * @f1: first element
 * @f2: second elment
 */
void _free(char *f1, char **f2)
{
	free(f1);
	free(f2);
}

