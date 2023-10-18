#include "main.h"

/**
 * exec - executes the user command
 * @args: the array of the splited command
 * @line: the input of the user
 * @name: shell name
 * @ind: index
 * Return: the status of the operation
 */

int exec(char **args, char *line, int ind, char **name)
{
	int status = 0;
	char *path = NULL;
	char *command;
	pid_t id;

	path = _getenv("PATH");
	command = get_full_path(args[0], path);

	if (_strchr(args[0], '/') == NULL)
	{
		if (command == NULL)
		{
			print_error(name[0], args[0], ind);
			return (127);
		}
	}
	else
		command = args[0];

	id = fork();

	if (id == 0)
	{

		if (execve(command, args, environ) == -1)
		{
			/*perror(args[0]);*/
			free(args);
			free(line);
			exit(127);
		}
	}
	else
		waitpid(id, &status, 0);
	return (WEXITSTATUS(status));
}
