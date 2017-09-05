#include<stdio.h>

int main()
{
	float f,c;
	scanf("%f",&f);
	c = 5*(f-32)/9.0;
	printf("%.3f\n",c);
	return 0;
}