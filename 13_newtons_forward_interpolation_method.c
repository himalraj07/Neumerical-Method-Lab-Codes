/*
    Newton's forward interpolation Method.
*/

#include <stdio.h>
#include <stdlib.h>

int fact(int n)
{
    if (n == 0 || n == 1)
    {
        return 1;
    }
    else
    {
        return n * fact(n - 1);
    }
}

int main()
{
    int n;

    printf("\nNewton's Forward Interpolation Method\n");
    printf("====================================\n");

    printf("\nEnter the number of terms (maximum 15) : ");

    if (scanf("%d", &n) != 1 || n < 2 || n > 15)
    {
        printf("Invalid input for the number of terms. Exiting.\n\n");
        return 1;
    }

    float *x = (float *)malloc(n * sizeof(float));
    float **y = (float **)malloc(n * sizeof(float *));

    if (x == NULL || y == NULL)
    {
        printf("Memory allocation failed. Exiting.\n\n");
        return 1;
    }

    for (int i = 0; i < n; i++)
    {
        y[i] = (float *)malloc(n * sizeof(float));
        if (y[i] == NULL)
        {
            printf("Memory allocation failed. Exiting.\n\n");
            return 1;
        }
    }

    printf("\nEnter the x and y values for each term : \n\n");
    for (int i = 0; i < n; i++)
    {
        printf("Term %d: ", i + 1);
        if (scanf("%f%f", &x[i], &y[i][0]) != 2)
        {
            printf("Invalid input for term %d. Exiting.\n\n", i + 1);
            return 1;
        }
    }

    // Calculate the forward difference table
    for (int i = 1; i < n; i++)
    {
        for (int j = 0; j < n - i; j++)
        {
            y[j][i] = y[j + 1][i - 1] - y[j][i - 1];
        }
    }

    // Display the forward difference table
    printf("\nForward Difference Table :\n\n");
    for (int i = 0; i < n; i++)
    {
        printf("%f", x[i]);
        for (int j = 0; j < n - i - 1; j++)
        {
            printf("\t%f", y[i][j]);
        }
        printf("\n");
    }

    // Perform interpolation
    printf("\nEnter the value of x for which f(x) is to be calculated : ");
    float X;
    if (scanf("%f", &X) != 1)
    {
        printf("Invalid input for x. Exiting.\n\n");
        return 1;
    }

    float h = x[1] - x[0];
    float p = (X - x[0]) / h;
    float res = y[0][0];

    for (int i = 1; i < n; i++)
    {
        float v = p;
        for (int j = 1; j <= i; j++)
        {
            v = v * (p - j);
        }
        res = res + (v * y[0][i] / fact(i));
    }

    printf("\nValue of f(%f) : %f\n\n", X, res);

    // Free allocated memory
    free(x);
    for (int i = 0; i < n; i++)
    {
        free(y[i]);
    }
    free(y);

    return 0;
}
