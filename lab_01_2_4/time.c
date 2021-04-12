#include <stdio.h>
#include <math.h>

int main()
{
	int t;
	
	int h;
	
	int m;
	
	scanf("%d", &t);
	
	h = t / 3600;
	
	m = (t % 3600) / 60;
	
	t = (t % 3600) % 60;
	
	printf("%d %d %d", h, m, t);
	return 0;
}