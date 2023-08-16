/*
    Fixed point iteration Method.
*/

#include <stdio.h>
#include <math.h>

float f(float x)
{
    return (pow(x, 3) - 9 * pow(x, 2) - 10);
}

float g(float x)
{
    // Updated the calculation to use floating-point division
    float r = 9 * x * x + 10;
    float s = 1.0 / 3.0;
    return pow(r, s);
}

int main()
{
    int i = 0;
    float x0, x1;

    printf("\nFixed Point Iteration Method\n");
    printf("============================\n\n");

    printf("Enter initial approximation : ");
    scanf("%f", &x0);

    printf("\nIteration\t   x0\t\t\t   x1");

    do
    {
        i++;
        x1 = g(x0);
        printf("\n  %d\t\t%f\t\t%f", i, x0, x1);
        x0 = x1;
    } while (fabs(f(x1)) > 0.001);

    printf("\n\nRoot of the equation is : %f\n\n", x1);

    return 0;
}
