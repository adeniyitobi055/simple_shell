#include "main.h"

/**
 * read_input - read user input.
 * @input_len: length of user input.
 *
 * Return: Always 0.
 */

char *read_input(ssize_t *input_len)
{
	char *buffer;
	size_t n;

	n = 0;
	*input_len = getline(&buffer, &n, stdin);
	return (buffer);
}

/**
 * exe_input - execute users input.
 * @argv: argument vector.
 *
 * Return: Always 0.
 */

int exe_input(char **argv)
{
	pid_t child_pid;

	child_pid = fork();
	if (child_pid == -1)
	{
		perror("./shell");
		return (1);
	}
	if (child_pid == 0)
	{
		if ((execve(argv[0], argv, NULL) == -1))
		{
			perror("./shell");
		}
	}
	else
	{
		wait(NULL);
	}
	return (0);
}

/**
 * parser - splits a string
 * @buffer: string
 * @num_token: length of token string
 *
 * Return: pointer to array of strings or NULL
 */

char **parser(char *buffer, int *num_token)
{
	char **av, *buffer_copy, *token, *delim;
	unsigned int i;

	*num_token = 0;
	delim = " \n";
	buffer_copy = malloc(sizeof(char) * _strlen(buffer));
	if (buffer_copy == NULL)
		return (NULL);
	_strcpy(buffer_copy, buffer);
	token = strtok(buffer, delim);
	(*num_token)++;
	while (token != NULL)
	{
		(*num_token)++;
		token = strtok(NULL, delim);
	}
	av = malloc(sizeof(char *) * (*num_token));
	if (av == NULL)
		return (NULL);
	token = strtok(buffer_copy, delim);
	for (i = 0; token; i++)
	{
		av[i] = malloc(sizeof(char) * _strlen(token));
		if (av[i] == NULL)
		{
			free_grid(av, *num_token);
			return (NULL);
		}
		_strcpy(av[i], token);
		token = strtok(NULL, delim);
	}
	av[i] = NULL;
	free(buffer_copy);
	return (av);
}
