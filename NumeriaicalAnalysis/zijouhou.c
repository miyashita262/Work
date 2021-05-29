#include <stdio.h>
#include <math.h>

int main(void) //前期中間練習問題　5問目
{
    double sx1 = 0;
    double sx2 = 0;
    double sy = 0;
    double sxy = 0;
    int n = 0;
    int i = 0;
    float a = 0;
    float b = 0;
    float x = 0;
    float y = 0;

    printf("How many datas do you input?");
    scanf("%d", &n);
    printf("%d data input please.\n", n);

    for (i = 0; i < n; i++)
    {
        scanf("%f", &x);
        printf("x=%f input.\n", x);
        scanf("%f", &y);
        printf("y=%f input.\n", y);
        sx1 += x;
        sx2 += x * x;
        sy += y;
        sxy += x * y;
    }

    a = ((sy * sx2) - (sx1 * sxy)) / ((n * sx2) - (sx1 * sx1));
    b = ((n * sxy) - (sy * sx1)) / ((n * sx2) - (sx1 * sx1));

    printf("a=%f\n", a);
    printf("b=%f\n", b);

    return 0;
}