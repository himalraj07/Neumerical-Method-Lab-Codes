/*
    Newton's backward interpolation Method.
*/

#include <stdio.h>
#define MAX_TERMS 10  // Limit the number of terms for better performance
#define FACT_LIMIT 12 // Limit factorial calculation to avoid overflow

int fact(int n)
{
    if (n == 0 || n == 1)
        return 1;
    else
        return n * fact(n - 1);
}

int main()
{
    float x[MAX_TERMS], y[MAX_TERMS][MAX_TERMS], X, result = 0, p, h, v;
    int n, i, j;

    printf("\nNewton's Backward Interpolation Method\n");
    printf("======================================\n");

    // Input the number of terms
    printf("\nEnter the number of terms (maximum %d) : ", MAX_TERMS);
    if (scanf("%d", &n) != 1 || n <= 0 || n > MAX_TERMS)
    {
        printf("Invalid input or number of terms exceeds the limit.\n\n");
        return 1;
    }

    // Input the data points
    for (i = 0; i < n; i++)
    {
        printf("Enter term %d x and y value : ", i);
        if (scanf("%f%f", &x[i], &y[i][0]) != 2)
        {
            printf("Invalid input for x and y values.\n\n");
            return 1;
        }
    }

    // Input the value of x for which f(x) is to be calculated
    printf("\nEnter the value of x for which f(x) is to be calculated : ");
    if (scanf("%f", &X) != 1)
    {
        printf("Invalid input for x value.\n\n");
        return 1;
    }

    h = x[1] - x[0];
    p = (X - x[0]) / h;

    // Calculate backward difference table
    for (i = 1; i < n; i++)
    {
        for (j = n - 1; j >= i; j--)
            y[j][i] = y[j][i - 1] - y[j - 1][i - 1];
    }

    // Display the backward difference table
    printf("\nBackward Difference Table :\n\n");
    for (i = 0; i < n; i++)
    {
        printf("%f\t", x[i]);
        for (j = 0; j <= i; j++)
            printf("%f\t", y[i][j]);
        printf("\n");
    }

    // Calculate the result using Newton's backward interpolation formula
    result = y[n - 1][0];
    for (i = 1; i < n; i++)
    {
        v = p;
        for (j = 1; j <= i; j++)
        {
            v = v * (p + j);
        }

        // Handle division by zero for the factorial calculation
        if (i >= FACT_LIMIT)
        {
            printf("Warning: Factorial calculation limit reached. Truncating the interpolation calculation.\n\n");
            break;
        }

        result = result + (v * y[n - 1][i] / fact(i));
    }

    printf("\nThe value of f(%f) : %f\n\n", X, result);
    return 0;
}
