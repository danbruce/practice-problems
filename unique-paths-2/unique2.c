int uniquePathsWithObstacles(int **obstacleGrid, int obstacleGridRowSize, int obstacleGridColSize)
{
    if (obstacleGridRowSize <= 0 || obstacleGridColSize <= 0)
    {
        return 0;
    }

    int grid[obstacleGridRowSize][obstacleGridColSize];
    unsigned short i, j;
    for (i = 0; i < obstacleGridRowSize; i++)
    {
        for (j = 0; j < obstacleGridColSize; j++)
        {
            if (obstacleGrid[i][j])
            {
                // if this is an obstructed cell, we cannot reach this cell
                grid[i][j] = 0;
            }
            else if (i == 0)
            {
                // first row
                grid[0][j] = (j == 0) ? 1 : grid[0][j - 1];
            }
            else if (j == 0)
            {
                // first column
                grid[i][0] = grid[i - 1][0];
            }
            else
            {
                // otherwise we can reach this cell by the sum of ways we can
                // reach the two adjacent cells (above and to our left)
                grid[i][j] = grid[i - 1][j] + grid[i][j - 1];
            }
        }
    }
    return grid[obstacleGridRowSize - 1][obstacleGridColSize - 1];
}