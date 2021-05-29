#include <stdio.h>
#include <math.h>
#define eps 0.000001

double func(double x) //前期中間練習問題　3問目
{
    double ans = pow(x, 2) - 2.0;
    return ans;
}

int main(void)
{
    int i = 0;
    double a = 1.4;
    double b = 1.5;
    double fa, fb, fc, c;

    do
    {
        fa = func(a);
        fb = func(b);
        c = (a * fb - b * fa) / (fb - fa);
        fc = func(c);
        if (fc * fb < 0)
        {
            a = c;
            i += 1;
        }
        else
        {
            b = c;
        }
    } while (fabs(fc) > eps);

    printf("%lf\ncount=%d\neps=%f", c, i, eps);

    return 0;
}