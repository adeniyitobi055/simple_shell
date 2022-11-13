#include "main.h"

/**
 * free_grid - frees memory of an array of strings
 * @grid: 2D array
 * @num: number of strings
 *
 * Return: nothing
 */

void free_grid(char **grid, int num)
{
	int a;

	for (a = 0; a < num; a++)
		free(grid[a]);
	free(grid);
}
