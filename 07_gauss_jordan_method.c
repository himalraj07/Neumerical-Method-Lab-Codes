/*
    Gauss-jordan Method.
*/

#include <stdio.h>

int main(void)
{
    float m[3][4];
    int i, j, k;

    printf("\nGauss Jordan Method\n");
    printf("===================\n");

    // Input matrix from the user
    printf("\nEnter the matrix (3x4) : \n");
    for (i = 0; i < 3; i++)
    {
        for (j = 0; j < 4; j++)
        {
            scanf("%f", &m[i][j]);
        }
    }

    // Perform Gauss-Jordan elimination
    for (i = 0; i < 3; i++)
    {
        // Make the diagonal element 1
        float t = m[i][i];
        if (t == 0)
        {
            printf("\nThe matrix is singular. No unique solution exists.\n\n");
            return 1;
        }
        for (j = 0; j < 4; j++)
        {
            m[i][j] /= t;
        }

        // Make the elements of the other rows in the same column zero
        for (j = 0; j < 3; j++)
        {
            if (i != j)
            {
                t = m[j][i];
                for (k = 0; k < 4; k++)
                {
                    m[j][k] -= t * m[i][k];
                }
            }
        }
    }

    // Print the result
    printf("\nMatrix is :\n\n");
    for (i = 0; i < 3; i++)
    {
        for (j = 0; j < 4; j++)
        {
            printf("%f\t", m[i][j]);
        }
        printf("\n");
    }

    printf("\nSolutions are :\n\n");
    for (i = 0; i < 3; i++)
    {
        printf("x%d = %f\n", i + 1, m[i][3]);
    }
    printf("\n");

    return 0;
}
