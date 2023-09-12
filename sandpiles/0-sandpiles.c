#include <stdio.h>
#include "sandpiles.h"

/**
 * isStable - check if the given grid is stable or not
 * @matrix: matrix forming the grid
 *
 * Return: 0 on failure, 1 on success
 */
int isStable(int matrix[3][3])
{
	int i, j;

	for (i = 0; i < 3; i++)
	{
		for (j = 0; j < 3; j++)
		{
			if (matrix[i][j] >= 4)
				return (0);
		}
	}
	return (1);
}

/**
 * printMatrix - print the given grid
 * @matrix: matrix forming the grid
 */
void printMatrix(int matrix[3][3])
{
	int i, j;

	printf("=\n");

	for (i = 0; i < 3; i++)
	{
		for (j = 0; j < 3; j++)
		{
			if (j != 0)
				printf(" ");
			printf("%d", matrix[i][j]);
		}
		printf("\n");
	}
}

/**
 * addSandpile - add the sandpiles of matrix2 to matrix1
 * @matrix: matrix forming the grid
 * @matrix2: matrix forming the grid2
 */
void addSandpile(int matrix[3][3], int matrix2[3][3])
{
	size_t i, j;

	for (i = 0; i < 3; i++)
		for (j = 0; j < 3; j++)
			matrix[i][j] += matrix2[i][j];
}

/**
 * dropSand - topopling the sandpiles
 * @matrix: matrix forming the grid
 */
void dropSand(int matrix[3][3])
{
	int i, j;
	int toppled[3][3] = {{0}};

	for (i = 0; i < 3; i++)
	{
		for (j = 0; j < 3; j++)
		{
			if (matrix[i][j] >= 4)
			{
				matrix[i][j] -= 4;

				if (i > 0)
					toppled[i - 1][j] += 1;
				if (i < 3 - 1)
					toppled[i + 1][j] += 1;
				if (j > 0)
					toppled[i][j - 1] += 1;
				if (j < 3 - 1)
					toppled[i][j + 1] += 1;
			}
		}
	}
	addSandpile(matrix, toppled);
}


/**
 * sandpiles_sum - Compute the sum of two sandpiles
 * @grid1: First 3x3 grid
 * @grid2: Second 3x3 grid
 */
void sandpiles_sum(int grid1[3][3], int grid2[3][3])
{
	addSandpile(grid1, grid2);

	while (!isStable(grid1))
	{
		printMatrix(grid1);
		dropSand(grid1);
	}
}
