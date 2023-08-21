/*
    Horner's Method
*/

#include <stdio.h>

int main()
{
    printf("\nHorner's Method\n");
    printf("===============\n\n");

    float coefficients[100], result = 0, x;
    int degree, i;

    printf("Enter the degree of the polynomial : ");
    scanf("%d", &degree);

    printf("\nEnter the coefficients of the polynomial\n");
    printf("----------------------------------------\n\n");
    for (i = degree; i >= 0; i--)
    {
        printf("Coefficient of x^%d : ", i);
        scanf("%f", &coefficients[i]);
    }

    printf("\nEnter the value of x : ");
    scanf("%f", &x);

    // Evaluate the polynomial using Horner's method
    for (i = degree; i > 0; i--)
    {
        result = (result + coefficients[i]) * x; // Move the multiplication inside the loop
    }
    result = result + coefficients[0];

    printf("\nValue of the polynomial at x = %f is [ %f ].\n\n", x, result);

    return 0;
}
