#include<stdio.h>
#include<string.h>

void judge(int n);

#define maxn 1000

int square1[maxn][maxn];
int square2[maxn][maxn];

int main()
{
	int n=0,s=0,j,k,kase=0;
	char hv;
	while(scanf("%d %d",&n,&s) == 2 && n)
	{
		memset(square1,0,sizeof(square1));
		memset(square2,0,sizeof(square2));
		for(int i = 0 ; i < s ;i++)
		{
			scanf("%c %d %d",&hv,&j,&k);
			if(hv == 'H') square1[j][k] = 1;
			if(hv == 'V') square2[j][k] = 1;
		}
		if(kase) printf("**********************************\n\n");
		printf("Problem #%d\n\n",++kase);
		judge(n);
	}
	return 0;
}

void judge(int n)
{
	int sum =0;
	for(int n1 = 1 ; n1 < n ; n1++)
	{
		for(int i = 1;i < n-n1+1;i++)
		{
			for(int j = 1 ;j < n - n1 +1 ;j++)
			{
				int k,ok=1;
				for(k = j ; k < n1+j;k++)
					if(!square1[i][k]||!square1[i+n1][k]){ok = 0;break;}
				for(k = i ; k < n1+i;k++)
					if(!square2[k][j]||!square2[k][j+n1]){ok = 0;break;}
				if(ok) sum++;
			}
		}
		printf("%d square (s) of size %d\n",n1,sum);
	}
	if(!sum) printf("No completed squares can be found.\n");
	return ;
}