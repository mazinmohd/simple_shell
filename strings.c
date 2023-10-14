#include "main.h"

/**
 *  _strlen - print length of string
 *  @str: the string
 *
 *  Return: length
 */
int _strlen(char *str)
{
	int len = 0, i;

	for (i = 0; str[i] != '\0'; i++)
		len++;	
	return (len);
}

/**
 * _strcat - concatenates 2 strings
 * @dest: string to be appended to
 * @src: string to append
 *
 * Return: concatenated string
 */
char *_strcat(char *dest, char *src)
{
	int i = 0, j;

	while (dest[i] != '\0')
	{
		i++;
	}
	for (j = 0; src[j] != '\0'; j++)
	{
		dest[i + j] = src[j];
	}
	dest[i + j] = '\0';
	return (dest);
}

/**
 * *_strcpy - copies the string pointed to by src
 * including the terminating null byte (\0)
 * to the buffer pointed to by dest
 * @dest: pointer to the buffer in which we copy the string
 * @src: string to be copied
 *
 * Return: return the copied string
 */
char *_strcpy(char *dest, char *src)
{
	int length, i;

	length = 0;

	while (src[length] != '\0')
	{
		length++;
	}

	for (i = 0; i < length; i++)
	{
		dest[i] = src[i];
	}
	dest[i] = '\0';

	return (dest);
}

/**
 * _strcmp - compares 2 strings
 * @s1: first string
 * @s2: second string
 *
 * Return: 0 if it the same
 */

int _strcmp(char *s1, char *s2)
{
	int i = 0;

	while (s1[i] - s2[i] == 0 && s1[i] != '\0')
	{
		i++;
	}
	return (s1[i] - s2[i]);
}

/**
 * _strchr - Returns a pointer to the first occurrence of the character
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
