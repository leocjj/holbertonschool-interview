#include <stdlib.h>
#include <stdio.h>
#include "sandpiles.h"


/**
 * print_g - Print 3x3 grid
 * @grid: 3x3 grid
 *
 */
void print_g(int grid[3][3])
{
	int i, j;

	printf("=\n");
	for (i = 0; i < 3; i++)
	{
		for (j = 0; j < 3; j++)
		{
			if (j)
				printf(" ");
			printf("%d", grid[i][j]);
		}
		printf("\n");
	}
}

/**
 * sandpiles_sum - creates a binary tree node.
 * @grid1: Left 3x3 grid
 * @grid2: Right 3x3 grid
 * Return: void.
 */
void sandpiles_sum(int grid1[3][3], int grid2[3][3])
{
	int unstable = 1;

	for (int i = 0; i <= 2; i++)
		for (int j = 0; j <= 2; j++)
			grid1[i][j] += grid2[i][j];

	while (unstable)
	{
		unstable = 0;
		for (int i = 0; i <= 2; i++)
		{
			for (int j = 0; j <= 2; j++)
			{
				if (grid1[i][j] >= 4)
				{
					unstable = 1;
					grid1[i][j] -= 4;

					if ((i - 1) >= 0)
						grid1[i - 1][j] += 1;

					if ((i + 1) <= 2)
						grid1[i + 1][j] += 1;

					if ((j - 1) >= 0)
						grid1[i][j - 1] += 1;

					if ((j + 1) <= 2)
						grid1[i][j + 1] += 1;
				}
			}
		}
		print_g(grid1);
	}
}
