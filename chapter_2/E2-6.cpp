#define LOCAL
#include<stdio.h>
#define INF 100000000

int main()
{
#ifdef LOCAL
	freopen("E2-6.in","r",stdin);
	freopen("E2-6.out","w",stdout);
#endif
	int x,n,s,kase=0;
	int MAX= -INF;
	int MIN = INF;
	while(scanf("%d",&n) == 1 && n)
	{
		s = 0;
		for(int i = 0; i < n ;i++)
		{
			scanf("%d",&x);
			s += x;
			if(x>MAX) MAX = x;
			if(x<MIN) MIN = x;
		}
		if(kase) 
			printf("\n");
		printf("case %d: %d %d %.3f\n",++kase,MIN,MAX,(double)s/n);
	}
	return 0;
}