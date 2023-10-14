#include "main.h"
/**
 * spilt_line - splits the command entered from the user
 * @new_line: the input from user
 * Return: the array of the splited command
 */

char **spilt_line(char *new_line)
{
	int len = 0;
	char **args = NULL;
	char *del = " \n\t";
	char *token = NULL;

	args = malloc(sizeof(char *) * 25);
	if (args == NULL)
		return (NULL);
	token = strtok(new_line, del);
	if (!token)
	{
		free(new_line);
		return (NULL);
	}
	while (token != NULL)
	{
		args[len] = token;
		len++;
		token = strtok(NULL, del);
	}
	args[len] = NULL;
	return (args);
}
