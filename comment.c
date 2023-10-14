#include "main.h"
/**
 * comment - handles the comments from the user
 * @line: the input from user
 */

void comment(char *line)
{
	int j = 0;

	if (line[j] == '#')
		(line[j]) = '\0';
	while (line[j] != '\0')
	{
		if (line[j] == '#' && line[j - 1] == ' ')
			break;
		j++;
	}
	line[j] = '\0';
}
