#include <stdio.h>
#include "sandpiles.h"

/**
 * print_grid - Print 3x3 grid
 * @grid: 3x3 grid
 */
static void print_grid(int grid[3][3])
{
    int i, j;

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
 * toppling - Perform toppling operation on a cell
 * @grid: 3x3 grid
 * @row: row index
 * @col: column index
 */
static void toppling(int grid[3][3], int row, int col)
{
    grid[row][col] -= 4;
    if (row - 1 >= 0)
        grid[row - 1][col]++;
    if (row + 1 < 3)
        grid[row + 1][col]++;
    if (col - 1 >= 0)
        grid[row][col - 1]++;
    if (col + 1 < 3)
        grid[row][col + 1]++;
}

/**
 * is_stable - Check if the sandpile is stable
 * @grid: 3x3 grid
 * Return: 1 if stable, 0 otherwise
 */
static int is_stable(int grid[3][3])
{
    int i, j;

    for (i = 0; i < 3; i++)
    {
        for (j = 0; j < 3; j++)
        {
            if (grid[i][j] > 3)
                return 0;
        }
    }
    return 1;
}

/**
 * sandpiles_sum - Compute the sum of two sandpiles
 * @grid1: First 3x3 grid
 * @grid2: Second 3x3 grid
 */
void sandpiles_sum(int grid1[3][3], int grid2[3][3])
{
    int temp_grid[3][3];
    int i, j;

    // Step 1: Add the two grids together and store the result in a temporary grid
    for (i = 0; i < 3; i++)
    {
        for (j = 0; j < 3; j++)
        {
            temp_grid[i][j] = grid1[i][j] + grid2[i][j];
        }
    }

    // Step 2: Check if the temporary grid is stable, if not, perform toppling operations
    while (!is_stable(temp_grid))
    {
        printf("=\n");
        print_grid(grid1);
        printf("\n");

        // Perform toppling operation on unstable cells
        for (i = 0; i < 3; i++)
        {
            for (j = 0; j < 3; j++)
            {
                if (temp_grid[i][j] > 3)
                    toppling(temp_grid, i, j);
            }
        }

        // Assign the values of the resulting grid back to the original grid1 sandpile
        for (i = 0; i < 3; i++)
        {
            for (j = 0; j < 3; j++)
            {
                grid1[i][j] = temp_grid[i][j];
            }
        }
    }

    printf("=\n");
}
