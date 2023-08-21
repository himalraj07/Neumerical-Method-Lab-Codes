/*
    Runge Kutta Method
*/

#include <stdio.h>
#include <math.h>

// Function to calculate the derivative dy/dx
float f(float x, float y)
{
    return (x - y) / (x + y);
}

int main()
{
    float x0, y0, xn, h;

    // Input section
    printf("Enter initial values:\n");
    printf("x0: ");
    scanf("%f", &x0);
    printf("y0: ");
    scanf("%f", &y0);
    printf("Enter the final value of x (xn): ");
    scanf("%f", &xn);
    printf("Enter the step size (h): ");
    scanf("%f", &h);

    // Initialization
    float x = x0;
    float y = y0;

    printf("\nStep\t|\tx\t|\ty\n");
    printf("----------------------------------------\n");

    // Runge-Kutta method
    int step = 0;
    while (x < xn)
    {
        float k1 = h * f(x, y);
        float k2 = h * f(x + h / 2, y + k1 / 2);
        float k3 = h * f(x + h / 2, y + k2 / 2);
        float k4 = h * f(x + h, y + k3);

        // Update y using weighted average of slopes
        y = y + (k1 + 2 * k2 + 2 * k3 + k4) / 6;
        x = x + h;

        printf("%d\t|\t%.2f\t|\t%.6f\n", step, x, y);
        step++;
    }

    return 0;
}
