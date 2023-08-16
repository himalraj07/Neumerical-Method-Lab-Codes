/*
    Jacobi Method
*/

#include <stdio.h>
#include <math.h>

float fx(float y, float z);
float fy(float x, float z);
float fz(float x, float y);

int main()
{
    float x, y, z, xn, yn, zn;
    int n, i;

    printf("\nJacobi Method\n");
    printf("=============\n");

    printf("\nEnter initial values of x, y, and z : ");
    scanf("%f %f %f", &x, &y, &z);

    printf("Enter number of iterations : ");
    scanf("%d", &n);
    printf("\n");

    if (n <= 0)
    {
        printf("Number of iterations should be a positive integer.\n\n");
        return 1;
    }

    for (i = 1; i <= n; i++)
    {
        xn = fx(y, z);
        yn = fy(x, z);
        zn = fz(x, y);
        
        // Here, we use the updated values in the next iteration
        x = xn;
        y = yn;
        z = zn;
        
        // Print intermediate results (optional)
        printf("Iteration %d : x = %f, y = %f, z = %f\n", i, x, y, z);
    }

    printf("\nFinal result : x = %f, y = %f, z = %f\n\n", x, y, z);
    return 0;
}

float fx(float y, float z)
{
    return ((17 - y + 2 * z) / 20);
}

float fy(float x, float z)
{
    return ((-18 - 3 * x + 2 * z) / 20);
}

float fz(float x, float y)
{
    return ((25 - 2 * x + 3 * y) / 20);
}
