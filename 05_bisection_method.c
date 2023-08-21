/*
    Bisection Method.
*/

#include <stdio.h>
#include <math.h>

// Define the function whose root we want to find
float f(float x)
{
    return (pow(x, 3) - 9 * pow(x, 2) - 10);
}

int main()
{
    int i = 0;
    float x1, x2, x3;

    printf("\nBisection Method\n");
    printf("================\n\n");

    printf("Enter two initial approximations (x1 and x2) : ");

    // Ensure valid input
    if (scanf("%f%f", &x1, &x2) != 2)
    {
        printf("Invalid input. Please enter two numerical values.\n\n");
        return 1; // Indicate error
    }

    // Check if the initial approximations bracket a root
    if (f(x1) * f(x2) > 0)
    {
        printf("\nNo solution exists within the given interval. The function values have the same sign at both points.\n\n");
    }
    else
    {
        printf("\nIteration\t  x1\t\t  f(x1)\t\t  x2\t\t f(x2)\t\t  x3\t\t f(x3)\n");

        do
        {
            i++;
            x3 = (x1 + x2) / 2;
            printf("%0d\t\t%0f\t%0f\t%0f\t%0f\t%0f\t%0f\n", i, x1, f(x1), x2, f(x2), x3, f(x3));
            if (f(x3) * f(x1) > 0)
            {
                x1 = x3;
            }
            else
            {
                x2 = x3;
            }
        } while (fabs(f(x3)) > 0.001);

        printf("\nApproximate root : %f\n\n", x3);
    }

    return 0; // Indicate successful execution
}
