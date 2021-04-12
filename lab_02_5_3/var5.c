#include <stdio.h>
#include <math.h>

float sum_range(float x, float eps)
{
    float s = 0;

    float a = 1;

    int i = 1;

    while (fabs(a) > eps)
    {
        s += a;
        a *= (pow(x, 2) * i) / (i + 1);
        i++;
        i++;
    }
    return s;
}

float function_value(float x)
{
    float f;
    f = 1 / (sqrt(1 - x * x));
    return f;
}

float absolute_error(float f, float s)
{
    float diff;

    diff = fabs(f - s);
    return diff;
}

float relative_error(float f, float s)
{
    float div;

    div = fabs((f - s) / f);

    return div;
}
int main()
{
    float eps;

    float x;

    float s;

    float f;

    int rc;

    rc = scanf("%f %f", &x, &eps);

    if (rc == 2 && fabs(x) < 1 && x != eps && eps > 0 && eps < 1)
    {
        s = sum_range(x, eps);

        f = function_value(x);

        printf("%.6f %.6f %.6f %.6f", s, f, absolute_error(f, s), \
            relative_error(f, s));
		return 0;
    }
    else
    {
        printf("Input error");
		return 1;
    }
    return 0;
}
