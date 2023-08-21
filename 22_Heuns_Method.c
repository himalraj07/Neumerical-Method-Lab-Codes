/*
    Heun's Method
*/

#include <stdio.h>

// Define the differential equation's function
#define f(x, y) (2 * (y) / (x))

int main()
{
    float x, y, h, xn;

    printf("Heun's Method for solving ordinary differential equations\n");
    printf("Enter initial value for x and y: ");
    scanf("%f%f", &x, &y);
    printf("Enter step size h and final value of x: ");
    scanf("%f%f", &h, &xn);

    while (x + h <= xn)
    {
        // Heun's method formula
        float k1 = f(x, y);
        float k2 = f(x + h, y + h * k1);
        y = y + (h / 2) * (k1 + k2);
        x = x + h;

        printf("At x = %f, y = %f\n", x, y);
    }

    return 0;
}
