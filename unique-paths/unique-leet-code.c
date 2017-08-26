#include <stdio.h>
#include <stdlib.h>

int uniquePaths(int m, int n)
{
    if (m <= 0 || n <= 0)
    {
        return 0;
    }
    else if (m == 1 || n == 1)
    {
        return 1;
    }
    int grid[2][n];
    unsigned short i, j;
    for (j = 0; j < n; j++)
    {
        // initialize the first row to 1
        grid[0][j] = 1;
    }
    // set the left-most column on the second row to 1
    grid[1][0] = 1;

    for (i = 1; i < m; i++)
    {
        for (j = 1; j < n; j++)
        {
            grid[i % 2][j] = grid[(i - 1) % 2][j] + grid[i % 2][j - 1];
        }
    }
    return grid[(m - 1) % 2][n - 1];
}

int main(int argc, char **argv)
{
    if (argc < 3)
    {
        puts("Must provide two integers.");
        return 1;
    }
    unsigned int m, n;
    sscanf(argv[1], "%u", &m);
    sscanf(argv[2], "%u", &n);
    printf("%llu\n", uniquePaths(m, n));
    return 0;
}
