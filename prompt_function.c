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
	if (*input_len == -1)
	{
		write(1, "\n", 1);
		exit(98);
	}
	buffer[(*input_len) - 1] = 0;
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
