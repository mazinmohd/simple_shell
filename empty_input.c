#include "main.h"
/**
 * is_empty - check if the user give empty input
 * @str: the input of the user
 * Return: if true return 1 else return 0
 */
int is_empty(const char *str)
{
	if (str == NULL)
		return (1);

	while (*str)
	{
		if (!_isspace(*str))
			return (0);
		str++;
	}

	return (1);
}
/**
 * _isspace - check the character of input
 * @c: the character of input
 * Return: 0 if false, 1 if true
 */

int _isspace(char c)
{
	return (c == ' ' || c == '\t' || c == '\n' ||
			c == '\v' || c == '\f' || c == '\r');
}

