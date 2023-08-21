/*
    Secant Method
*/

#include <stdio.h>
#include <math.h>
#include <stdlib.h>

// Define the function
#define f(x) (x) * (x) * (x)-2 * (x)-5

int main()
{
    printf("\n");
    printf("Secant Method\n");
    printf("=============\n\n");

    float x0, x1, x2, f0, f1, f2, tolerance;
    int step = 1, maxIterations;

    // Input initial guesses, tolerance, and maximum iterations
    printf("Enter initial guesses : ");
    scanf("%f %f", &x0, &x1);

    printf("Enter tolerable error : ");
    scanf("%f", &tolerance);

    printf("Enter maximum iterations : ");
    scanf("%d", &maxIterations);
    printf("\n");

    printf("Step\t  x0\t\t  x1\t\t  x2\t\t  f(x2)\n");

    do
    {
        // Calculate function values at x0 and x1
        f0 = f(x0);
        f1 = f(x1);

        // Check for mathematical error
        if (f0 == f1)
        {
            printf("Mathematical Error.\n");
            exit(0);
        }

        // Calculate the new approximation using the Secant formula
        x2 = x1 - (x1 - x0) * f1 / (f1 - f0);
        f2 = f(x2);

        // Print step details
        printf("%d\t%10.6f\t%10.6f\t%10.6f\t%10.6f\n", step, x0, x1, x2, f2);

        // Update variables for the next iteration
        x0 = x1;
        f0 = f1;
        x1 = x2;
        f1 = f2;

        step++;

        // Check for convergence
        if (step > maxIterations)
        {
            printf("Not Convergent.\n");
            exit(0);
        }
    } while (fabs(f2) > tolerance);

    printf("\n");
    printf("The Root is : %f\n", x2);
    printf("\n");

    return 0;
}
