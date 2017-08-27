int uniquePathsWithObstacles(int **obstacleGrid, int obstacleGridRowSize, int obstacleGridColSize)
{
    if (obstacleGridRowSize <= 0 || obstacleGridColSize <= 0 || obstacleGrid[0][0])
    {
        return 0;
    }

    int grid[obstacleGridRowSize][obstacleGridColSize];
    unsigned short i, j;
    grid[0][0] = 1 - obstacleGrid[0][0];
    // initialize the first column
    for (i = 1; i < obstacleGridRowSize; i++)
    {
        grid[i][0] = obstacleGrid[i][0] ? 0 : grid[i - 1][0];
    }
    // initialize the first row
    for (j = 1; j < obstacleGridColSize; j++)
    {
        grid[0][j] = obstacleGrid[0][j] ? 0 : grid[0][j - 1];
    }

    for (i = 1; i < obstacleGridRowSize; i++)
    {
        for (j = 1; j < obstacleGridColSize; j++)
        {
            if (obstacleGrid[i][j])
            {
                // if this is an obstructed cell, we cannot reach this cell
                grid[i][j] = 0;
                continue;
            }
            grid[i][j] = grid[i - 1][j] + grid[i][j - 1];
        }
    }
    return grid[obstacleGridRowSize - 1][obstacleGridColSize - 1];
}