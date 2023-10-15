#include "main.h"
/**
 * _getenv - gets environment path
 * @viron: the env variable
 * Return: the path
 */
char *_getenv(char *viron)
{
	size_t len = _strlen(viron);
	char **env = environ;

	while (*env)
	{
		if (_strncmp(*env, viron, len) == 0 && (*env)[len] == '=')
			return (&(*env)[len + 1]);
		env++;
	}
	return (NULL);
}
