#include "main.h"
/**
 * print_error - displays error message
 * @name: shell name
 * @command: user command
 * @ind: error index
 */
void print_error(char *name, char *command, int ind)
{
	char *id, msg[] = ": not found\n";

	id = _itoa(ind);
	write(STDERR_FILENO, name, _strlen(name));
	write(STDERR_FILENO, ": ", 2);
	write(STDERR_FILENO, id, _strlen(id));
	write(STDERR_FILENO, ": ", 2);
	write(STDERR_FILENO, command, _strlen(command));
	/*write(STDERR_FILENO, ": ", 2);*/
	write(STDERR_FILENO, msg, _strlen(msg));
	free(id);
}

/**
 * _itoa -
 * @n:
 * Return: buffer
 */
char *_itoa(int n)
{
	char buff[25];
	int i = 0;

	if (n == 0)
		buff[i++] = '0';
	else
	{
		while (n > 0)
		{
			buff[i++] = (n % 10) + '0';
			n /= 10;
		}
	}
	buff[i] = '\0';
	rev_str(buff, i);

	return (strdup(buff));
}

/**
 * rev_str - reverse string
 * @str: string to be reverted
 * @len: string length
 */
void rev_str(char *str, int len)
{
	int begin = 0, end = len - 1;
	char copy;

	while (begin < end)
	{
		copy = str[begin];
		str[begin] = str[end];
		str[end] = copy;
		begin++;
		end--;
	}
}
