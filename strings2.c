#include "main.h"

/**
 * _strchr - Returns a pointer to the first
 *       occurrence of the character
 * @s: string to search
 * @c: character to be searched for
 *
 * Return: the location
 */

char *_strchr(char *s, char c)
{
	int i;

	for (i = 0; s[i] != '\0'; i++)
	{
		if (s[i] == c)
		{
			return (&s[i]);
		}
	}
	return (0);
}

/**
 * *_strdup - copy of the string
 * @str: input
 * Return: pointer
 */

char *_strdup(char *str)
{
	int i, size;
	char *m;

	if (str == NULL)
		return (NULL);

	for (size = 0; str[size] != '\0'; size++)
		;
	size++;
	m = malloc(size * sizeof(*str));

	if (m == 0)
		return (NULL);

	for (i = 0; i < size; i++)
		m[i] = str[i];
	return (m);
}

/**
 * _strncmp - compare two strings
 * @str1: first string
 * @str2: second string
 * @num: size
 * Return: comparsion
 */
int _strncmp(const char *str1, const char *str2, size_t num)
{
	size_t i;

	for (i = 0; i < num; i++)
	{
		if (str1[i] == '\0' || str1[i] != str2[i])
		{
			return (str1[i] - str2[i]);
		}
	}

	return 0;
}
