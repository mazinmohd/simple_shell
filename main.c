#include "main.h"
/**
 * main - entry point
 * 
 * Return: 0 in success and -1 in fail
 */
int main(void)
{
	char *line = NULL;
	char **tokens = NULL;
	int status = 0;

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
		tokens = spilt_line(line);
		if (tokens == NULL)
		{
			free(tokens);
			continue;
		}
		if (check_built(line))
		{
			handle_built(tokens, &status, line);
			continue;
		}
		status = exec(tokens, line);
		free(tokens);
		free(line);
	}
	return (status);
}
