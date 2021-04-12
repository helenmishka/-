#include <stdio.h>
#include <math.h>
int main()
{
	float a, b, c;
	float h;
	float cut;
	float p;
	
	scanf("%f %f %f", &a, &b, &h);
	cut = (a - b) / 2;
	c = sqrt((cut * cut) + (h * h));
	p = b + a + (2 * c);
	printf("%.5f", p);
	return 0;
}