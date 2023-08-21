/*
    Heun's Method
*/

#include <stdio.h>

// Define the differential equation's function
#define f(x, y) (2 * (y) / (x))

int main()
{
    float x, y, h, xn;

    printf("\nHeun's Method for solving ordinary differential equations\n\n");

    printf("Enter initial value for x : ");
    scanf("%f", &x);

    printf("Enter initial value for y : ");
    scanf("%f", &y);

    printf("Enter step size h : ");
    scanf("%f", &h);

    printf("Enter final value of x : ");
    scanf("%f", &xn);
    printf("\n");

    while (x + h <= xn)
    {
        // Heun's method formula
        float k1 = f(x, y);
        float k2 = f(x + h, y + h * k1);
        y = y + (h / 2) * (k1 + k2);
        x = x + h;

        printf("At x = %f, y = %f\n", x, y);
    }
    printf("\n");
    return 0;
}
