#include <stdio.h>
#include <math.h>
int main()
{
	float v1, v2;
	float t1, t2;
	
	float v;
	float t;
	
	scanf("%f %f %f %f", &v1, &t1, &v2, &t2);
	
	v = v1 + v2;
	
	t = ((v1 * t1) + (v2 * t2)) / (v1 + v2);
	
	printf("%.5f %.5f", v, t);
	return 0;
}