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
	ssize_t input_len = 1;
	int num, num_token;

	if (ac == 1)
	{
		while (1)
		{
			write(1, "#cisfun$ ", 9);
			buffer = read_input(&input_len);
			if (input_len == -1)
			{
				write(1, "\n", 1);
				break;
			}
			argv = parser(buffer, &num_token);
			num = exe_input(argv);
			if (num == 1)
			{
				perror("Execution failed");
				return (1);
			}
		}
	free(buffer);
	free_grid(argv, num_token);
	}
	return (0);
}
