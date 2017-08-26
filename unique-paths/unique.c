#include <stdio.h>
#include <stdlib.h>
#include <gmp.h>

char *uniquePaths(unsigned int m, unsigned int n)
{
    if (m <= 0 || n <= 0)
        return "0";
    else if (m == 1 || n == 1)
        return "1";
    mpz_t grid[2][n];
    unsigned short i, j;
    unsigned long one = 1;
    for (j = 0; j < n; j++)
    {
        // initialize the first row to 1
        mpz_init_set_ui(grid[0][j], one);
        // initialize the second row
        mpz_init(grid[1][j]);
    }
    // set the left-most column on the second row to 1
    mpz_set_ui(grid[1][0], one);

    for (i = 1; i < m; i++)
    {
        for (j = 1; j < n; j++)
        {
            mpz_add(grid[i % 2][j], grid[(i - 1) % 2][j], grid[i % 2][j - 1]);
        }
    }
    char *s = mpz_get_str(NULL, 10, grid[(m - 1) % 2][n - 1]);
    return s;
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
    char *result = uniquePaths(m, n);
    printf("%s\n", result);
    free(result);
    return 0;
}
