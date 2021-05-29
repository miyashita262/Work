#include <stdio.h>
#include <math.h>
#define N 4

int main(void) //前期中間練習問題　一問目
{

    double a[N][N + 1] = {{1, 2, -3, 2, 3}, {-3, 4, 1, 2, 9}, {3, 2, -3, 0, -1}, {0, -3, 2, 1, 7}};
    int i = 0;
    int j = 0;
    int k = 0;
    double pivot = 0;
    double aik = 0;

    for (i = 0; i < N; i++)
    {
        pivot = a[i][i];
        for (j = i; j < N + 1; j++)
            a[i][j] = a[i][j] / pivot;
        for (k = 0; k < N; k++)
            if ((k - i) != 0)
            {
                aik = a[k][i];
                for (j = i; j < N + 1; j++)
                    a[k][j] = a[k][j] - aik * a[i][j];
            }
    }
    for (i = 0; i < N; i++)
    {
        printf("x%d=%lf\n", i + 1, a[i][N]);
    }
    return 0;
}
