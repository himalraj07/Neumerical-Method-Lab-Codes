/*
    Newton's divided difference method.
*/

#include <stdio.h>

int main()
{
    float x[10], y[10][10], X, temp, sum = 0;
    int i, numDataPoints, j, k = 0;

    printf("\nNewton's Divided Difference Method\n");
    printf("==================================\n");

    printf("\nHow many data points will you enter (maximum 10) : ");
    scanf("%d", &numDataPoints);
    printf("\n");

    if (numDataPoints > 10 || numDataPoints < 2)
    {
        printf("Please enter a valid number of data points (between 2 and 10).\n");
        return 1;
    }

    // Input phase
    for (i = 0; i < numDataPoints; i++)
    {
        printf("Enter the value of x%d : ", i);
        scanf("%f", &x[i]);

        printf("Enter the value of y%d : ", i);
        scanf("%f", &y[i][0]);

        printf("\n");
    }

    // Calculation phase
    for (i = 1; i < numDataPoints; i++)
    {
        k = i;
        for (j = 0; j < numDataPoints - i; j++)
        {
            y[i][j + 1] = (y[i - 1][j + 1] - y[i - 1][j]) / (x[k] - x[j]);
            k++;
        }
    }

    // Print the divided differences table
    printf("\nTable of Divided Differences :\n");
    printf("------------------------------\n");
    printf("   x(i)  |    y(i)   ");
    for (i = 1; i < numDataPoints; i++)
    {
        printf("|    y%d(i)  ", i);
    }
    printf("\n");
    printf("--------------------");
    for (i = 1; i < numDataPoints; i++)
    {
        printf("-------------");
    }
    printf("\n");

    for (i = 0; i < numDataPoints; i++)
    {
        printf("%7.2f  |", x[i]);
        for (j = 0; j < numDataPoints - i; j++)
        {
            printf("  %7.2f  |", y[i][j]);
        }
        printf("\n");
    }

    // Find the value of X for interpolation
    printf("\nEnter the value of X for interpolation : ");
    scanf("%f", &X);

    // Interpolation phase
    for (i = 0; i < numDataPoints; i++)
    {
        temp = y[i][0];
        for (j = 0; j < i; j++)
        {
            temp *= (X - x[j]);
        }
        sum += temp;
    }

    printf("\nf(%f) = %f\n\n", X, sum);

    return 0;
}
