//ʧ��
#include<stdio.h>
#include<string.h>

void choose();
void queue(int aSub,int bSub);
void initialize();

#define maxn 20

int n,k,m,left,A,B;//leftʣ�µ�����
int people[maxn];

int main()
{
	while(scanf("%d %d %d",&n,&k,&m) == 3 && n != 0)
	{
		left = n;
		A=B=0;
		memset(people,0,sizeof(people));
		initialize();
		choose();
	}
	return 0;
}

void choose()
{
	int aSub=0,bSub=0;
	while(left)
	{
		aSub = k%left-1;//A��ѡ���ڵ�ǰ�����е��±�
		bSub = left - m%left;//B��ѡ���ڵ�ǰ�����е��±�
		printf("aSub = %d,bSub = %d\n",aSub,bSub);//����
		A = people[aSub];
		B = people[bSub];
		if(A == B)
		{
			left--;
			if(left)
				printf("%3d,",A);
			else
				printf("%3d",A);
		}
		else
		{
			left -= 2;
			if(left)
				printf("%3d%3d,",A,B);
			else
				printf("%3d%3d",A,B);
		}
		queue(aSub,bSub);
	}
}

void queue(int aSub,int bSub)
{
	int begin = aSub < bSub ? aSub : bSub;//ȡ���ߵĽ�С�߸���begin
	int next = aSub > bSub ? aSub : bSub;//ȡ���ߵĽϴ��߸���next
	if(next == begin)
	{
		for(int i = begin ; i <= left ;i++)
			people[i] = people[i+1];
	}
	else
	{
		for(int i = begin ; i < next ; i++)
			people[i] = people[i+1];
		for(int j = next ; i <= left ; i++)
			people[i-1] = people[i+1];
	}
	//����
	printf("People: ");
	for(int i = 0 ; i < left ; i++)
	{
		printf("%d ",people[i]);
	}
	printf("\n");
}

void initialize()
{
	for(int i = 0  ; i < n ; i++)
	{
		people[i] = i+1;
	}
}