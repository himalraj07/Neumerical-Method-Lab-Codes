/*
    Least Square Linear Fitting
*/

#include <stdio.h>

#define MAX_DATA_POINTS 50

int main()
{
    printf("\nLeast Square Linear Fitting\n");
    printf("===========================\n\n");

    int n, i;
    float x[MAX_DATA_POINTS], y[MAX_DATA_POINTS];
    float sumX = 0, sumX2 = 0, sumY = 0, sumXY = 0;
    float a, b;

    // Get the number of data points from the user
    printf("How many data points ? \n= ");
    scanf("%d", &n);
    printf("\n");

    // Input data points
    printf("Enter Data for required points \n");
    printf("------------------------------ \n");
    for (i = 0; i < n; i++)
    {
        printf("\nData point %d \n", i + 1);
        printf("x[%d] = ", i);
        scanf("%f", &x[i]);
        printf("y[%d] = ", i);
        scanf("%f", &y[i]);
    }

    // Calculate required sums for linear regression
    for (i = 0; i < n; i++)
    {
        sumX += x[i];
        sumX2 += x[i] * x[i];
        sumY += y[i];
        sumXY += x[i] * y[i];
    }

    // Calculate the coefficients of the linear regression equation
    b = (n * sumXY - sumX * sumY) / (n * sumX2 - sumX * sumX);
    a = (sumY - b * sumX) / n;

    // Display results
    printf("\nCalculated values\n");
    printf("-----------------\n");

    printf("a = %.2f\n", a);
    printf("b = %.2f\n\n", b);

    printf("Equation of the best fit line\n");
    printf("-----------------------------\n");

    printf("y = %.2f + %.2fx\n\n", a, b);

    return 0;
}
