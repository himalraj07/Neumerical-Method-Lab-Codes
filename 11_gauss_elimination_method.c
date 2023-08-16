/*
    Gauss elimination Method.
*/

#include <stdio.h>
#include <math.h>
#define SIZE 10

int main()
{
    float a[SIZE][SIZE + 1], x[SIZE], ratio;
    int i, j, k, n;

    printf("\nGauss Elimination Method\n");
    printf("========================\n");

    printf("\nEnter the number of unknowns (maximum 10) : ");
    scanf("%d", &n);

    // Input the augmented matrix
    printf("\nEnter the augmented matrix (coefficients and constants) :\n");
    for (i = 1; i <= n; i++)
    {
        for (j = 1; j <= n + 1; j++)
        {
            printf("a[%d][%d]: ", i, j);
            scanf("%f", &a[i][j]);
        }
    }

    // Gaussian Elimination
    for (i = 1; i <= n - 1; i++)
    {
        for (j = i + 1; j <= n; j++)
        {
            ratio = a[j][i] / a[i][i];
            for (k = i; k <= n + 1; k++)
            {
                a[j][k] -= ratio * a[i][k];
            }
        }
    }

    // Back substitution
    x[n] = a[n][n + 1] / a[n][n];
    for (i = n - 1; i >= 1; i--)
    {
        x[i] = a[i][n + 1];
        for (j = i + 1; j <= n; j++)
        {
            x[i] -= a[i][j] * x[j];
        }
        x[i] /= a[i][i];
    }

    // Print the solution
    printf("\nSolution :\n\n");
    for (i = 1; i <= n; i++)
    {
        printf("x[%d] = %0.3f\n", i, x[i]);
    }
    printf("\n");

    return 0;
}
