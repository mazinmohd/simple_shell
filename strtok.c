#include "main.h"
/**
 * _strtok - breaks the string into tokens
 * @str: string to be breaked down
 * @delim: separator
 * Return: poiner to the next token
 */
char *_strtok (char *str, char *del)
{
	static char *token;
	char *tokenizer;
	
	if (str != NULL)
		token = str;
	
	if (token == NULL)
		return (NULL);
	
	while (*token != '\0' && _strchr(del, *token) != NULL)
		token++;

	if (*token == '\0')
		return (NULL);
	
	tokenizer = token;
	
	while (*token != '\0' && _strchr(del, *token) == NULL)
		token++;
	
	if (*token != '\0')
	{
		*token = '\0';
		token++;
	}

	return (tokenizer);
}
