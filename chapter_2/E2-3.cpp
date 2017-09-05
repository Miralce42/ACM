#include<stdio.h>

int main()
{
	int i=0;
	float term = 0,sum = 0;
	do
	{
		term = 1.0/(2*i+1);
		if(i % 2 == 0)
			sum += term;
		else
			sum -= term;
		printf("%.6f\n",term);
		i++;
	}while(term >= 1e-4);
	printf("%.6f\n",sum);
	return 0;
}