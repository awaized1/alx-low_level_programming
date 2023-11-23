#!/usr/bin/python3
"""Code defines an island perimeter by measuring function."""


def island_perimeter(grid):
    """Function returns the perimiter of an island.

    Grid represents water by 0 and land by 1.

    Args:
        grid (list): List of list of integers representing an island.
    Returns:
        The perimeter of the island defined by the grid.
    """
    wid = len(grid[0])
    height = len(grid)
    edge = 0
    size = 0

    for i in range(height):
        for j in range(wid):
            if grid[i][j] == 1:
                size += 1
                if (j > 0 and grid[i][j - 1] == 1):
                    edge += 1
                if (i > 0 and grid[i - 1][j] == 1):
                    edge += 1
    return size * 4 - edge * 2
