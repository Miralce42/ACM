//p58
#include<stdio.h>
#include<string.h>

#define maxm 50
#define maxn 1000

void count(int m,int n);
int findMax(int m,int n);

char DNA[maxm][maxn];
char ans[maxn];
int num[maxn][4];
const char ACGT[4] = {'A','C','G','T'};

int main()
{
	int m,n,sum=0;
	scanf("%d %d",&m,&n);
	for(int i = 0 ; i < m ; i++)
	{
		scanf("%s",DNA[i]);
	}
	memset(num,0,sizeof(num));
	count(m,n);
	sum = findMax(m,n);
	printf("%d %s\n",sum,ans);
	return 0;
}

void count(int m,int n)
{
	for(int i = 0 ; i < n ;i++)
	{
		for(int j = 0 ; j < m ;j++)
		{
			switch(DNA[j][i])
			{
			case 'A': num[i][0]++;break;
			case 'C': num[i][1]++;break;
			case 'G': num[i][2]++;break;
			case 'T': num[i][3]++;break;
			}
		}
	}
}

int findMax(int m,int n)
{
	int sum = 0;
	for(int i = 0 ; i < n;i++)
	{
		int max=0;
		for(int j = 3 ; j >= 0 ;j++)
		{
			if(num[i][j] >= max)
			{
				max = num[i][j];
				ans[i] = ACGT[j];
			}
		}
		sum += m - max;
	}
	return sum;
}

