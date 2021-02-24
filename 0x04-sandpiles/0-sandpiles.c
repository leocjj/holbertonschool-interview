#include "sandpiles.h"

/**
 * isStable - Function checking if a sandpile is stable
 * @grid: The sandpile
 * Return: 1 if the sandpile is stable, 0 otherwise
 */
int isStable(int grid[3][3])
{
	int x, y;

	for (x = 0; x < 3; x++)
	{
		for (y = 0; y < 3; y++)
		{
			if (grid[x][y] > 3)
				return (0);
		}
	}
	return (1);
}

/**
 * topple - Function that topples an unstable sandpile
 * @grid: The sandpile
 * Return: Void function
 */
void topple(int grid[3][3])
{
	int x, y, cpGrid[3][3];

	for (x = 0; x < 3; x++)
	{
		for (y = 0; y < 3; y++)
		{
			cpGrid[x][y] = grid[x][y];
		}
	}
	for (x = 0; x < 3; x++)
	{
		for (y = 0; y < 3; y++)
		{
			if (grid[x][y] >= 4)
			{
				cpGrid[x][y] -= 4;
				if (x + 1 < 3)
					cpGrid[x + 1][y] += 1;
				if (x - 1 >= 0)
					cpGrid[x - 1][y] += 1;
				if (y + 1 < 3)
					cpGrid[x][y + 1] += 1;
				if (y - 1 >= 0)
					cpGrid[x][y - 1] += 1;
			}
		}
	}
	for (x = 0; x < 3; x++)
	{
		for (y = 0; y < 3; y++)
		{
			grid[x][y] = cpGrid[x][y];
		}
	}
}

/**
 * print_g - Print 3x3 grid
 * @grid: 3x3 grid
 * Return: Void function
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
 * sandpiles_sum - Function that computes the sum of two sandpiles
 * @grid1: the first sandpile
 * @grid2: the second sandpile
 * Return: Void Function
 */
void sandpiles_sum(int grid1[3][3], int grid2[3][3])
{
	int x, y;

	for (int i = 0; i <= 2; i++)
		for (int j = 0; j <= 2; j++)
			grid1[i][j] += grid2[i][j];

	while (!isStable(grid1))
	{
		print_g(grid1);
		topple(grid1);
	}
}
