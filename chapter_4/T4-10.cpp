#include<stdio.h>
#include<string.h>
#include<stdlib.h>

int cmp(const void*a,const void*b);
void flood(int num,int v);

#define maxn 1000

int h[maxn];

int main()
{
	int n,m,v,kase=0;
	while(scanf("%d %d",&n,&m) == 2 && n)
	{
		memset(h,0,sizeof(h));
		for(int i = 0 ; i < n*m ; i++)
		{
			scanf("%d",&h[i]);
		}
		qsort(h,n*m,sizeof(int),cmp);//C�����Դ�����������
		scanf("%d",&v);
		v /= 100;//��ȥ������������ֱ�Ӽ���߶�
		printf("Region %d\n",kase);
		flood(n*m,v);
	}
	return 0;
}

int cmp(const void*a,const void*b)//�������Ƚϵĺ�����
{
    return *(int*)a-*(int*)b;
}

void flood(int num,int v)
{
	int flooded=0;
	for(int i = 0 ; i < num ; i ++)
	{
		int d = (h[i+1]-h[i])*(i);
		v -= h[i];
		if(!v)
			break;
		else
			flooded++;
		if(v - d)
			v -= d;
		else
			break;
	}
	printf("Water level is %.2f meters.\n",v);
	printf("%.2f percent of the region is under water.\n",flooded/num);
}
