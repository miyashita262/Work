#include <stdio.h>
#include <math.h>
#define eps 0.00001

double func(double x)
{
    double ans = pow(x, 2) - 2;
    return ans;
}

double dfunc(double x)
{
    double dans = x * 2;
    return dans;
}

int main(void)
{
    double x = 1.4;
    double fx0 = 0;
    double dx0 = 0;
    double x1 = 0;
    double dx = 0;
    double x0 = 1.4;

    do
    {
        fx0 = func(x0); //x→x0  funcとdfuncは同じ値
        dx0 = dfunc(x0);
        x1 = x0 - fx0 / dx0;
        dx = fabs(x1 - x0);
        x0 = x1;
        printf("%.10f\n", x0);
    } while (dx > eps);

    return 0;
}