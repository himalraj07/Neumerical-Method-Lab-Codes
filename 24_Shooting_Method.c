/*
    Shooting Method
*/

#include <stdio.h>
#include <math.h>
#include <stdlib.h>

// Define the differential equations
float f1(float x, float y, float z)
{
    return z;
}

float f2(float x, float y, float z)
{
    return x + y;
}

// Implement the shooting method
float shoot(float x0, float y0, float z0, float xn, float h)
{
    float x, y, z, k1, k2, k3, k4, l1, l2, l3, l4, k, l;
    x = x0;
    y = y0;
    z = z0;

    do
    {
        k1 = h * f1(x, y, z);
        l1 = h * f2(x, y, z);
        k2 = h * f1(x + h / 2, y + k1 / 2, z + l1 / 2);
        l2 = h * f2(x + h / 2, y + k1 / 2, z + l1 / 2);
        k3 = h * f1(x + h / 2, y + k2 / 2, z + l2 / 2);
        l3 = h * f2(x + h / 2, y + k2 / 2, z + l2 / 2);
        k4 = h * f1(x + h, y + k3, z + l3);
        l4 = h * f2(x + h, y + k3, z + l3);

        l = 1.0 / 6.0 * (l1 + 2 * l2 + 2 * l3 + l4);
        k = 1.0 / 6.0 * (k1 + 2 * k2 + 2 * k3 + k4);

        y += k;
        x += h;
        z += l;

        // Print intermediate values (if needed)
        // printf("%f %f\n", x, y);
    } while (x < xn);

    return y;
}

int main()
{
    printf("\nShooting Method\n");
    printf("=================\n\n");
    float x0, y0, xn, yn, h, m1, m2, m3, b, b1, b2, b3, e;
    int p = 0;

    // Input: Initial values

    printf("Enter initial values\n");
    printf("--------------------\n\n");

    printf("Enter x0 : ");
    scanf("%f", &x0);

    printf("Enter y0 : ");
    scanf("%f", &y0);

    printf("Enter xn : ");
    scanf("%f", &xn);

    printf("Enter yn : ");
    scanf("%f", &yn);

    printf("Enter h : ");
    scanf("%f", &h);

    // Input: Initial guess M1
    printf("Enter the initial guess M1 : ");
    scanf("%f", &m1);

    b = yn;
    b1 = shoot(x0, y0, m1, xn, h);

    // Tolerance value for convergence check
    float tolerance = 0.00005;

    if (fabs(b1 - b) < tolerance)
    {
        printf("The value of x is: %f\n", xn);
        printf("The value of y is: %f\n", b1);
        return 0;
    }
    else
    {
        // Input: M2
        printf("Enter the value of M2 : ");
        scanf("%f", &m2);
        b2 = shoot(x0, y0, m2, xn, h);

        if (fabs(b2 - b) < tolerance)
        {
            printf("The value of x is : %f\n", xn);
            printf("The value of y is : %f\n", b2);
            return 0;
        }
        else
        {
            // Input: M3
            printf("Enter the value of M3 : ");
            scanf("%f", &m3);
            b3 = shoot(x0, y0, m3, xn, h);

            if (fabs(b3 - b) < tolerance)
            {
                printf("The value of x is : %f\n", xn);
                printf("The value of y is : %f\n", b3);
                return 0;
            }
            else
            {
                // Implement the iteration loop to refine M
                int maxIterations = 1000; // Maximum number of iterations
                for (int iteration = 0; iteration < maxIterations; ++iteration)
                {
                    m1 = m2;
                    m2 = m3;
                    b1 = b2;
                    b2 = b3;

                    m3 = m2 + ((m2 - m1) * (b - b2)) / ((b2 - b1) != 0 ? (b2 - b1) : 1);

                    b3 = shoot(x0, y0, m3, xn, h);

                    if (fabs(b3 - b) < tolerance)
                    {
                        printf("\nThe value of x is : %f\n", xn);
                        printf("The value of y is : %f\n\n", b3);
                        return 0;
                    }
                }

                printf("Solution not found within the iteration limit.\n\n");
                return 1;
            }
        }
    }
}
