#include "main.h"

/**
 * main - read and execute input.
 * @ac: argument count.
 * @argv: argument vector.
 *
 * Return: Always 0.
 */

int main(int ac, char **argv)
{
	char *buffer;
	ssize_t input_len;
	int num;

	if (ac == 1)
	{
		while (1)
		{
			write(1, "#cisfun$ ", 9);
			buffer = read_input(&input_len);
			strcpy(argv[0], buffer);
			argv[1] = NULL;
			num = exe_input(argv);
			if (num == 1)
			{
				perror("Execution failed");
				return (1);
			}
		}
	free(buffer);
	}
	return (0);
}
