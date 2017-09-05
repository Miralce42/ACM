#include<stdio.h>
#include<math.h>

int main()
{
	int n,m,kase=0;
	double s;
	while(1)
	{
		s=0.0;
		scanf("%d %d",&n,&m);
		if(n == 0 && m == 0)
			break;
		if(n < m && m < 1e6)
		{
			while(n <= m)
			{
				s += 1.0/pow(n,2);
				n++;
			}
			printf("case %d: %.5f",++kase,s);
		}

	}
	return 0;
	
}