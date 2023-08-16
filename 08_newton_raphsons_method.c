/*
    Newton Raphson's Method.
*/

#include <stdio.h>
#include <math.h>

// Function prototypes
float f(float x);
float derivative_f(float x);

int main()
{
    float x;
    int i = 0;
    const float tolerance = 0.0001;

    printf("\nNewton-Raphson Method\n");
    printf("=====================\n");

    printf("\nEnter an initial guess for the root : ");
    scanf("%f", &x);
    printf("\n");

    printf("Iteration\tRoot Estimate\t\tFunction Value\t\tDerivative Value\n");
    printf("--------------------------------------------------------------------------------\n");
    
    do
    {
        float f_x = f(x);
        float f_prime_x = derivative_f(x);

        // Check for division by zero (derivative should not be zero)
        if (fabs(f_prime_x) < 1e-6)
        {
            printf("Derivative is too close to zero. Newton-Raphson method cannot continue.\n\n");
            return 1; // Exit with an error code
        }

        float x_new = x - f_x / f_prime_x;
        printf("%d\t\t%.6f\t\t%.6f\t\t%.6f\n", i, x_new, f_x, f_prime_x);

        // Check if the difference between the new estimate and the old one is within the tolerance
        if (fabs(x_new - x) < tolerance)
        {
            printf("\n");
            printf("Converged after %d iterations.\n", i);
            printf("\n");
            printf("Approximate root : %.6f\n", x_new);
            printf("\n");
            return 0; // Exit successfully
        }

        x = x_new;
        i++;
    } while (i <= 100); // Add a maximum iteration limit to prevent infinite loops

    printf("Method did not converge within %d iterations.\n\n", i);
    printf("Best approximate root found : %.6f\n\n", x);

    return 0;
}

// Function definition
float f(float x)
{
    return (x * x * x - 3 * x - 10);
}

// Derivative of the function definition
float derivative_f(float x)
{
    return (3 * x * x - 3);
}
