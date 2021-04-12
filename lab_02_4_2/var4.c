#include <stdio.h>

void point(float x1, float y1, float x2, float y2, float x, float y)
{
    if (((x2 - x1) * (y2 - y) - (y2 - y1) * (x2 - x)) == 0 && \
		((x - x1) * (x - x2) + (y - y1) * (y - y2) <= 0))
    {
        printf("1");
    }
    else
        printf("0");
}

int main()
{
    float x1, x2, x;

    float y1, y2, y;

    int rc;

    rc = scanf("%f %f %f %f %f %f", &x1, &y1, &x2, &y2, &x, &y);

    if (rc == 6 && (x1 != x2 || y1 != y2))
    {
        point(x1, y1, x2, y2, x, y);
		return 0;
    }
    else
    {
        printf("Input error");
		return 1;
    }
    return 0;
}
