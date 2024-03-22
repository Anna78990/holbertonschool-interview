#!/usr/bin/python3
"""
Island Perimeter Algo
O(n) time O(1) space
"""


def island_perimeter(grid):
    """
    calculate the island permeter
    0 represents water
    1 represents land
    Each cell is square, with a side length of 1
    Args:
           the grid describing island
    Return:
           the perimeter of the island described in grid
    """
    perim = 0
    for row in range(len(grid)):
        for col in range(len(grid[row])):
            if grid[row][col] == 1:
                perim += 4
                if col and grid[row][col - 1] == 1:
                    perim -= 2
                if row and grid[row - 1][col] == 1:
                    perim -= 2
    return perim
