#include "holberton.h"
/**
 *exit_op - handles exit builtin
 *@array: the array of strings to execute
 *
 *Return: 0 upon success, or some specific exit code specified by user
 */
int exit_op(char **array)
{
	int num, j = 0;

	if (array[1] == NULL)
	{
		free(array);
		exit(0);
	}

	else
	{
		num = _atoi(array[1]);
		if (num == -1)
		{
			write(STDOUT_FILENO, "./hsh: 1: exit: Illegal number: ", 32);
			while (array[1][j] != '\0')
				j++;
			write(STDOUT_FILENO, array[1], j);
			write(STDOUT_FILENO, "\n", 1);
			return (0);
		}
		free(array);
		exit(num);
	}
}
/**
 *cd_op - hands the cd builtin
 *@array: the array of command line strings
 *@env: the environment variable
 *
 *Return: 0 upon success
 */
int cd_op(char **array, char **env)
{
	int i = 0;
	char cwd[1024];
	char *newdir;

	if (array[1] == NULL)
	{
		if (chdir(_getenv("HOME", env)) == -1)
		{
			perror("./hsh");
			perror("cd");
			write(STDOUT_FILENO, "can't cd to home\n", 17);
		}
	}
	else
	{
		getcwd(cwd, 1024);
		while (cwd[i] != '\0')
			i++;
		cwd[i++] = '/';
		cwd[i] = '\0';
		newdir = str_concat(cwd, array[1]);
		if (chdir(newdir) == -1)
		{
			perror("./hsh");
			write(STDOUT_FILENO, "can't cd into directory\n", 24);
		}
		free(newdir);
	}
	return (0);
}
/**
 *env_op - handles env builtin
 *@env: environment varialbe
 *
 *Return: 0 on success
 */
int env_op(char **env)
{
	int i = 0, length = 0;

	while (env[i] != NULL)
	{
		length = _strlen(env[i]);
		write(STDOUT_FILENO, env[i], length);
		write(STDOUT_FILENO, "\n", 1);
		i++;
	}
	return (0);
}