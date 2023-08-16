/*
    Simpson's 3/8 Rule.
*/

#include <stdio.h>
#include <math.h>

float f(float x)
{
    // Avoid division by zero when x is zero.
    return (x != 0) ? (1 / x) : 0;
}

int main()
{
    float a, b, h, s = 0, s1;
    int n;

    printf("\nSimpson's 3/8 Rule\n");
    printf("==================\n\n");

    // Input validation for number of intervals (n)
    do
    {
        printf("Enter number of intervals (must be a positive multiple of 3) : ");
        scanf("%d", &n);
    } while (n <= 0 || n % 3 != 0);

    printf("Enter lower limit : ");
    scanf("%f", &a);

    printf("Enter upper limit : ");
    scanf("%f", &b);

    h = (b - a) / n;
    s = f(a) + f(b);

    printf("\n%5s %10s\n", "x", "\t  f(x)");
    printf("------------------------\n");
    printf("%8f\t%8f\n", a, f(a));

    int i;
    for (i = 1; i < n; i++)
    {
        float x = a + i * h;
        s += (i % 3 == 0) ? 2 * f(x) : 3 * f(x);
        printf("%8f\t%8f\n", x, f(x));
    }

    printf("%8f\t%8f\n", b, f(b));

    s1 = ((3 * h) / 8) * s;

    printf("\nResult: %f\n\n", s1);

    return 0;
}
