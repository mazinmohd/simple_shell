#include "main.h"
/**
 * _atoi_ - convert the char to int
 * @str: the string we want to convert it
 * Return: the converted int
 */
int _atoi_(char *str)
{
	int result = 0;
	int i, j;

	j = _strlen(str);
	for (i = 0; i < j; i++)
	{
		if (str[i] < '0' || str[i] > '9')
			break;
		result = result * 10 + str[i] - '0';
	}
	return (result);
}
