#include<stdio.h>

int main()
{
	int a,b,c,kase=0;
	double v;
	while(1)
	{
		scanf("%d %d %d",&a,&b,&c);
		if(a == 0 && b == 0 && c == 0)
			break;
		if(a <= 1e6 && b <= 1e6 && c <=100)
		{
			v = (double)a/b;
			printf("case %d: %.*lf\n",++kase,c,v);
		}
	}
	return 0;
}