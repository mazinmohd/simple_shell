#include "main.h"
/**
 * main - entry point
 * @ac: counts arg number
 * @argv: array of string
 * Return: 0 in success and -1 in fail
 */
int main(int ac, char **argv)
{
	char *line = NULL, **tokens = NULL;
	int status = 0, ind = 0;
	(void) ac;

	while (1)
	{
		line = read_line();
		if (line == NULL)
		{
			if (isatty(STDIN_FILENO))
				write(1, "\n", 2);
			return (status);
		}
		comment(line);
		if (is_empty(line))
		{
			free(line);
			status = 0;
			continue;
		}
		ind++;
		tokens = spilt_line(line);
		if (tokens == NULL)
		{
			free(tokens);
			continue;
		}
		if (check_built(line))
		{
			handle_built(tokens, status, line, ind, argv);
			continue;
		}
		status = exec(tokens, line, ind, argv);
		free(tokens);
		free(line);
	}
	return (status);
}
