#include "holberton.h"
/**
  *line_handler - reads a line of text typed in after a prompt
  *
  *Description: function will read a line, break it into tokens, and execute
  *the call, then return to main when end of file is reached
  *Return: 0 when EOF is reached (ie user presses Ctrl + D)
  */
int main(int ac, char **av, char **env)
{
	(void)ac;
	(void)av;
	char *line, *newline;
	size_t len;
	ssize_t characters = 0;
	char **tokenarray;

	while (1)
	{
		line = NULL;
		len = 0;
		if (isatty(0))
			write(STDOUT_FILENO, "$ ", 2);
		characters = getline(&line, &len, stdin);
		if (line[0] == '\n' && line[1] == '\0')
		{
			free(line);
			continue;
		}
		if (characters == EOF && characters == -1)
			return (control_D_op(line));
		newline = _reallocchar(line);
		tokenarray = tokensplit(newline);
		executeprog(tokenarray, env);
		free_tokens(tokenarray);
		free(line);
		free(newline);
		free(tokenarray);
	}
	free(line);
	return (0);
}
