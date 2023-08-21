/*
    Euler's Method
*/

#include <stdio.h>

float calculateFunction(float x, float y)
{
    return x + y;
}

int main()
{
    printf("\nEuler's Method\n");
    printf("==============\n\n");

    float initialX, initialY, stepSize, targetX;

    // Input from the user
    printf("Enter initial x : ");
    scanf("%f", &initialX);

    printf("Enter initial y : ");
    scanf("%f", &initialY);

    printf("Enter step size : ");
    scanf("%f", &stepSize);

    printf("Enter target x : ");
    scanf("%f", &targetX);

    float currentX = initialX;
    float currentY = initialY;

    printf("\nEuler's Method Table\n");
    printf("x\t\t  y\n");
    printf("-----------------------\n");

    while (currentX <= targetX)
    {
        printf("%.3f\t\t%.3f\n", currentX, currentY);

        float slope = calculateFunction(currentX, currentY);
        float deltaY = stepSize * slope;

        currentY += deltaY;
        currentX += stepSize;
    }
    printf("\n");
    return 0;
}
