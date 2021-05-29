#include <stdio.h>
#include <math.h>
#define N 5

int main(void) //前期中間練習問題二問目
{
    int i = 0;
    int k = 0;
    int j = 0;
    double eps = 0;
    double a[N][N + 1] = {{4, -1, 0, 0, -1, 3}, {-1, 4, -1, 0, 0, 3}, {0, -1, 4, -1, 0, 7}, {0, 0, -1, 4, -1, 9}, {-1, 0, 0, -1, 4, 8}};
    double x[N] = {}; //バグるかもしれないから値入れる
    double y[N] = {};

    printf("How many eps size? ");
    scanf("%lf", &eps);
    for (i = 0; i < N; i++)
    {
        x[i] = 1.0;
    }
    for (i = 0; i < N; i++)
    {
        y[i] = x[i];
    }

    for (k = 1; k <= 30; k++)
    {
        for (i = 0; i < N; i++)
        {
            double sum = 0;
            for (j = 0; j < N; j++)
            {
                if (i != j)
                    sum += a[i][j] * x[j];
            }
            x[i] = (a[i][N] - sum) / a[i][i];
        }
        double q = 0;
        for (i = 0; i < N; i++)
        {
            q += fabs(x[i] - y[i]);
            y[i] = x[i];
        }

        if (q < eps)
        {
            for (i = 0; i < N; i++)
            {
                printf("x%d=%f\n", i, x[i]);
            }
            break;
        }
    }
    if (k > 30)
    {
        printf("収束せず\n");
    }
    return 0;
}