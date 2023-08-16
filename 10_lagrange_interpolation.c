/*
    Lagrange interpolation Method.
*/

#include <stdio.h>
#define N 15

int main()
{
    float x[N], y[N], X, res = 0, num, den;
    int i, j, n;

    printf("\nLarange Interpolation Method\n");
    printf("============================\n");

    printf("\nEnter the number of terms (up to %d) : ", N);
    if (scanf("%d", &n) != 1 || n <= 0 || n > N)
    {
        printf("Invalid number of terms. Please enter a positive integer up to %d.\n", N);
        return 1;
    }

    for (i = 0; i < n; i++)
    {
        printf("Enter term %d x and y value : ", i);
        if (scanf("%f %f", &x[i], &y[i]) != 2)
        {
            printf("Invalid input. Please enter valid x and y values.\n");
            return 1;
        }
    }

    printf("Enter the value of x for which f(x) is to be calculated : ");
    if (scanf("%f", &X) != 1)
    {
        printf("Invalid input. Please enter a valid value for x.\n");
        return 1;
    }

    for (i = 0; i < n; i++)
    {
        num = 1;
        den = 1;

        for (j = 0; j < n; j++)
        {
            if (i != j)
            {
                num *= X - x[j];
                den *= x[i] - x[j];
            }
        }

        // Check for division by zero to prevent errors
        if (den != 0)
            res += (num / den) * y[i];
        else
        {
            printf("\n");
            printf("Error: Division by zero occurred. The interpolation cannot be performed.\n\n");
            return 1;
        }
    }

    printf("\nValue of f(%2f) : %3f\n\n", X, res);
    return 0;
}
