/*
    Traperoidal rule.
*/

#include <stdio.h>
#include <math.h>

float f(float x)
{
    return 1.0f / x;
}

void main()
{
    float a, b, h, s = 0, s1;
    int i, n;

    printf("\nTraperoidal rule\n");
    printf("================\n");

    printf("\nEnter number of intervals : ");
    scanf("%d", &n);

    printf("Enter lower limit : ");
    scanf("%f", &a);

    printf("Enter upper limit : ");
    scanf("%f", &b);

    h = (b - a) / n;
    s = f(a) + f(b);

    printf("\n%3f\t%3f", a, f(a));

    for (i = 1; i < n; i++)
    {
        s = s + 2 * f(a + i * h);
        printf("\n%3f\t%3f", a + i * h, f(a + i * h));
    }

    printf("\n%3f\t%3f", b, f(b));

    s1 = (h / 2) * s;

    printf("\n%f", s1);
    
    printf("\n\n");
}