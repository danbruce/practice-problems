#include <stdio.h>
#include <stdlib.h>
#include <gmp.h>
#include <math.h>

void uniquePaths(unsigned int m, unsigned int n)
{
    if (m <= 0 || n <= 0)
    {
        // base case for m/n as zero
        puts("0");
        return;
    }
    else if (m == 1 || n == 1)
    {
        // base case for m/n as one
        puts("1");
        return;
    }

    int minInt = m <= n ? m : n;
    int maxInt = m >= n ? m : n;
    mpz_t grid[2][minInt];
    unsigned short i, j;
    unsigned long one = 1;
    for (j = 0; j < minInt; j++)
    {
        // initialize the first row to 1
        mpz_init_set_ui(grid[0][j], one);
        // initialize the second row
        mpz_init(grid[1][j]);
    }
    // set the left-most column on the second row to 1
    mpz_set_ui(grid[1][0], one);

    for (i = 1; i < maxInt; i++)
    {
        for (j = 1; j < minInt; j++)
        {
            // for each element, add the adjacent left and above/below elements
            mpz_add(grid[i % 2][j], grid[(i - 1) % 2][j], grid[i % 2][j - 1]);
        }
    }
    char *result = mpz_get_str(NULL, 10, grid[(maxInt - 1) % 2][minInt - 1]);
    puts(result);
    free(result);
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
    uniquePaths(m, n);
    return 0;
}
