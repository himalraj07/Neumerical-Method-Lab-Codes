/*
    Picard's Method
*/

#include <stdio.h>
#include <math.h>

// Define a function for Y terms
double getY(int n, double x)
{
    double result = 1.0;
    for (int i = 1; i <= n; i++)
    {
        result += pow(x, i) / i;
    }
    return result;
}

int main()
{
    double start_value, end_value, allowed_error;

    // Limit the number of points to avoid overflow
    const int max_points = 30;

    printf("Enter start value: ");
    scanf("%lf", &start_value);
    printf("Enter end value: ");
    scanf("%lf", &end_value);
    printf("Enter allowed error: ");
    scanf("%lf", &allowed_error);

    // Calculate the number of points needed
    int num_points = (int)((end_value - start_value) / allowed_error) + 1;

    // Limit the number of points to max_points
    if (num_points > max_points)
    {
        num_points = max_points;
        allowed_error = (end_value - start_value) / (max_points - 1);
    }

    // Print the header
    printf("%-10s%-20s%-20s%-20s\n", "X", "Y(1)", "Y(2)", "Y(3)");

    // Print the separator line
    for (int i = 0; i < 70; i++)
    {
        printf("=");
    }
    printf("\n");

    // Print the table content
    for (int i = 0; i < num_points; i++)
    {
        double x = start_value + i * allowed_error;
        printf("%-10.4lf%-20.10lf%-20.10lf%-20.10lf\n", x, getY(1, x), getY(2, x), getY(3, x));
    }

    return 0;
}
