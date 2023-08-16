/*
    Gauss Seidel Method.
*/

#include <stdio.h>
#include <math.h>

// Function prototypes
float fx(float y, float z);
float fy(float x, float z);
float fz(float x, float y);

int main()
{
    float x = 0, y = 0, z = 0, xn, yn, zn;
    int i, n;

    printf("\nGauss Seidel Method\n");
    printf("===================\n\n");

    printf("Enter number of iterations : ");
    scanf("%d", &n);

    for (i = 1; i <= n; i++)
    {
        // Gauss Seidel method updates
        xn = fx(y, z);
        yn = fy(x, z);
        zn = fz(x, y);

        // Updating variables with new values
        x = xn;
        y = yn;
        z = zn;
    }

    // Printing the final values of x, y, and z
    printf("\nFinal results after %d iterations:\n", n);
    printf("x = %f\ny = %f\nz = %f\n\n", x, y, z);

    return 0;
}

float fx(float y, float z)
{
    // Solving for x using the given equation
    return ((17 - y + 2 * z) / 20);
}

float fy(float x, float z)
{
    // Solving for y using the given equation
    return ((-18 - 3 * x + 2 * z) / 20);
}

float fz(float x, float y)
{
    // Solving for z using the given equation
    return ((25 - 2 * x + 3 * y) / 20);
}
