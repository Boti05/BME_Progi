#include <math.h>
#include <float.h>
#include <stdio.h>

int main()
{
    double x_null, num;
    int i = 0;

    scanf("%lf%lf", &num, &x_null);
    if (x_null <= 0)
    {
        return 0;
    }
    else
    {
        printf("%d %.16E\n",i, x_null);
        i++;

        while ((fabs((x_null * x_null) - num) / num) > 10 * DBL_EPSILON)
        {
            x_null = (x_null / 2) + (num / (2 * x_null));
            printf("%d %.16E\n",i, x_null);
            i++;
        }
    }
    return 0;
}