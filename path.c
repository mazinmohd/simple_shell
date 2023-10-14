#include "main.h"
/**
 * get_full_path - gets the path of the user command
 * @command: the user input
 * @path: the environment path
 * Return: the path
 */
char *get_full_path(char *command, char *path)
{
	char *token;
	char *full_path = NULL;

	token = strtok(path, ":");
	while (token != NULL)
	{
		full_path = malloc(_strlen(token) + _strlen(command) + 1);
		if (full_path == NULL)
			return (NULL);

		_strcpy(full_path, token);
		_strcat(full_path, "/");
		_strcat(full_path, command);

		if (access(full_path, X_OK) == 0)
			return (full_path);

		free(full_path);
		token = strtok(NULL, ":");
	}

	return (NULL);
}
