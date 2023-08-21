/*
    Gaussian Integration (2 point formula)
*/

#include <stdio.h>
#include <math.h>

float f(float x)
{
    return exp(x);
}

float g(float a, float b, float z)
{
    float x = (b - a) / 2 * z + (b + a) / 2;
    return exp(x);
}

float gaussianIntegration(float a, float b, int n)
{
    float I = 0;

    if (a == -1 && b == 1)
    {
        if (n == 2)
        {
            I = 1 * f(-1 / sqrt(3)) + 1 * f(1 / sqrt(3));
        }
        else if (n == 3)
        {
            I = 5.0 / 9.0 * f(-sqrt(3.0 / 5.0)) + 8.0 / 9.0 * f(0) + 5.0 / 9.0 * f(sqrt(3.0 / 5.0));
        }
        else if (n == 4)
        {
            I = 0.34785 * f(-0.86114) + 0.65215 * f(-0.33998) + 0.65215 * f(0.33998) + 0.34785 * f(0.86114);
        }
    }
    else
    {
        if (n == 2)
        {
            I = (b - a) / 2 * (1 * g(a, b, -1 / sqrt(3)) + 1 * g(a, b, 1 / sqrt(3)));
        }
        else if (n == 3)
        {
            I = (b - a) / 2 * (5.0 / 9.0 * g(a, b, -sqrt(3.0 / 5.0)) + 8.0 / 9.0 * g(a, b, 0) + 5.0 / 9.0 * g(a, b, sqrt(3.0 / 5.0)));
        }
        else if (n == 4)
        {
            I = (b - a) / 2 * (0.34785 * g(a, b, -0.86114) + 0.65215 * g(a, b, -0.33998) + 0.65215 * g(a, b, 0.33998) + 0.34785 * g(a, b, 0.86114));
        }
    }

    return I;
}

int main()
{
    float a, b;
    int n;

    printf("Enter the range [a, b]: ");
    scanf("%f %f", &a, &b);

    printf("Select the number of points (2, 3, or 4): ");
    scanf("%d", &n);

    if (n < 2 || n > 4)
    {
        printf("Invalid choice. Please select 2, 3, or 4.\n");
        return 1;
    }

    float result = gaussianIntegration(a, b, n);
    printf("Integration result: %f\n", result);

    return 0;
}
