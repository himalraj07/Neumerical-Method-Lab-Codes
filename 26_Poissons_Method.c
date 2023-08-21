/*
    Poisson's Method
*/

#include <stdio.h>
#include <math.h>

#define g(x, y) 2 * (x) * (x) * (y) * (y)

int main()
{
    printf("\nPoisson's Method\n");
    printf("================\n\n");
    int n, i, j, k;
    float sum, error, t[10], a[10][10], b[10], new_x[10], old_x[10], tl, tr, tu, tb, h;

    // User inputs
    printf("Enter Dimension of plate : ");
    scanf("%d", &n);

    printf("Enter Dimension of grid : ");
    scanf("%f", &h);
    printf("\n");

    // Input temperatures individually
    printf("Enter temperature at the left side of the plate : ");
    scanf("%f", &tl);
    printf("Enter temperature at the right side of the plate : ");
    scanf("%f", &tr);
    printf("Enter temperature at the bottom of the plate : ");
    scanf("%f", &tb);
    printf("Enter temperature at the upper side of the plate : ");
    scanf("%f", &tu);

    // Initialize coefficient matrix a and RHS vector b
    for (i = 0; i <= n; i++)
    {
        for (j = 0; j <= n; j++)
        {
            if (i == j)
            {
                a[i][j] = -4;
            }
            else if (j == n - 1)
            {
                a[i][j] = 0;
            }
            else
            {
                a[i][j] = 1;
            }
        }
        b[i] = 0; // Initialize the RHS vector
    }

    // Populate the RHS vector b with source term values
    k = 0;
    for (i = 1; i < n; i++)
    {
        for (j = 1; j < n; j++)
        {
            b[k] = h * h * g(i, j);
            if (i == 1)
            {
                b[k] -= tb;
            }
            if (i == n - 1)
            {
                b[k] -= tu;
            }
            if (j == 1)
            {
                b[k] -= tl;
            }
            if (j == n - 1)
            {
                b[k] -= tr;
            }
            k++;
        }
    }

    // User input for desired accuracy
    printf("\n");
    printf("Enter Accuracy Limit : ");
    scanf("%f", &error);

    // Initialize the solution vector
    for (i = 0; i <= n; i++)
    {
        new_x[i] = 0;
    }

    // Gauss-Seidel iterative method for solving linear system
    while (1)
    {
        for (i = 1; i < n; i++)
        {
            sum = b[i];
            for (j = 0; j <= n; j++)
            {
                if (i != j)
                {
                    sum -= a[i][j] * new_x[j];
                }
            }
            old_x[i] = new_x[i];
            new_x[i] = sum / a[i][i]; // Corrected calculation here
            t[i] = fabs(new_x[i] - old_x[i]) / fabs(new_x[i]);
        }

        // Check for convergence
        int converged = 1;
        for (i = 1; i < n; i++)
        {
            if (t[i] > error)
            {
                converged = 0;
                break;
            }
        }
        if (converged)
        {
            break;
        }
    }

    // Display the solution
    printf("\nSolution\n");
    printf("--------\n\n");
    for (i = 0; i <= n; i++)
    {
        printf("x%d = %6.2f\n", i + 1, new_x[i]);
    }
    printf("\n");

    return 0;
}
