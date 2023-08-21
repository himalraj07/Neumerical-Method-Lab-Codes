/*
    Simpson's 1/3 Rule.
*/

#include <stdio.h>
#include <math.h>

float f(float x)
{
    return 1 / x; // It's better to use 1.0 / x to ensure floating-point division.
}

int main()
{
    float a, b, h, s = 0, s1;
    int n, i;

    printf("\nSimpson's 1/3 Rule for Numerical Integration\n");
    printf("============================================\n\n");

    printf("Enter the number of intervals (even) : ");
    scanf("%d", &n);

    printf("Enter the lower limit : ");
    scanf("%f", &a);

    printf("Enter the upper limit : ");
    scanf("%f", &b);

    if (n % 2 != 0)
    {
        printf("Error: Number of intervals must be even.\n\n");
        return 1; // Returning a non-zero value to indicate an error in the program.
    }

    h = (b - a) / n;
    s = f(a) + f(b);

    printf("\n%3f\t%3f", a, f(a));

    for (i = 1; i < n; i++)
    {
        if (i % 2 == 0)
        {
            s = s + 2 * f(a + i * h);
        }
        else
        {
            s = s + 4 * f(a + i * h);
        }
        printf("\n%3f\t%3f", a + i * h, f(a + i * h));
    }

    printf("\n%3f\t%3f", b, f(b));

    s1 = (h / 3) * s;

    printf("\n\nResult : %f\n\n", s1);

    return 0; // Indicating successful program execution.
}
