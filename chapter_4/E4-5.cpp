//P85
#include<stdio.h>
#include<string.h>

bool simulate();

#define maxn 1000

struct command
{
	char c[5];
	int r1,c1,r2,c2;//��������EX���õ��ĸ�����
	int a,x[20];//a�������еĸ�����x[i]�������еĺ�
}cmd[maxn];

int r,c,n,r0,c0;//r,c����Ĵ�С��r0,c0����

int main()
{
	int q,kase = 0;
	while(scanf("%d %d %d",&r,&c,&n)==3 && r!=0)
	{
		for(int i = 0 ; i < n ; i++)//��ȡ����ָ��
		{
			scanf("%s",cmd[i].c);//��ȡ��ָ��ָ������
			if(cmd[i].c[0] == 'E')//
				scanf("%d %d %d %d",&cmd[i].r1,&cmd[i].c1,&cmd[i].r2,&cmd[i].c2);
			else
			{
				scanf("%d",&cmd[i].a);
				for(int j = 0 ; j < cmd[i].a ; j++)
					scanf("%d",&cmd[i].x[j]);
			}
		}

		if(kase > 0) printf("\n");
		printf("Spreadsheet #%d\n",++kase);

		scanf("%d",&q);
		for(int j = 0 ; j < q ;j++)
		{
			scanf("%d %d",&r0,&c0);
			printf("Cell data in (%d,%d)",r0,c0);
			if(!simulate()) printf(" GONE\n");
			else printf(" move to (%d,%d)\n",r0,c0);
		}
	}
	return 0;
}

bool simulate()
{
	for(int i =  0 ; i < n ; i++)
	{
		if(cmd[i].c[0] == 'E')
		{
			if(cmd[i].r1 == r0 && cmd[i].c1 ==c0) 
			{
				r0 = cmd[i].r2;
				c0 = cmd[i].c2;
			}
			else if(cmd[i].r2 == r0 && cmd[i].c2 == c0)
			{
				r0 = cmd[i].r1;
				c0 = cmd[i].c1;
			}
		}
		else
		{
			int dr=0,dc=0;
			for(int j = 0 ; j < cmd[i].a ; j++)
			{
				if(cmd[i].c[0] == 'D')
				{
					if(cmd[i].c[1] == 'R' && r0 == cmd[i].x[j]) return false;//�����������У��У���ɾ��
					if(cmd[i].c[1] == 'C' && c0 == cmd[i].x[j]) return false;
					if(cmd[i].c[1] == 'R' && r0 > cmd[i].x[j]) dr--;
					if(cmd[i].c[1] == 'C' && c0 > cmd[i].x[j]) dc--;
				}
				if(cmd[i].c[0] == 'I') 
				{
					if(cmd[i].c[1] == 'R' && r0 >= cmd[i].x[j]) dr++;
					if(cmd[i].c[1] == 'C' && c0 >= cmd[i].x[j]) dc++;
				}
			}
			r0 += dr;
			c0 += dc;
		}
	}
	return true;
}

