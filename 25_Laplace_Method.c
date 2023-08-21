/*
    Laplace Method
*/

#include <stdio.h>
#include <math.h>

#define SIZE 4

typedef float Matrix[SIZE + 1][SIZE + 1];

// Function to input a row of values
void inputRow(int i, Matrix u)
{
    printf("Enter the values of u[%d, j], j = 1 to %d : ", i, SIZE);
    for (int j = 1; j <= SIZE; j++)
    {
        scanf("%f", &u[i][j]);
    }
}

// Function to input a column of values
void inputColumn(int j, Matrix u)
{
    printf("Enter the values of u[i, %d], i = 2 to %d : ", j, SIZE - 1);
    for (int i = 2; i <= SIZE - 1; i++)
    {
        scanf("%f", &u[i][j]);
    }
}

// Function to output the matrix
void outputMatrix(Matrix u, int wd, int prsn)
{
    for (int i = 1; i <= SIZE; i++)
    {
        for (int j = 1; j <= SIZE; j++)
        {
            printf("%*.*f ", wd, prsn, u[i][j]);
        }
        printf("\n");
    }
    printf("\n");
}

int main()
{
    printf("\nLaplace Method\n");
    printf("==============\n\n");
    Matrix u;
    float allowedError, maxIterations;
    float mer, e, t;
    int itr, i, j;

    // Initialize the matrix with zeros
    for (i = 1; i <= SIZE; i++)
    {
        for (j = 1; j <= SIZE; j++)
        {
            u[i][j] = 0;
        }
    }

    printf("Enter the boundary conditions\n");
    printf("-----------------------------\n\n");

    inputRow(1, u);
    inputRow(SIZE, u);
    inputColumn(1, u);
    inputColumn(SIZE, u);

    printf("\nEnter the allowed error : ");
    scanf("%f", &allowedError);

    printf("Enter the maximum number of iterations : ");
    scanf("%f", &maxIterations);
    // printf("\n");

    for (itr = 1; itr <= maxIterations; itr++)
    {
        mer = 0;
        for (i = 2; i <= SIZE - 1; i++)
        {
            for (j = 2; j <= SIZE - 1; j++)
            {
                t = (u[i - 1][j] + u[i + 1][j] + u[i][j + 1] + u[i][j - 1]) / 4.0;
                e = fabs(u[i][j] - t);
                if (e > mer)
                {
                    mer = e;
                }
                u[i][j] = t;
            }
        }

        printf("\nIteration number %d\n", itr);
        outputMatrix(u, 9, 2);

        if (mer <= allowedError)
        {
            printf("\nSolution after %d iterations :\n", itr);
            outputMatrix(u, 8, 1);
            return 0;
        }
    }
    printf("\nSorry! The number of iterations is not sufficient.\n\n");
    return 1;
}
